#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../../Modele/Modele_hpp/Reservation.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>

void testSuppressionReservation() {
    Database db(":memory");
    TrajetControlleur controller(db);
    // Cas nominal : suppression d'une réservation existante
    try {
        Passager p("Durant", "Alice", "alice@email.com", "pwd", "pwd", "Nice", {});
        Reservation r1(1,true, 10, 1);
        Reservation r2(2, true, 15, 1);
        std::vector<Reservation> liste = {r1, r2};
        p.setListeReservation(liste);


        // Suppression de la réservation id 1
        controller.supprimerReservation(1);


        if (p.getListeReservation().size() == 1 && p.getListeReservation()[0].getIdReservation() == 2) {
            std::cout << "Test Suppression Nominale : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression Nominale : Échoué (résultat inattendu)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression Nominale : Échoué (exception)" << std::endl;
    }

    // Cas limite : suppression dans une liste contenant une seule réservation
    try {
        Passager p("Martin", "Bob", "bob@email.com", "pwd", "76789", true, {});
        Reservation r(3,true, 20, 2);
        p.setListeReservation({r});

        controller.supprimerReservation(3);


        if (p.getListeReservation().empty()) {
            std::cout << "Test Suppression Limite : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression Limite : Échoué (liste non vide)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression Limite : Échoué (exception)" << std::endl;
    }

    // Cas erreur : suppression d’un ID qui n'existe pas
    try {
        Passager p("Durand", "Chloe", "chloe@email.com", "pwd", "76800", true, false);
        Reservation r(4,true, 30, 2);
        p.setListeReservation({r});

        controller.supprimerReservation(9999);


        if (p.getListeReservation().size() == 1 && p.getListeReservation()[0].getIdReservation() == 4) {
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
