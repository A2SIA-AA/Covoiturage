#include "../../Interface/Interface_hpp/AccueilInterface.hpp"
#include <iostream>
#include <cassert>

/**
 * @brief Fonction de test unitaire pour la méthode accueil().
 *
 * Cette fonction vérifie que la méthode accueil() retourne successivement "1", "2", ..., "5".
 * Un message de réussite est affiché pour chaque test.
 */
void testAccueilInterface() {
    // Instancier l'implémentation concrète
    AccueilInterface accueil;

    std::string resultat;

    // Test 1
    resultat = accueil.accueil();
    assert(resultat == "1");
    std::cout << "Test accueil() 1 : Réussi" << std::endl;

    // Test 2
    resultat = accueil.accueil();
    assert(resultat == "2");
    std::cout << "Test accueil() 2 : Réussi" << std::endl;

    // Test 3
    resultat = accueil.accueil();
    assert(resultat == "3");
    std::cout << "Test accueil() 3 : Réussi" << std::endl;

    // Test 4
    resultat = accueil.accueil();
    assert(resultat == "4");
    std::cout << "Test accueil() 4 : Réussi" << std::endl;

    // Test 5
    resultat = accueil.accueil();
    assert(resultat == "5");
    std::cout << "Test accueil() 5 : Réussi" << std::endl;
}

int main() {
    // Lancer les tests unitaires
    std::cout << "--- Début des tests unitaires pour AccueilInterface ---" << std::endl;
    testAccueilInterface();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}

