#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>

void testReservation() {
    TrajetControlleur controleur;

    // Cas nominal : données valides
    try {
        controleur.reservation(
            1,                          // idTrajet
            "Dupont",                   // nom
            "Alice",                    // prenom
            "alice@example.com",        // email
            1234567890,                 // numéro téléphone
            30.0f,                      // prix
            2001,                       // idReservation
            true                        // statut
        );
        std::cout << "Test Réservation Valide : Réussi" << std::endl;
    } catch (...) {
        std::cout << "Test Réservation Valide : Échoué (exception)" << std::endl;
    }

    // Cas aux limites : téléphone invalide
    try {
        controleur.reservation(
            2,
            "Martin",
            "Bob",
            "bob@example.com",
            -12345,                     // Numéro invalide
            20.0f,
            2002,
            false
        );
        std::cout << "Test Téléphone Invalide : Échoué (aucune exception)" << std::endl;
    } catch (...) {
        std::cout << "Test Téléphone Invalide : Réussi (exception attendue)" << std::endl;
    }

    // Cas d’erreur : email vide
    try {
        controleur.reservation(
            3,
            "Durand",
            "Chloe",
            "",                         // email vide
            111222333,
            15.0f,
            2003,
            true
        );
        std::cout << "Test Email Vide : Échoué (aucune exception)" << std::endl;
    } catch (...) {
        std::cout << "Test Email Vide : Réussi (exception attendue)" << std::endl;
    }
}

int main() {
    testReservation();
    return 0;
}
