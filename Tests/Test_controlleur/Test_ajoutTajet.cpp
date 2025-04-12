#include "Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>
#include <vector>
#include <string>

void testVerifierSaisie() {
    TrajetControlleur controleur;

    // Test avec des informations valides
    int idTrajet = 1;
    std::string date = "2025-04-15";
    std::string heureDepart = "10:00";
    std::string heureArrivee = "14:00";
    std::string lieuDepart = "Paris";
    std::string lieuArrivee = "Lyon";
    std::vector<std::pair<std::string, float>> segmentsPrix = {{"Paris-Lyon", 30.0}};
    std::vector<std::string> villesEtapes = {"Paris", "Lyon"};
    bool disponible = true;
    bool allerRetour = false;
    bool animaux = false;
    std::string voiture = "Peugeot 308";
    int nombrePlaceDispo = 4;
    bool etat = true; // Trajet à venir
    float emissionCO2 = 120.0;
    std::string description = "Trajet Paris-Lyon";

    // Vérification de la saisie pour un trajet valide
    try {
        controleur.verifierSaisie(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                 segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                 voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << "Test Saisie Valide : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Saisie Valide : Échoué - " << e.what() << std::endl;
    }

    // Test avec une date vide (devrait échouer)
    date = "";
    try {
        controleur.verifierSaisie(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                 segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                 voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << "Test Date Vide : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Date Vide : Échoué - " << e.what() << std::endl;
    }

    // Test avec un nombre de places disponible négatif (devrait échouer)
    nombrePlaceDispo = -1;
    try {
        controleur.verifierSaisie(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                 segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                 voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << "Test Nombre de Places Dispo Négatif : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Nombre de Places Dispo Négatif : Échoué - " << e.what() << std::endl;
    }
}

int main() {
    // Lancer les tests
    testVerifierSaisie();
    return 0;
}
