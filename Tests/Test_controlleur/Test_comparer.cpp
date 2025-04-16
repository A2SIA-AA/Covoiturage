#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparer() {
    RechercheControlleur controleur;

    std::vector<std::pair<std::string, float>> segmentsVoiture = { {"Paris-Lyon", 40.0} };
    std::vector<std::pair<std::string, float>> segmentsVoiture2 = { {"Paris-Lyon", 35.0} };

    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajets voiture
    Trajet voiture1(1, "2025-06-15", "08:00", "11:30", "Paris", "Lyon",
                    segmentsVoiture, villes, true, false, false, "Clio", 3, true, 95.0, "Voiture A");

    Trajet voiture2(2, "2025-06-15", "09:00", "12:00", "Paris", "Lyon",
                    segmentsVoiture2, villes, true, false, false, "308", 2, true, 90.0, "Voiture B");
    std::vector<Trajet> trajetsDispo = { voiture1, voiture2 };

    // Cas nominal
    try {
        std::vector<Trajet> resultats = controleur.comparer(trajetsDispo);

        if (!resultats.empty()) {
            std::cout << "Test Cas Nominal : Réussi - Trajet top = " << resultats[0].getDescription() << "\n";
        } else {
            std::cout << "Test Cas Nominal : Échoué - Liste retournée vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception dans Test Cas Nominal : " << e.what() << "\n";
    }

    // Cas : liste vide
    try {
        std::vector<Trajet> vide;
        std::vector<Trajet> resultats = controleur.comparer(vide);

        std::cout << "Test Liste Vide : Échoué (exception attendue ou liste vide)\n";
    } catch (const std::exception& e) {
        std::cout << "Test Liste Vide : Réussi - Exception capturée : " << e.what() << "\n";
    }
}

int main() {
    testComparer();
    return 0;
}
