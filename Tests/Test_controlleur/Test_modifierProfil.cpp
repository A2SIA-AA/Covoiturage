#include "../../Controlleur/Controlleur_hpp/ModifierProfilControlleur.hpp"
#include <iostream>
#include <iostream>
#include <stdexcept> // Pour std::invalid_argument

// Fonction de test unitaire
void testModifierProfil() {
    ModifierProfilControlleur controleur;

    // Cas nominal : champ "nom"
    try {
        controleur.ModifierProfil("nom", "Alice");
        std::cout << "Test Nom : Réussi" << std::endl;
    } catch (...) {
        std::cout << "Test Nom : Échoué" << std::endl;
    }

    // Cas limite : champ inconnu "adresse"
    try {
        controleur.ModifierProfil("adresse", "Paris");
        std::cout << "Test Champ Invalide : Échoué (aucune exception levée)" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Test Champ Invalide : Réussi (exception attrapée)" << std::endl;
    }

    // Cas limite : champ vide
    try {
        controleur.ModifierProfil("", "Quelque chose");
        std::cout << "Test Champ Vide : Échoué (aucune exception levée)" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Test Champ Vide : Réussi (exception attrapée)" << std::endl;
    }
}

// Main pour exécuter les tests
int main() {
    testModifierProfil();
    return 0;
}
