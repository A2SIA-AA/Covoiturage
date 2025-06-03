#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testRechercherTrajet() {
    Database db(":memory:");
    RechercheControlleur controleur(db);

    std::vector<std::pair<std::string, float>> segments = { {"Paris-Lyon", 30.0} };
    std::vector<std::string> villes = { };

    // Trajets de covoiturage avec différentes dates et villes de départ et d'arrivée
    Trajet voiture1("2025-06-01", "08:00", "11:00", "Paris", "Lyon",
                    segments, villes, true, false, false, "Citroën", 4, true, 40.0, "Voiture 1");

    Trajet voiture2("2025-06-01", "09:00", "10:30", "Paris", "Lyon",
                    segments, villes, true, false, false, "Peugeot", 2, true, 30.0, "Voiture 2");

    Trajet voiture3("2025-06-01", "07:00", "08:00", "Paris", "Marseille",
                    segments, villes, true, false, false, "Renault", 3, true, 35.0, "Voiture 3");

    Trajet voiture4("2025-06-02", "10:00", "12:00", "Paris", "Lyon",
                    segments, villes, true, false, false, "Volkswagen", 5, true, 50.0, "Voiture 4");

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2, voiture3, voiture4 };

    db.ajouterTrajet(voiture1,1);
    db.ajouterTrajet(voiture2,1);
    db.ajouterTrajet(voiture3,1);
    db.ajouterTrajet(voiture4,1);

    // Cas nominal : recherche pour Paris -> Lyon le 1er juin 2025
    try {
        std::vector<Trajet> resultat = controleur.rechercherTrajet("Paris", "Lyon", "2025-06-01");

        if (resultat.size() == 2 &&
            resultat[0].getDescription() == "Voiture 1" &&
            resultat[1].getDescription() == "Voiture 2") {
            std::cout << "Test rechercherTrajet (Nominal) : Réussi\n";
        } else {
            std::cout << "Test rechercherTrajet (Nominal) : Échoué - Mauvais résultat\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception rechercherTrajet (Nominal) : " << e.what() << "\n";
    }

    // recherche pour Paris -> Marseille le 1er juin 2025
    try {
        std::vector<Trajet> resultat = controleur.rechercherTrajet("Paris", "Marseille", "2025-06-01");

        if (resultat.size() == 1 &&
            resultat[0].getDescription() == "Voiture 3") {
            std::cout << "Test rechercherTrajet (Marseille, Nominal) : Réussi\n";
        } else {
            std::cout << "Test rechercherTrajet (Marseille, Nominal) : Échoué - Mauvais résultat\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception rechercherTrajet (Marseille, Nominal) : " << e.what() << "\n";
    }

    // Cas où aucune correspondance : recherche avec une date qui ne correspond à aucun trajet
    try {
        std::vector<Trajet> resultat = controleur.rechercherTrajet("Paris", "Lyon", "2025-06-03");

        if (resultat.empty()) {
            std::cout << "Test rechercherTrajet (Pas de trajet trouvé) : Réussi\n";
        } else {
            std::cout << "Test rechercherTrajet (Pas de trajet trouvé) : Échoué - Résultats inattendus\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception rechercherTrajet (Pas de trajet trouvé) : " << e.what() << "\n";
    }

    // Cas où la ville de départ ou d'arrivée est incorrecte
    try {
        std::vector<Trajet> resultat = controleur.rechercherTrajet("Inexistante", "Lyon", "2025-06-01");

        if (resultat.empty()) {
            std::cout << "Test rechercherTrajet (Ville de départ incorrecte) : Réussi\n";
        } else {
            std::cout << "Test rechercherTrajet (Ville de départ incorrecte) : Échoué - Résultats inattendus\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception rechercherTrajet (Ville de départ incorrecte) : " << e.what() << "\n";
    }
}

int main() {
    testRechercherTrajet();
    return 0;
}
