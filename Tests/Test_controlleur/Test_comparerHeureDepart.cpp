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

    // Trajets covoiturage avec différentes heures de départ
    Trajet voiture1(1, "2025-06-01", "08:00", "11:00", "Paris", "Lyon",
                    segments, villes, true, false, false, "Citroën", 4, true, 80.0, "Voiture 1");

    Trajet voiture2(2, "2025-06-01", "06:30", "09:30", "Paris", "Lyon",
                    segments, villes, true, false, false, "Peugeot", 2, true, 75.0, "Voiture 2");

    Trajet voiture3(3, "2025-06-01", "07:15", "10:15", "Paris", "Lyon",
                    segments, villes, true, false, false, "Renault", 3, true, 78.0, "Voiture 3");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2, voiture3 };

    // Cas nominal
    try {
        std::vector<Trajet> resultat = controleur.comparerHeureDepart(trajetsDispo);

        if (resultat.size() == 3 &&
            resultat[0].getDescription() == "Voiture 2" &&
            resultat[1].getDescription() == "Voiture 3" &&
            resultat[2].getDescription() == "Voiture 1") {
            std::cout << "Test comparerHeureDepart (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerHeureDepart (Nominal) : Échoué - Mauvais ordre\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerHeureDepart (Nominal) : " << e.what() << "\n";
    }

    // Cas vide
    try {
        std::vector<Trajet> vide;
        std::vector<Trajet> resultat = controleur.comparerHeureDepart(vide);

        if (resultat.empty()) {
            std::cout << "Test comparerHeureDepart (Vide) : Réussi - Liste vide retournée\n";
        } else {
            std::cout << "Test comparerHeureDepart (Vide) : Échoué - Liste non vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerHeureDepart (Vide) : " << e.what() << "\n";
    }
}

int main() {
    testComparerHeureDepart();
    return 0;
}
