#include "InscriptionInterface.hpp"
#include <iostream>


/**
 * @brief Fonction pour tester la méthode sInscrire.
 */
void testSInscrire() {
    // Instancier l'implémentation concrète
    InscriptionInterface inscription; 
    
    // Test 1 : Inscription valide
    bool resultat = inscription.sInscrire("Dupont", "Jean", "jean.dupont@example.com", "0601020304", "motdepasse123");
    std::cout << "Test 1 - Inscription valide : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 2 : Email déjà utilisé
    resultat = inscription.sInscrire("Dupont", "Jean", "jean.dupont@example.com", "0601020304", "motdepasse123");
    std::cout << "Test 2 - Email déjà utilisé : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 3 : Email vide
    resultat = inscription.sInscrire("Dupont", "Jean", "", "0601020304", "motdepasse123");
    std::cout << "Test 3 - Email vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 4 : Mot de passe vide
    resultat = inscription.sInscrire("Dupont", "Jean", "jean.dupont@example.com", "0601020304", "");
    std::cout << "Test 4 - Mot de passe vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 5 : Nom vide
    resultat = inscription.sInscrire("", "Jean", "jean.dupont@example.com", "0601020304", "motdepasse123");
    std::cout << "Test 5 - Nom vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 6 : Prénom vide
    resultat = inscription.sInscrire("Dupont", "", "jean.dupont@example.com", "0601020304", "motdepasse123");
    std::cout << "Test 6 - Prénom vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 7 : Numéro de téléphone vide
    resultat = inscription.sInscrire("Dupont", "Jean", "jean.dupont@example.com", "", "motdepasse123");
    std::cout << "Test 7 - Numéro de téléphone vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;
}

int main() {
    // Lancer les tests unitaires
    std::cout << "--- Début des tests unitaires pour InscriptionInterface ---" << std::endl;
    testSInscrire();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}

