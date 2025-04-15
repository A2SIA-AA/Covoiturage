#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

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
        Trajet meilleur = controleur.comparerEmission(trajetsDispo, trajetsTrain, "emission");

        if (meilleur.getDescription() == "Train B") {
            std::cout << "Test comparerEmission (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerEmission (Nominal) : Échoué - Mauvais trajet : "
                      << meilleur.getDescription() << "\n";
        }

    } catch (const std::exception& e) {
        std::cout << "Exception comparerEmission (Nominal) : " << e.what() << "\n";
    }

    // Cas : liste trajets dispo vide
    try {
        std::vector<Trajet> vide;
        controleur.comparerEmission(vide, trajetsTrain, "emission");
        std::cout << "Test comparerEmission (Liste Vide) : Échoué\n";
    } catch (const std::exception& e) {
        std::cout << "Test comparerEmission (Liste Vide) : Réussi - " << e.what() << "\n";
    }

    // Cas : critère invalide
    try {
        controleur.comparerEmission(trajetsDispo, trajetsTrain, "distance");
        std::cout << "Test comparerEmission (Critère invalide) : Échoué\n";
    } catch (const std::exception& e) {
        std::cout << "Test comparerEmission (Critère invalide) : Réussi - " << e.what() << "\n";
    }
}

int main() {
    testComparerEmission();
    return 0;
}
