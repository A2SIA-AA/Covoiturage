#include "Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


void testComparerPointIntermediaire() {
    RechercheControlleur controleur;

    std::vector<std::pair<std::string, float>> segments = { {"Paris-Lyon", 30.0} };

    // Trajets disponibles
    std::vector<std::string> etapesVoiture1 = { "Etape1", "Etape2" }; // 2 étapes
    std::vector<std::string> etapesVoiture2 = { "Etape1" }; // 1 étape

    Trajet voiture1(1, "2025-07-01", "08:00", "12:00", "Paris", "Lyon",
                    segments, etapesVoiture1, true, false, false, "Renault", 3, true, 90.0, "Voiture A");

    Trajet voiture2(2, "2025-07-01", "09:00", "13:00", "Paris", "Lyon",
                    segments, etapesVoiture2, true, false, false, "Peugeot", 2, true, 85.0, "Voiture B");

    // Trains
    std::vector<std::string> etapesTrain1 = { "EtapeA", "EtapeB", "EtapeC" }; // 3 étapes
    std::vector<std::string> etapesTrain2 = {}; // 0 étape

    Trajet train1(101, "2025-07-01", "10:00", "13:00", "Paris", "Lyon",
                  segments, etapesTrain1, true, false, false, "TGV", 0, true, 60.0, "Train A");

    Trajet train2(102, "2025-07-01", "07:00", "10:00", "Paris", "Lyon",
                  segments, etapesTrain2, true, false, false, "TGV", 0, true, 58.0, "Train B");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2 };
    std::vector<Trajet> trajetsTrain = { train1, train2 };

    //Cas nominal
    try {
        auto resultats = controleur.comparerPointIntermediaire(trajetsDispo, trajetsTrain, "arret");

        bool testOK = resultats.first[0].getDescription() == "Voiture B" &&
              resultats.second[0].getDescription() == "Train B";

        if (testOK) {
            std::cout << "Test Cas Nominal : Réussi\n";
        } else {
            std::cout << "Test Cas Nominal : Échoué (ordre incorrect)\n";
        }


    } catch (const std::exception& e) {
        std::cout << "Test Cas Nominal : Échoué " << e.what() << std::endl;
    }

    //Cas : liste vide
    try {
        std::vector<Trajet> vide;
        controleur.comparerPointIntermediaire(vide, trajetsTrain, "arret");
        std::cout << "Test Liste Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Liste Vide : Réussi  " << e.what() << std::endl;
    }

    //Cas : critère invalide
    try {
        controleur.comparerPointIntermediaire(trajetsDispo, trajetsTrain, "stop");
        std::cout << "Test Critère Invalide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Critère Invalide : Réussi - " << e.what() << std::endl;
    }
}

int main() {
    testComparerPointIntermediaire();
    return 0;
}
