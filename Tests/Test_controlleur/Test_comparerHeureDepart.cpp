#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparerHeureDepart() {
    RechercheControlleur controleur;

    std::vector<std::pair<std::string, float>> segments = { {"Paris-Lyon", 30.0} };
    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets voiture
    Trajet voiture1(1, "2025-06-01", "07:30", "11:00", "Paris", "Lyon",
                    segments, villes, true, false, false, "Citroën", 4, true, 80.0, "Voiture A");

    Trajet voiture2(2, "2025-06-01", "06:00", "10:30", "Paris", "Lyon",
                    segments, villes, true, false, false, "Peugeot", 2, true, 75.0, "Voiture B");

    // Trajets train
    Trajet train1(101, "2025-06-01", "08:30", "10:30", "Paris", "Lyon",
                  segments, villes, true, false, false, "TGV", 0, true, 60.0, "Train A");

    Trajet train2(102, "2025-06-01", "05:45", "09:00", "Paris", "Lyon",
                  segments, villes, true, false, false, "TGV", 0, true, 62.0, "Train B");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2 };
    std::vector<Trajet> trajetsTrain = { train1, train2 };

    // Cas nominal
    try {
        Trajet meilleur = controleur.comparerHeureDepart(trajetsDispo, trajetsTrain, "heure");

        if (meilleur.getDescription() == "Train B") {
            std::cout << "Test comparerHeureDepart (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerHeureDepart (Nominal) : Échoué - Résultat = "
                      << meilleur.getDescription() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerHeureDepart (Nominal) : " << e.what() << "\n";
    }

    //Cas : liste vide
    try {
        std::vector<Trajet> vide;
        controleur.comparerHeureDepart(vide, trajetsTrain, "heure");
        std::cout << "Test comparerHeureDepart (Liste Vide) : Échoué\n";
    } catch (const std::exception& e) {
        std::cout << "Test comparerHeureDepart (Liste Vide) : Réussi - " << e.what() << "\n";
    }

    //Cas : critère invalide
    try {
        controleur.comparerHeureDepart(trajetsDispo, trajetsTrain, "départ");
        std::cout << "Test comparerHeureDepart (Critère invalide) : Échoué\n";
    } catch (const std::exception& e) {
        std::cout << "Test comparerHeureDepart (Critère invalide) : Réussi - " << e.what() << "\n";
    }
}

int main() {
    testComparerHeureDepart();
    return 0;
}
