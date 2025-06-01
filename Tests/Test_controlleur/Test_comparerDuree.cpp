#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparerDuree() {
    Database db(":memory:");
    RechercheControlleur controleur(db);

    std::vector<std::pair<std::string, float>> segments = { {"Paris-Lyon", 30.0} };
    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets covoiturage avec différentes durées
    Trajet voiture1( "2025-06-01", "08:00", "11:00", "Paris", "Lyon", // 3h
                    segments, villes, true, false, false, "Citroën", 4, true, 80.0, "Voiture 1");

    Trajet voiture2("2025-06-01", "09:00", "10:30", "Paris", "Lyon", // 1h30
                    segments, villes, true, false, false, "Peugeot", 2, true, 75.0, "Voiture 2");

    Trajet voiture3("2025-06-01", "07:00", "08:00", "Paris", "Lyon", // 1h
                    segments, villes, true, false, false, "Renault", 3, true, 78.0, "Voiture 3");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2, voiture3 };

    // Cas nominal
    try {
        std::vector<Trajet> resultat = controleur.comparerDuree(trajetsDispo);

        if (resultat.size() == 3 &&
            resultat[0].getDescription() == "Voiture 3" &&
            resultat[1].getDescription() == "Voiture 2" &&
            resultat[2].getDescription() == "Voiture 1") {
            std::cout << "Test comparerDuree (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerDuree (Nominal) : Échoué - Mauvais ordre\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerDuree (Nominal) : " << e.what() << "\n";
    }

    // Cas vide
    try {
        std::vector<Trajet> vide;
        std::vector<Trajet> resultat = controleur.comparerDuree(vide);

        if (resultat.empty()) {
            std::cout << "Test comparerDuree (Vide) : Réussi - Liste vide retournée\n";
        } else {
            std::cout << "Test comparerDuree (Vide) : Échoué - Liste non vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerDuree (Vide) : " << e.what() << "\n";
    }
}

int main() {
    testComparerDuree();
    return 0;
}
