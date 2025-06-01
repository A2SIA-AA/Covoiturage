#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void testComparer() {
    // 1) On crée une base en mémoire (":memory:") pour satisfaire le constructeur de RechercheControlleur
    Database db(":memory:");

    // 2) On instancie le contrôleur en lui passant 'db'
    RechercheControlleur controleur(db);

    // 3) On prépare deux trajets de comparaison
    std::vector<std::pair<std::string, float>> segmentsVoiture1 = { {"Paris-Lyon", 40.0f} };
    std::vector<std::pair<std::string, float>> segmentsVoiture2 = { {"Paris-Lyon", 35.0f} };
    std::vector<std::string> villes = { "Paris", "Lyon" };

    // Trajet A (prix = 40)
    Trajet voiture1(
        /* date */             "2025-06-15",
        /* heureDepart */      "08:00",
        /* heureArrivee */     "11:30",
        /* lieuDepart */       "Paris",
        /* lieuArrivee */      "Lyon",
        /* segmentsPrix */     segmentsVoiture1,
        /* villesEtapes */     villes,
        /* disponible */       true,
        /* allerRetour */      false,
        /* animaux */          false,
        /* voiture */          "Clio",
        /* nombrePlaceDispo */ 3,
        /* etat */             true,
        /* emissionCO2 */      95.0f,
        /* description */      "Voiture A"
    );

    // Trajet B (prix = 35)
    Trajet voiture2(
        /* date */             "2025-06-15",
        /* heureDepart */      "09:00",
        /* heureArrivee */     "12:00",
        /* lieuDepart */       "Paris",
        /* lieuArrivee */      "Lyon",
        /* segmentsPrix */     segmentsVoiture2,
        /* villesEtapes */     villes,
        /* disponible */       true,
        /* allerRetour */      false,
        /* animaux */          false,
        /* voiture */          "308",
        /* nombrePlaceDispo */ 2,
        /* etat */             true,
        /* emissionCO2 */      90.0f,
        /* description */      "Voiture B"
    );

    std::vector<Trajet> trajetsDispo = { voiture1, voiture2 };

    // --- Cas nominal : on s'attend à ce que le trajet le moins cher (voiture B) soit en tête ---
    try {
        auto resultats = controleur.comparer(trajetsDispo);
        if (!resultats.empty() && resultats[0].getDescription() == "Voiture B") {
            std::cout << "Test Cas Nominal : Réussi - Trajet top = "
                      << resultats[0].getDescription() << "\n";
        } else {
            std::cout << "Test Cas Nominal : Échoué - ordre inattendu\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception dans Test Cas Nominal : " << e.what() << "\n";
    }

    // --- Cas liste vide : on s'attend à recevoir une liste vide (sans exception) ---
    try {
        std::vector<Trajet> vide;
        auto resultats = controleur.comparer(vide);
        if (resultats.empty()) {
            std::cout << "Test Liste Vide : Réussi - Liste vide retournée\n";
        } else {
            std::cout << "Test Liste Vide : Échoué - La liste n'est pas vide\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Test Liste Vide : Échoué - Exception capturée : " << e.what() << "\n";
    }
}

int main() {
    testComparer();
    return 0;
}
