#include "Systeme.h"
#include <fstream>
#include <iostream>
#include <sstream>

Systeme::Systeme(){}

bool Systeme::charger_donnees(const std::string& fichier){
    std::ifstream file(fichier);

    if(!file.is_open()){
        std::cerr <<"Erreur d'ouverture du fichier !!!" <<std::endl;
        return false;
    }

    std::string ligne;

    while(getline(file, ligne)){
        std::stringstream ss(ligne);

        std::string nom;
        std::string film;
        std::string note_str;
        int note;

        if(std::getline(ss, nom, ',') && std::getline(ss, film, ',') && std::getline(ss, note_str)){
            note = std::stoi (note_str);

            Utilisateur * user = trouver_utilisateur(nom);
            if(user == nullptr){
                Utilisateur nouvelle_utilisateur(nom);
                ajouter_utilisateur(nouvelle_utilisateur);
                user = trouver_utilisateur(nom);
            }

            user->ajouter_note(film, note);
        }

    }

    return true;
}

void Systeme::ajouter_utilisateur(const Utilisateur& user){
    this->utilisateurs.push_back(user);
}

Utilisateur * Systeme::trouver_utilisateur(const std::string& nom){
    for(auto& user : utilisateurs){
        if(user.get_nom() == nom){
            return &user;
        }
    }
    return nullptr;
}

void Systeme::afficher_utilisateurs() const {
    int nombre = 0;

    for(const auto& user : utilisateurs){
        ++nombre;
        std::cout <<"L'utilisateur [" <<nombre <<"] : " <<user.get_nom() <<std::endl;
    }
}

std::vector<std::string> Systeme::recommander_films_pour(const std::string& nom){
    std::vector<std::string> recommendations;
    
    Utilisateur * user_cible = trouver_utilisateur(nom);
    if(user_cible == nullptr){
        return recommendations;
    }

    double meilleure_similarite = -1.0;
    Utilisateur* utilisateur_similaire = nullptr;
    
    for(auto& autre_user : utilisateurs){
        if(autre_user.get_nom() != nom){
            double similarite = user_cible->calcule_similarite(autre_user);
            if(similarite > meilleure_similarite){
                meilleure_similarite = similarite;
                utilisateur_similaire = &autre_user;
            }
        }
    }
    
    if(utilisateur_similaire != nullptr){
        auto films_similaire = utilisateur_similaire->get_notes_films();
        auto films_cible = user_cible->get_notes_films();
        
        for(const auto& film_note : films_similaire){
            std::string film = film_note.first;
            int note = film_note.second;
            
            if(note >= 4 && films_cible.find(film) == films_cible.end()){
                recommendations.push_back(film);
            }
        }
    }
    
    return recommendations;
}
