#include "../../Modele/Modele_hpp/Trajet.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>

#include "Modele_hpp/Conducteur.hpp"

void testSuppressionTrajet()
{
    // Cas nominal : suppression d'un trajet existant
    try {
        // Initialisation d'un conducteur (on suppose qu'il existe une liste de trajets pour le conducteur)
        Conducteur c(1, "Alice", "Durant", "alice@email.com", "pwd", "Nice", false);
        Trajet t1(101, "2025-05-01", "10:00", "12:00", "Paris", "Lyon", {{"Segment1", 10.0f}, {"Segment2", 15.0f}}, {"Paris", "Lyon"}, true, true, true, "Voiture", 3, true, 120.0f, "Trajet Paris-Lyon");
        Trajet t2(102, "2025-05-02", "09:00", "11:00", "Lyon", "Marseille", {{"Segment1", 12.0f}, {"Segment2", 18.0f}}, {"Lyon", "Marseille"}, true, false, false, "Voiture", 2, true, 130.0f, "Trajet Lyon-Marseille");
        // On suppose qu'il existe une collection de trajets pour le conducteur
        std::vector<Trajet> trajets = {t1, t2};

        c.setListeTrajet(trajets);

        // Création du contrôleur de suppression et appel à la méthode
        TrajetControlleur controller;
        controller.supprimerTrajet(102);  // Suppression du trajet avec ID 102

        // Vérification
        if (c.getListeTrajet().size() == 1 && c.getListeTrajet()[0].getIdTrajet() == 101) {
            std::cout << "Test Suppression Nominale : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression Nominale : Échoué (résultat inattendu)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression Nominale : Échoué (exception)" << std::endl;
    }

    // Cas limite : suppression dans une liste contenant un seul trajet
    try {
        Conducteur c(1, "Alice", "Durant", "alice@email.com", "pwd", "Nice", false);
        Trajet t(103, "2025-06-01", "08:00", "10:00", "Nice", "Monaco", {{"Segment1", 10.0f}}, {"Nice", "Monaco"}, true, false, true, "Voiture", 1, true, 140.0f, "Trajet Nice-Monaco");

        std::vector<Trajet> trajets = {t};
        c.setListeTrajet(trajets);

        // Création du contrôleur de suppression et appel à la méthode
        TrajetControlleur controller;
        controller.supprimerTrajet(103);   // Suppression du seul trajet

        // Vérification
        if (c.getListeTrajet().empty())
        {
            std::cout << "Test Suppression : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression : Échoué (résultat inattendu)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression : Échoué (exception)" << std::endl;
    }

    // Cas erreur : suppression d’un ID de trajet inexistant
    try {
        Conducteur c(1, "Alice", "Durant", "alice@email.com", "pwd", "Nice", false);
        Trajet t(104, "2025-07-01", "12:00", "14:00", "Marseille", "Nice", {{"Segment1", 20.0f}}, {"Marseille", "Nice"}, true, true, false, "Voiture", 3, true, 150.0f, "Trajet Marseille-Nice");

        std::vector<Trajet> trajets = {t};
        c.setListeTrajet(trajets);

        // Tentative de suppression avec un ID inexistant
        TrajetControlleur controller;
        controller.supprimerTrajet(9999);  // ID inexistant

        // Vérification
        if (c.getListeTrajet().size() == 1 && c.getListeTrajet()[0].getIdTrajet() == 104)
        {
            std::cout << "Test Suppression Erreur : Réussi" << std::endl;
        } else {
            std::cout << "Test Suppression Erreur : Échoué (résultat inattendu)" << std::endl;
        }
    } catch (...) {
        std::cout << "Test Suppression Erreur : Échoué (exception)" << std::endl;

    }
}

int main(){
    testSuppressionTrajet();
    return 0;
}
