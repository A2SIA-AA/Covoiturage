#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparerPointIntermediaire() {
    Database db(":memory:");
    RechercheControlleur controleur(db);

    std::vector<std::pair<std::string, float>> segments1 = { {"Paris-Lyon", 30.0}, {"Lyon-Marseille", 200.0} };
    std::vector<std::pair<std::string, float>> segments2 = { {"Paris-Lyon", 30.0} };
    std::vector<std::pair<std::string, float>> segments3 = { {"Paris-Lyon", 30.0}, {"Lyon-Aix", 100.0}, {"Aix-Marseille", 30.0} };

    std::vector<std::string> villesEtapes1 = { "Lyon" };
    std::vector<std::string> villesEtapes2 = { };
    std::vector<std::string> villesEtapes3 = { "Lyon", "Aix" };

    // Trajets covoiturage avec différents nombres de points intermédiaires
    Trajet voiture1("2025-06-01", "08:00", "11:00", "Paris", "Marseille",  // 2 points intermédiaires
                    segments1, villesEtapes1, true, false, false, "Citroën", 4, true, 150.0, "Voiture 1");

    Trajet voiture2("2025-06-01", "09:00", "10:30", "Paris", "Lyon",  // 1 point intermédiaire
                    segments2, villesEtapes2, true, false, false, "Peugeot", 2, true, 100.0, "Voiture 2");

    Trajet voiture3("2025-06-01", "07:00", "08:00", "Paris", "Aix",  // 2 points intermédiaires
                    segments3, villesEtapes3, true, false, false, "Renault", 3, true, 120.0, "Voiture 3");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2, voiture3 };

    db.ajouterTrajet(voiture1,1);
    db.ajouterTrajet(voiture2,1);
    db.ajouterTrajet(voiture3,1);

    // Cas nominal
    try {
        std::vector<Trajet> resultat = controleur.comparerPointIntermediaire(trajetsDispo);

        if (resultat.size() == 3 &&
            resultat[0].getDescription() == "Voiture 2" &&
            resultat[1].getDescription() == "Voiture 1" &&
            resultat[2].getDescription() == "Voiture 3") {
            std::cout << "Test comparerPointIntermediaire (Nominal) : Réussi\n";
        } else {
            std::cout << "Test comparerPointIntermediaire (Nominal) : Échoué - Mauvais ordre\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerPointIntermediaire (Nominal) : " << e.what() << "\n";
    }

    // Cas vide
    try {
        std::vector<Trajet> vide;
        std::vector<Trajet> resultat = controleur.comparerPointIntermediaire(vide);

        if (resultat.empty()) {
            std::cout << "Test comparerPointIntermediaire (Vide) : Réussi - Liste vide retournée\n";
        } else {
            std::cout << "Test comparerPointIntermediaire (Vide) : Échoué - Liste non vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception comparerPointIntermediaire (Vide) : " << e.what() << "\n";
    }
}

int main() {
    testComparerPointIntermediaire();
    return 0;
}
