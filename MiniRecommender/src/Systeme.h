#ifndef __SYSTEME__
    #define __SYSTEME__

    #include "Utilisateur.h"
    #include <vector>
    #include <string>

    class Systeme {
        private:
            std::vector<Utilisateur> utilisateurs;

        public:
        Systeme();

        bool charger_donnees(const std::string&);
        void ajouter_utilisateur(const Utilisateur&);
        Utilisateur* trouver_utilisateur(const std::string&);
        std::vector<std::string> recommander_films_pour(const std::string&);
        void afficher_utilisateurs() const;

    };

#endif //__SYSTEME__