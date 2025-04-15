#include "../../Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
#include <iostream>

// Fonction de test
void testVerifierSaisie() {
    InscriptionControlleur controleur;

    // Cas nominal : tous les champs sont valides
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durand@mail.com", "motDePasse123", "12 avenue des Champs Elysée");
        std::cout << "Test Saisie Valide : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Saisie Valide : Échoué - " << e.what() << std::endl;
    }

    // Cas d’erreur : nom vide
    try {
        controleur.verifierSaisieInscription("", "Jean", "jean.durand@mail.com", "motDePasse123", "12 avenue des Champs Elysée");
        std::cout << "Test Nom Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Nom Vide : Réussi - " << e.what() << std::endl;
    }

    // Cas limite : email sans '@'
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durandmail.com", "motDePasse123", "12 avenue des Champs Elysée");
        std::cout << "Test Email Incorrect : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Email Incorrect : Réussi - " << e.what() << std::endl;
    }

    // Cas d’erreur : mot de passe vide
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durand@mail.com", "", "12 avenue des Champs Elysée");
        std::cout << "Test Mot de Passe Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Mot de Passe Vide : Réussi - " << e.what() << std::endl;
    }

    // Cas d’erreur : adresse vide
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durand@mail.com", "motDePasse123", "");
        std::cout << "Test Adresse Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Adresse Vide : Réussi - " << e.what() << std::endl;
    }
}

int main() {
    testVerifierSaisie();
    return 0;
}
