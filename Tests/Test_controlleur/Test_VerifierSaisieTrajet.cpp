#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>
#include <vector>
#include <string>

void Test_VerifierSaisieTrajet() {
    Database db(":memory");
    TrajetControlleur controleur(db);

    // Données valides de base
    int idTrajet = 1;
    std::string date = "2025-04-20";
    std::string heureDepart = "10:00";
    std::string heureArrivee = "12:00";
    std::string lieuDepart = "Paris";
    std::string lieuArrivee = "Lyon";
    std::vector<std::pair<std::string, float>> segmentsPrix = {{"Paris-Lyon", 30.0}};
    std::vector<std::string> villesEtapes = {"Paris", "Lyon"};
    bool disponible = true;
    bool allerRetour = false;
    bool animaux = false;
    std::string voiture = "Peugeot 208";
    int nombrePlaceDispo = 4;
    bool etat = true;
    float emissionCO2 = 100.0;
    std::string description = "Trajet agréable entre Paris et Lyon.";

    // Cas 1 : Tout est valide
    try {
        controleur.verifierSaisieTrajet(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                  segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                  voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << " Cas 1 (valide) : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << " Cas 1 (valide) : Échoué - " << e.what() << std::endl;
    }

    // Cas 3 : Lieu de départ vide
    try {
        controleur.verifierSaisieTrajet(idTrajet, date, heureDepart, heureArrivee, "", lieuArrivee,
                                  segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                  voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << " Cas 3 (lieu départ vide) : Échoué - aucune exception levée" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Cas 3 (lieu départ vide) : Réussi - " << e.what() << std::endl;
    }

    // Cas 4 : Nombre de places négatif
    try {
        controleur.verifierSaisieTrajet(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                  segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                  voiture, -5, etat, emissionCO2, description);
        std::cout << " Cas 4 (places négatives) : Échoué - aucune exception levée" << std::endl;
    } catch (const std::exception& e) {
        std::cout <<  "Cas 4 (places négatives) : Réussi - " << e.what() << std::endl;
    }

    // Cas 5 : Prix négatif dans un segment
    std::vector<std::pair<std::string, float>> mauvaisPrix = {{"Paris-Lyon", -20.0}};
    try {
        controleur.verifierSaisieTrajet(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                  mauvaisPrix, villesEtapes, disponible, allerRetour, animaux,
                                  voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << " Cas 5 (prix négatif) : Échoué - aucune exception levée" << std::endl;
    } catch (const std::exception& e) {
        std::cout << " Cas 5 (prix négatif) : Réussi - " << e.what() << std::endl;
    }

    // Cas 6 : Date vide
    try {
        controleur.verifierSaisieTrajet(idTrajet, "", heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                                  segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                                  voiture, nombrePlaceDispo, etat, emissionCO2, description);
        std::cout << " Cas 6 (date vide) : Échoué - aucune exception levée" << std::endl;
    } catch (const std::exception& e) {
        std::cout << " Cas 6 (date vide) : Réussi - " << e.what() << std::endl;
    }
}

int main() {
    Test_VerifierSaisieTrajet();
    return 0;
}
