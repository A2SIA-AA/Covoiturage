#include "../../Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
#include <iostream>

// Fonction de test
void testVerifierSaisie() {
    Database db(":memory:");
    InscriptionControlleur controleur(db);

    // Cas nominal : tous les champs sont valides
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durand@mail.com", "motDePasse123", "12 avenue des Champs Elysée",false);
        std::cout << "Test Saisie Valide : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Saisie Valide : Échoué - " << e.what() << std::endl;
    }

    // Cas d’erreur : nom vide
    try {
        controleur.verifierSaisieInscription("", "Jean", "jean.durand@mail.com", "motDePasse123", "12 avenue des Champs Elysée",false);
        std::cout << "Test Nom Vide : Réussi " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Nom Vide : Echoué - " << e.what() << std::endl;
    }

    // Cas limite : email sans '@'
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durandmail.com", "motDePasse123", "12 avenue des Champs Elysée",true);
        std::cout << "Test Email Incorrect : Réussi " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Email Incorrect : Echoué - " << e.what() << std::endl;
    }

    // Cas d’erreur : mot de passe vide
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durand@mail.com", "", "12 avenue des Champs Elysée",false);
        std::cout << "Test Mot de Passe Vide : Réussi " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Mot de Passe Vide : Echoué - " << e.what() << std::endl;
    }

    // Cas d’erreur : adresse vide
    try {
        controleur.verifierSaisieInscription("Durand", "Jean", "jean.durand@mail.com", "motDePasse123", "",false);
        std::cout << "Test Adresse Vide : Réussi " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Adresse Vide : Echoué - " << e.what() << std::endl;
    }
}

int main() {
    testVerifierSaisie();
    return 0;
}
