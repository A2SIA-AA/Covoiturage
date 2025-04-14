#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>

void testComparerEmission() {
    RechercheControlleur controleur;

    std::vector<std::pair<std::string, float>> segments = { {"Paris-Lyon", 30.0} };
    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets disponibles
    Trajet trajet1(1, "2025-05-10", "08:00", "12:00", "Paris", "Lyon",
                   segments, villes, true, false, false, "Peugeot", 3, true, 110.5, "Voiture A");
    Trajet trajet2(2, "2025-05-10", "09:00", "13:00", "Paris", "Lyon",
                   segments, villes, true, false, false, "Renault", 2, true, 95.2, "Voiture B");

    // Trains
    Trajet train1(101, "2025-05-10", "08:30", "11:30", "Paris", "Lyon",
                  segments, villes, true, false, false, "TGV", 0, true, 85.0, "Train A");
    Trajet train2(102, "2025-05-10", "10:00", "13:00", "Paris", "Lyon",
                  segments, villes, true, false, false, "TGV", 0, true, 78.0, "Train B");

    std::vector<Trajet> trajetsDispo = { trajet1, trajet2 };
    std::vector<Trajet> trajetsTrain = { train1, train2 };

    // Cas nominal
    try {
        auto resultats = controleur.comparerEmission(trajetsDispo, trajetsTrain, "emission");

        bool testOK = resultats.first[0].getDescription() == "Voiture B" &&
                      resultats.second[0].getDescription() == "Train B";

        if (testOK) {
            std::cout << "Test Cas Nominal : Réussi\n";
        } else {
            std::cout << "Test Cas Nominal : Échoué (ordre incorrect)\n";
        }

    } catch (const std::exception& e) {
        std::cout << "Test Cas Nominal : Échoué - " << e.what() << std::endl;
    }

    // Cas : liste vide des trajets disponibles
    try {
        std::vector<Trajet> vide;
        controleur.comparerEmission(vide, trajetsTrain, "emission");
        std::cout << "Test Liste Trajets Dispo Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Liste Trajets Dispo Vide : Réussi - " << e.what() << std::endl;
    }

    // Cas : critère invalide
    try {
        controleur.comparerEmission(trajetsDispo, trajetsTrain, "distance");
        std::cout << "Test Critère Invalide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Critère Invalide : Réussi " << e.what() << std::endl;
    }
}

int main() {
    testComparerEmission();
    return 0;
}
