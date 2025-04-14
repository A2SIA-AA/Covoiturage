#include "Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>

void testComparerDistanceTrajet() {
    RechercheControlleur controleur;

    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Chaque segment ne représente PAS une distance, mais on simule avec calculerDistance
    std::vector<std::pair<std::string, float>> segmentsVoiture1 = { {"Paris-Lyon", 35.0}, {"Lyon-Macon", 15.0} };
    std::vector<std::pair<std::string, float>> segmentsVoiture2 = { {"Paris-Lyon", 45.0} };
    std::vector<std::pair<std::string, float>> segmentsTrain1 = { {"Paris-Lyon", 25.0}, {"Lyon-Macon", 20.0} };
    std::vector<std::pair<std::string, float>> segmentsTrain2 = { {"Paris-Lyon", 40.0} };

    Trajet voitureA(1, "2025-06-01", "08:00", "12:00", "Paris", "Lyon",
                   segmentsVoiture1, villes, true, false, false, "Tesla", 4, true, 80.0, "Voiture A");

    Trajet voitureB(2, "2025-06-01", "09:00", "13:00", "Paris", "Lyon",
                   segmentsVoiture2, villes, true, false, false, "Citroen", 2, true, 70.0, "Voiture B");

    Trajet trainA(101, "2025-06-01", "08:30", "11:30", "Paris", "Lyon",
                  segmentsTrain1, villes, true, false, false, "TGV", 0, true, 60.0, "Train A");

    Trajet trainB(102, "2025-06-01", "10:00", "13:00", "Paris", "Lyon",
                  segmentsTrain2, villes, true, false, false, "TGV", 0, true, 65.0, "Train B");

    std::vector<Trajet> trajetsDispo = { voitureA, voitureB };
    std::vector<Trajet> trajetsTrain = { trainA, trainB };

    //Cas nominal
    try {
        auto resultats = controleur.comparerDistanceTrajet(trajetsDispo, trajetsTrain, "distance");

        bool testOK = resultats.first[0].getDescription() == "Voiture A" &&
              resultats.second[0].getDescription() == "Train A";

        if (testOK) {
            std::cout << "Test Cas Nominal : Réussi\n";
        } else {
            std::cout << "Test Cas Nominal : Échoué (ordre incorrect)\n";
        }

    } catch (const std::exception& e) {
        std::cout << "Test Cas Nominal : Échoué  " << e.what() << std::endl;
    }

    //Cas : liste vide
    try {
        std::vector<Trajet> vide;
        controleur.comparerDistanceTrajet(vide, trajetsTrain, "distance");
        std::cout << "Test Liste Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Liste Vide : Réussi  " << e.what() << std::endl;
    }

    //Cas : mauvais critère
    try {
        controleur.comparerDistanceTrajet(trajetsDispo, trajetsTrain, "volume");
        std::cout << "Test Critère Invalide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Critère Invalide : Réussi - " << e.what() << std::endl;
    }
}

int main() {
    testComparerDistanceTrajet();
    return 0;
}
