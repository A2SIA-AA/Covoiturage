#include "ConnexionInterface.hpp"
#include <iostream>


/**
 * @brief Fonction pour tester la méthode seConnecter.
 */
void testSeConnecter() {
    // Instancier l'implémentation concrète
    ConnexionInterface connexion;

    // Test 1 : Utilisateur valide
    bool resultat = connexion.seConnecter("utilisateur@example.com", "motdepassecorrect");
    std::cout << "Test 1 - Utilisateur valide : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 2 : Email incorrect
    resultat = connexion.seConnecter("email_incorrect@example.com", "motdepassecorrect");
    std::cout << "Test 2 - Email incorrect : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 3 : Mot de passe incorrect
    resultat = connexion.seConnecter("utilisateur@example.com", "motdepasseincorrect");
    std::cout << "Test 3 - Mot de passe incorrect : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 4 : Email et mot de passe incorrects
    resultat = connexion.seConnecter("email_incorrect@example.com", "motdepasseincorrect");
    std::cout << "Test 4 - Email et mot de passe incorrects : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 5 : Email vide
    resultat = connexion.seConnecter("", "motdepassecorrect");
    std::cout << "Test 5 - Email vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

    // Test 6 : Mot de passe vide
    resultat = connexion.seConnecter("utilisateur@example.com", "");
    std::cout << "Test 6 - Mot de passe vide : " << (!resultat ? "Réussi" : "Échoué") << std::endl;

}

int main() {
    // Lancer les tests unitaires
    std::cout << "--- Début des tests unitaires pour ConnexionInterface ---" << std::endl;
    testSeConnecter();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}

