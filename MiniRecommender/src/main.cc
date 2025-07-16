#include "Systeme.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== SYSTÈME DE RECOMMANDATION DE FILMS ===" << std::endl;
    
    Systeme systeme;
    
    std::cout << "\n1. Chargement des données..." << std::endl;
    if (systeme.charger_donnees("Donnees/notes.txt")) {
        std::cout << "✓ Données chargées avec succès!" << std::endl;
    } else {
        std::cout << "✗ Erreur lors du chargement des données!" << std::endl;
        return 1;
    }
    
    std::cout << "\n2. Utilisateurs dans le système:" << std::endl;
    systeme.afficher_utilisateurs();
    
    // Tester les recommandations pour chaque utilisateur
    std::cout << "\n3. Recommandations:" << std::endl;
    
    std::vector<std::string> utilisateurs = {"Alice", "Bob", "Charlie"};
    
    for (const auto& nom : utilisateurs) {
        std::cout << "\n--- Recommandations pour " << nom << " ---" << std::endl;
        
        auto recommendations = systeme.recommander_films_pour(nom);
        
        if (recommendations.empty()) {
            std::cout << "Aucune recommandation disponible pour " << nom << std::endl;
        } else {
            std::cout << "Films recommandés pour " << nom << ":" << std::endl;
            for (size_t i = 0; i < recommendations.size(); ++i) {
                std::cout << "  " << (i + 1) << ". " << recommendations[i] << std::endl;
            }
        }
    }
    
    // Test avec un utilisateur inexistant
    std::cout << "\n4. Test avec utilisateur inexistant:" << std::endl;
    auto reco_inexistant = systeme.recommander_films_pour("David");
    if (reco_inexistant.empty()) {
        std::cout << "✓ Gestion correcte d'un utilisateur inexistant" << std::endl;
    }
    
    // Afficher les notes de chaque utilisateur pour comprendre les recommandations
    std::cout << "\n5. Détails des notes par utilisateur:" << std::endl;
    for (const auto& nom : utilisateurs) {
        std::cout << "\n" << nom << " a noté:" << std::endl;
        Utilisateur* user = systeme.trouver_utilisateur(nom);
        if (user != nullptr) {
            auto notes = user->get_notes_films();
            for (const auto& film_note : notes) {
                std::cout << "  " << film_note.first << " : " << film_note.second << "/5" << std::endl;
            }
        }
    }
    
    return 0;
}