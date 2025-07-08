#include "Utilisateur.h"
#include <iostream>

Utilisateur::Utilisateur(){
    this->nom = "";
    this->notes_films = {};
}

Utilisateur::Utilisateur(std::string nom): nom(nom){
    this->notes_films = {};
}

void Utilisateur::ajouter_note(std::string film, int note){
    auto it = this->notes_films.find(film);

    if(it != this->notes_films.end()){
        std::cout <<"L'element existe déjà : " <<it->first <<"la note est : " <<it->second <<std::endl;
    }else{
        this->notes_films.insert({film, note});
        std::cout <<"L'element "<<film <<" > " <<note <<"est ajouté" <<std::endl;
    }
}

int Utilisateur::get_note(std::string film) const {
    auto it = this->notes_films.find(film);
    if(it != this->notes_films.end()){
        return it->second;
    }else{
        return 0;
    }
}

bool Utilisateur::a_note_film(std::string film){
    auto it = this->notes_films.find(film);
    if(it != this->notes_films.end()){
        return true;
    }
    return false;
}

std::string Utilisateur::get_nom() const {
    this->nom;
}

