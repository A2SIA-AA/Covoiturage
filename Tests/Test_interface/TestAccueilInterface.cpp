#include "AccueilInterface.hpp"
#include <iostream>

/**
 * @brief Fonction pour tester la méthode modifierCoordonnees.
 */
void testModifierCoordonnees() {
    // Instancier l'implémentation concrète
    AccueilInterface accueil;

    // Test 1 : Modification valide
    bool resultat = accueil.modifierCoordonnees("Dupont", "Jean", "jean.dupont@example.com", "0601020304");
    std::cout << "Test 1 - Modification valide : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 2 : Email invalide
    resultat = accueil.modifierCoordonnees("Dupont", "Jean", "email_invalide@example", "0601020304");
    std::cout << "Test 2 - Email invalide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 3 : Nom vide
    resultat = accueil.modifierCoordonnees("", "Jean", "jean.dupont@example.com", "0601020304");
    std::cout << "Test 3 - Nom vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 4 : Prénom vide
    resultat = accueil.modifierCoordonnees("Dupont", "", "jean.dupont@example.com", "0601020304");
    std::cout << "Test 4 - Prénom vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 5 : Email vide
    resultat = accueil.modifierCoordonnees("Dupont", "Jean", "", "0601020304");
    std::cout << "Test 5 - Email vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 6 : Téléphone vide
    resultat = accueil.modifierCoordonnees("Dupont", "Jean", "jean.dupont@example.com", "");
    std::cout << "Test 6 - Téléphone vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;
}

int main() {
    // Lancer les tests unitaires
    std::cout << "--- Début des tests unitaires pour AccueilInterface ---" << std::endl;
    testModifierCoordonnees();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}

