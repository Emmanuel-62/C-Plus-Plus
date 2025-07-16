#include "Utilisateur.h"
#include <iostream>
#include <cmath>

Utilisateur::Utilisateur(){
    this->nom = "";
    this->notes_films = {};
}

Utilisateur::Utilisateur(std::string nom): nom(nom){
    this->notes_films = {};
}

void Utilisateur::ajouter_note(std::string& film, int note){
    auto it = this->notes_films.find(film);

    if(it != this->notes_films.end()){
        std::cout <<"L'element existe déjà : " <<it->first <<"la note est : " <<it->second <<std::endl;
    }else{
        this->notes_films.insert({film, note});
        std::cout <<"L'element "<<film <<" > " <<note <<"est ajouté" <<std::endl;
    }
}

int Utilisateur::get_note(std::string& film) const {
    auto it = this->notes_films.find(film);
    if(it != this->notes_films.end()){
        return it->second;
    }else{
        return 0;
    }
}

bool Utilisateur::a_note_film(std::string& film){
    auto it = this->notes_films.find(film);
    if(it != this->notes_films.end()){
        return true;
    }
    return false;
}

std::string Utilisateur::get_nom() const {
    return this->nom;
}

std::map<std::string, int> Utilisateur::get_notes_films () const {
    return this->notes_films;
}

double Utilisateur::calcule_similarite(Utilisateur & autre) const{
    auto mes_notes = this->notes_films;
    auto ses_notes = autre.get_notes_films();

    double produit_salaire = 0.0;
    double norme_moi = 0.0;
    double norme_autre = 0.0;

    for(const auto& film : mes_notes){
        const std::string& nom_film = film.first;
        int ma_note = film.second;
        norme_moi += ma_note * ma_note;

        if(ses_notes.count(nom_film) > 0){
            int sa_note = ses_notes.at(nom_film);
            produit_salaire += ma_note * sa_note;
        }
    }

    for(const auto& film : ses_notes){
        int sa_note = film.second;
        norme_autre += sa_note * sa_note;
    }

    if(norme_moi == 0.0 || norme_autre == 0.0) {
        return 0.0;
    }
    return produit_salaire / (sqrt(norme_moi) * sqrt(norme_autre));
}