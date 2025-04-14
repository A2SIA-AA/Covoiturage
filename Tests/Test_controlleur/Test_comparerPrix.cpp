#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>

void testComparerPrix() {
    RechercheControlleur controleur;

    // Création des segments de prix
    std::vector<std::pair<std::string, float>> segmentsVoiture = { {"Paris-Lyon", 30.0} };
    std::vector<std::pair<std::string, float>> segmentsVoiture2 = { {"Paris-Lyon", 25.0} };
    std::vector<std::pair<std::string, float>> segmentsTrain = { {"Paris-Lyon", 50.0} };
    std::vector<std::pair<std::string, float>> segmentsTrain2 = { {"Paris-Lyon", 45.0} };

    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets covoiturage
    Trajet trajet1(1, "2025-05-10", "08:00", "12:00", "Paris", "Lyon",
                   segmentsVoiture, villes, true, false, false, "Peugeot", 3, true, 110.5, "Voiture A");
    Trajet trajet2(2, "2025-05-10", "09:00", "13:00", "Paris", "Lyon",
                   segmentsVoiture2, villes, true, false, false, "Renault", 2, true, 105.3, "Voiture B");

    // Trajets train
    Trajet train1(101, "2025-05-10", "08:30", "11:30", "Paris", "Lyon",
                  segmentsTrain, villes, true, false, false, "TGV", 0, true, 90.0, "Train A");
    Trajet train2(102, "2025-05-10", "10:00", "13:00", "Paris", "Lyon",
                  segmentsTrain2, villes, true, false, false, "TGV", 0, true, 92.0, "Train B");

    std::vector<Trajet> trajetsDispo = { trajet1, trajet2 };
    std::vector<Trajet> trajetsTrain = { train1, train2 };

    //Cas nominal
    try {
        auto resultats = controleur.comparerPrix(trajetsDispo, trajetsTrain, "prix");


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

    // Cas : liste vide
    try {
        std::vector<Trajet> vide;
        auto resultats = controleur.comparerPrix(vide, trajetsTrain, "prix");
        if (resultats.first.empty()) {
            std::cout << "Test Liste Trajets Dispo Vide : Réussi\n";
        } else {
            std::cout << "Test Liste Trajets Dispo Vide : Échoué (liste pas vide)\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Test Liste Trajets Dispo Vide : Échoué - " << e.what() << std::endl;
    }

    // Cas : critère invalide
    try {
        controleur.comparerPrix(trajetsDispo, trajetsTrain, "vitesse");
        std::cout << "Test Critère Invalide : Échoué \n";
    } catch (const std::exception& e) {
        std::cout << "Test Critère Invalide : Réussi " << e.what() << std::endl;
    }
}

int main() {
    testComparerPrix();
    return 0;
}
