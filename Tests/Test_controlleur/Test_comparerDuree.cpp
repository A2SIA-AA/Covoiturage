#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparerDuree() {
    RechercheControlleur controleur;

    std::vector<std::pair<std::string, float>> segments = { {"Paris-Lyon", 30.0} };
    std::vector<std::string> villes = { "Paris", "Lyon" };

    //Trajets voiture
    Trajet voiture1(1, "2025-06-01", "08:00", "11:00", "Paris", "Lyon",
                    segments, villes, true, false, false, "Citroën", 4, true, 80.0, "Voiture 1");

    Trajet voiture2(2, "2025-06-01", "09:00", "10:30", "Paris", "Lyon",
                    segments, villes, true, false, false, "Peugeot", 2, true, 75.0, "Voiture 2");

    //Trajets train
    Trajet train1(101, "2025-06-01", "07:30", "10:00", "Paris", "Lyon",
                  segments, villes, true, false, false, "TGV", 0, true, 60.0, "Train 1");

    Trajet train2(102, "2025-06-01", "08:30", "09:30", "Paris", "Lyon",
                  segments, villes, true, false, false, "TGV", 0, true, 62.0, "Train 2");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2 };
    std::vector<Trajet> trajetsTrain = { train1, train2 };

    //Cas nominal
    try {
        Trajet meilleur = controleur.comparerDuree(trajetsDispo, trajetsTrain, "duree");

        if (meilleur.getDescription() == "Train 2") {
            std::cout << "Test comparerDuree (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerDuree (Nominal) : Échoué - Mauvais trajet retourné : "
                      << meilleur.getDescription() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerDuree (Nominal) : " << e.what() << "\n";
    }

    //Cas : liste vide
    try {
        std::vector<Trajet> vide;
        controleur.comparerDuree(vide, vide, "duree");
        std::cout << "Test comparerDuree (Vide) : Échoué\n";
    } catch (const std::exception& e) {
        std::cout << "Test comparerDuree (Vide) : Réussi - " << e.what() << "\n";
    }

    // Cas : critère invalide
    try {
        controleur.comparerDuree(trajetsDispo, trajetsTrain, "temps");
        std::cout << "Test comparerDuree (Critère invalide) : Échoué\n";
    } catch (const std::exception& e) {
        std::cout << "Test comparerDuree (Critère invalide) : Réussi - " << e.what() << "\n";
    }
}

int main() {
    testComparerDuree();
    return 0;
}
