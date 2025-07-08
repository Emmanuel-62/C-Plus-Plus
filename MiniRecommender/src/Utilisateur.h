#ifndef __UTILISATEUR__
    #define __UTILISATEUR__

    #include <string>
    #include <map>

    class Utilisateur {
        private : 
            std::string nom;
            std::map <std::string, int> notes_films;

        public :
            Utilisateur();
            Utilisateur(std::string);

            void ajouter_note(std::string, int);
            int get_note(std::string) const;
            bool a_note_film(std::string);
            
            std::string get_nom() const;
            std::map<std::string, int> get_notes_films() const; 

            double calcule_similarite(Utilisateur&) const;

    };

#endif // __UTILISATEUR__