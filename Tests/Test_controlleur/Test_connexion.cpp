#include "Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include <iostream>

// Fonction de test qui affiche un message pour savoir si le test a réussi
void testVerifierUtilisateur() {
    ConnexionControlleur controleur;

    // Test de l'utilisateur valide
    bool resultat = controleur.verifierUtilisateur("utilisateur@example.com", "motdepassecorrect");
    std::cout << "Test Utilisateur Valide : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test de l'email incorrect
    resultat = controleur.verifierUtilisateur("utilisateur_incorrect@example.com", "motdepassecorrect");
    std::cout << "Test Email Incorrect : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test du mot de passe incorrect
    resultat = controleur.verifierUtilisateur("utilisateur@example.com", "motdepasseincorrect");
    std::cout << "Test Mot de Passe Incorrect : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test de l'email et du mot de passe incorrects
    resultat = controleur.verifierUtilisateur("utilisateur_incorrect@example.com", "motdepasseincorrect");
    std::cout << "Test Email et Mot de Passe Incorrects : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test de l'email vide
    resultat = controleur.verifierUtilisateur("", "motdepassecorrect");
    std::cout << "Test Email Vide : " << (resultat ? "Réussi" : "Échoué") << std::endl;

    // Test du mot de passe vide
    resultat = controleur.verifierUtilisateur("utilisateur@example.com", "");
    std::cout << "Test Mot de Passe Vide : " << (resultat ? "Réussi" : "Échoué") << std::endl;
}

int main() {
    // Lancer les tests
    testVerifierUtilisateur();
    return 0;
}
