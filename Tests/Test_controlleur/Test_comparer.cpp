#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparer() {
    RechercheControlleur controleur;

    std::vector<std::pair<std::string, float>> segmentsVoiture = { {"Paris-Lyon", 40.0} };
    std::vector<std::pair<std::string, float>> segmentsVoiture2 = { {"Paris-Lyon", 35.0} };
    std::vector<std::pair<std::string, float>> segmentsTrain = { {"Paris-Lyon", 60.0} };
    std::vector<std::pair<std::string, float>> segmentsTrain2 = { {"Paris-Lyon", 55.0} };

    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets voiture
    Trajet voiture1(1, "2025-06-15", "08:00", "11:30", "Paris", "Lyon",
                    segmentsVoiture, villes, true, false, false, "Clio", 3, true, 95.0, "Voiture A");

    Trajet voiture2(2, "2025-06-15", "09:00", "12:00", "Paris", "Lyon",
                    segmentsVoiture2, villes, true, false, false, "308", 2, true, 90.0, "Voiture B");

    // Trains
    Trajet train1(101, "2025-06-15", "10:00", "13:00", "Paris", "Lyon",
                  segmentsTrain, villes, true, false, false, "TGV", 0, true, 60.0, "Train A");

    Trajet train2(102, "2025-06-15", "07:30", "10:30", "Paris", "Lyon",
                  segmentsTrain2, villes, true, false, false, "TGV", 0, true, 65.0, "Train B");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2 };
    std::vector<Trajet> trajetsTrain = { train1, train2 };

    //Cas nominal
    try {
        auto resultats = controleur.comparer(trajetsDispo, trajetsTrain);

    } catch (const std::exception& e) {
        std::cout << "Test Cas Nominal : Échoué - " << e.what() << std::endl;
    }

    //Cas : liste vide
    try {
        std::vector<Trajet> vide;
        controleur.comparer(vide, trajetsTrain);
        std::cout << "Test Liste Vide : Échoué (exception attendue)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Liste Vide : Réussi - " << e.what() << std::endl;
    }
}

int main() {
    testComparer();
    return 0;
}
