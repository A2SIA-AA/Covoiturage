#include "../../Interface/Interface_hpp/ModifierProfilInterface.hpp"
#include <iostream>

/**
 * @brief Fonction pour tester la méthode seConnecter.
 */

void testModifierCoordonnees() {
    ModifierProfilInterface profil;

    // Test 1 : Tous les champs valides
    bool res = profil.modifierCoordonnees("Durand", "Jean", "jean.durand@mail.com", "0601020304");
    std::cout << "Test 1 - Champs valides : " << (res ? "Réussi" : "Échoué") << std::endl;

    // Test 2 : Email invalide
    res = profil.modifierCoordonnees("Durand", "Jean", "jean.durandmail.com", "0601020304");
    std::cout << "Test 2 - Email invalide : " << (!res ? "Réussi" : "Échoué") << std::endl;

    // Test 3 : Téléphone invalide (lettres)
    res = profil.modifierCoordonnees("Durand", "Jean", "jean.durand@mail.com", "06AB020304");
    std::cout << "Test 3 - Téléphone invalide : " << (!res ? "Réussi" : "Échoué") << std::endl;

    // Test 4 : Nom vide
    res = profil.modifierCoordonnees("", "Jean", "jean.durand@mail.com", "0601020304");
    std::cout << "Test 4 - Nom vide : " << (!res ? "Réussi" : "Échoué") << std::endl;

    // Test 5 : Prénom vide
    res = profil.modifierCoordonnees("Durand", "", "jean.durand@mail.com", "0601020304");
    std::cout << "Test 5 - Prénom vide : " << (!res ? "Réussi" : "Échoué") << std::endl;

    // Test 6 : Email vide
    res = profil.modifierCoordonnees("Durand", "Jean", "", "0601020304");
    std::cout << "Test 6 - Email vide : " << (!res ? "Réussi" : "Échoué") << std::endl;

    // Test 7 : Téléphone vide
    res = profil.modifierCoordonnees("Durand", "Jean", "jean.durand@mail.com", "");
    std::cout << "Test 7 - Téléphone vide : " << (!res ? "Réussi" : "Échoué") << std::endl;
}

int main() {
    std::cout << "--- Début des tests unitaires pour ModifierProfilInterface ---" << std::endl;
    testModifierCoordonnees();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}
