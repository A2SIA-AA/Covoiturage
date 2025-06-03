#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparerPrix() {
    Database db(":memory:");
    RechercheControlleur controleur(db);

    std::vector<std::pair<std::string, float>> segments1 = { {"Paris-Lyon", 40.0} };
    std::vector<std::pair<std::string, float>> segments2 = { {"Paris-Lyon", 30.0} };
    std::vector<std::pair<std::string, float>> segments3 = { {"Paris-Lyon", 30.0} };
    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets covoiturage avec différents prix
    Trajet voiture1("2025-06-01", "08:00", "11:00", "Paris", "Lyon",
                    segments1, villes, true, false, false, "Citroën", 4, true, 70.0, "Voiture 1");

    Trajet voiture2("2025-06-01", "09:00", "10:30", "Paris", "Lyon",
                    segments2, villes, true, false, false, "Peugeot", 2, true, 80.0, "Voiture 2");

    Trajet voiture3("2025-06-01", "07:00", "08:00", "Paris", "Lyon",
                    segments3, villes, true, false, false, "Renault", 3, true, 75.0, "Voiture 3");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2, voiture3 };

    // Cas nominal
    try {
        std::vector<Trajet> resultat = controleur.comparerPrix(trajetsDispo);

        if (resultat.size() == 3 &&
            resultat[0].getDescription() == "Voiture 2" &&
            resultat[1].getDescription() == "Voiture 3" &&
            resultat[2].getDescription() == "Voiture 1") {
            std::cout << "Test comparerPrix (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerPrix (Nominal) : Échoué - Mauvais ordre\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerPrix (Nominal) : " << e.what() << "\n";
    }

    // Cas vide
    try {
        std::vector<Trajet> vide;
        std::vector<Trajet> resultat = controleur.comparerPrix(vide);

        if (resultat.empty()) {
            std::cout << "Test comparerPrix (Vide) : Réussi - Liste vide retournée\n";
        } else {
            std::cout << "Test comparerPrix (Vide) : Échoué - Liste non vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerPrix (Vide) : " << e.what() << "\n";
    }
}

int main() {
    testComparerPrix();
    return 0;
}
