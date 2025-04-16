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

    // Trajets covoiturage avec différentes émissions de CO2
    Trajet voiture1(1, "2025-06-01", "08:00", "11:00", "Paris", "Lyon",  // 150g CO2
                    segments, villes, true, false, false, "Citroën", 4, true, 150.0, "Voiture 1");

    Trajet voiture2(2, "2025-06-01", "09:00", "10:30", "Paris", "Lyon",  // 100g CO2
                    segments, villes, true, false, false, "Peugeot", 2, true, 100.0, "Voiture 2");

    Trajet voiture3(3, "2025-06-01", "07:00", "08:00", "Paris", "Lyon",  // 120g CO2
                    segments, villes, true, false, false, "Renault", 3, true, 120.0, "Voiture 3");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2, voiture3 };

    // Cas nominal
    try {
        std::vector<Trajet> resultat = controleur.comparerEmission(trajetsDispo);

        if (resultat.size() == 3 &&
            resultat[0].getDescription() == "Voiture 2" &&
            resultat[1].getDescription() == "Voiture 3" &&
            resultat[2].getDescription() == "Voiture 1") {
            std::cout << "Test comparerEmission (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerEmission (Nominal) : Échoué - Mauvais ordre\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerEmission (Nominal) : " << e.what() << "\n";
    }

    // Cas vide
    try {
        std::vector<Trajet> vide;
        std::vector<Trajet> resultat = controleur.comparerEmission(vide);

        if (resultat.empty()) {
            std::cout << "Test comparerEmission (Vide) : Réussi - Liste vide retournée\n";
        } else {
            std::cout << "Test comparerEmission (Vide) : Échoué - Liste non vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerEmission (Vide) : " << e.what() << "\n";
    }
}

int main() {
    testComparerEmission();
    return 0;
}
