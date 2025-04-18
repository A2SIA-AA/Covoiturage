#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../../Modele/Modele_hpp/Reservation.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>

void testSuppressionReservation() {
    // Cas nominal : suppression d'une réservation existante
    try {
        // Initialisation
        Passager p(1, "Alice", "Durant", "alice@email.com", "pwd", "Nice", false);
        Reservation r1(25.0f, 1001, true);
        Reservation r2(30.0f, 1002, true);
        std::vector<Reservation> liste = {r1, r2};
        p.setListeReservation(liste);

        // Création du contrôleur de suppression et appel à la méthode
        TrajetControlleur controller;
        controller.supprimerReservation(1002);  // Suppression de la réservation avec ID 1002

        // Vérification
        if (p.getListeReservation().size() == 1 && p.getListeReservation()[0].getIdReservation() == 1001) {
            std::cout << "Test Suppression Nominale : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression Nominale : Échoué (résultat inattendu)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression Nominale : Échoué (exception)" << std::endl;
    }

    // Cas limite : suppression dans une liste contenant une seule réservation
    try {
        Passager p(2, "Bob", "Martin", "bob@email.com", "pwd", "Lille", true);
        Reservation r(50.0f, 2001, true);
        p.setListeReservation({r});

        // Création du contrôleur de suppression et appel à la méthode
        TrajetControlleur controller;
        controller.supprimerReservation(2001);   // Suppression de la seule réservation

        // Vérification
        if (p.getListeReservation().empty()) {
            std::cout << "Test Suppression Limite : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression Limite : Échoué (liste non vide)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression Limite : Échoué (exception)" << std::endl;
    }

    // Cas erreur : suppression d’un ID inexistant
    try {
        Passager p(3, "Chloe", "Durand", "chloe@email.com", "pwd", "Paris", false);
        Reservation r(35.0f, 3001, true);
        p.setListeReservation({r});

        // Tentative de suppression avec un ID inexistant
        TrajetControlleur controller;
        controller.supprimerReservation(9999);  // ID inexistant

        // Vérification
        if (p.getListeReservation().size() == 1 && p.getListeReservation()[0].getIdReservation() == 3001) {
            std::cout << "Test Suppression ID Inexistant : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression ID Inexistant : Échoué (mauvaise suppression)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression ID Inexistant : Échoué (exception)" << std::endl;
    }
}

int main() {
    testSuppressionReservation();
    return 0;
}
