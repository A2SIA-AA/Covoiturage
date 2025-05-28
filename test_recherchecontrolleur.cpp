#include "Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
#include "Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include "Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "Modele/Modele_hpp/BaseDonnees.hpp"
#include "Modele/Modele_hpp/Trajet.hpp"

#include <iostream>
#include <vector>

int main() {
    Database db("base_test.sqlite");
    std::cout << "Base initialisée.\n";

    InscriptionControlleur inscriptionCtrl(db);

    try {
        inscriptionCtrl.traiterInscription("test", "prenom", "test@example.com", "pwd123", "76120", false);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Arrêt propre du programme en cas d’erreur
    }
    // Connexion
    ConnexionControlleur conn(db);
    auto userOpt = conn.verifierUtilisateur("test@example.com", "pwd123");
    if (!userOpt) {
        std::cerr << "Échec de la connexion.\n";
        return 1;
    }
    int userId = userOpt->getIdUtilisateur();
/*
    // Ajout trajets
    TrajetControlleur trajCtrl(db);
    trajCtrl.creerTrajet(userId, "2025-07-01", "08:00", "10:00", "A", "B", {{"A-B", 20}}, {}, true, false, false, "Diesel", 3, true, 8.5, "T1");
    trajCtrl.creerTrajet(userId, "2025-07-01", "09:00", "11:00", "A", "B", {{"A-B", 15}}, {}, true, false, false, "Essence", 3, true, 7.2, "T2");
    trajCtrl.creerTrajet(userId, "2025-07-01", "07:00", "09:00", "A", "B", {{"A-B", 40}}, {}, true, false, false, "Electrique", 3, true, 0.0, "T3");
*/
  // Recherche
    RechercheControlleur rechercheCtrl(db);
    auto trajets = rechercheCtrl.rechercherTrajet("A", "B", "2025-07-01");
    std::cout << "\n--- Trajets trouvés : ---\n";
    for (const auto& t : trajets) {
        std::cout << "ID: " << t.getIdTrajet()
                  << " | Desc: " << t.getDescription()
                  << " | Date: " << t.getDate()
                  << " | CO2: " << t.getEmissionCO2()
                  << "\n";
    }
    std::cout << "--------------------------\n";



    auto parEmission = rechercheCtrl.comparerEmission(trajets);
    std::cout << "[comparerEmission] : ";
    for (auto& t : parEmission) std::cout << t.getDescription() << ' ';
    std::cout << "\n";

    float e = rechercheCtrl.calculerEmission(200.0f, "Diesel", 6.0f, 5);
    std::cout << "[calculerEmission] Diesel 200km,6L/100,anc5: " << e << "\n";

    auto parDuree = rechercheCtrl.comparerDuree(trajets);
    std::cout << "[comparerDuree] : ";
    for (auto& t : parDuree) std::cout << t.getDescription() << ' ';
    std::cout << "\n";

    auto parHeure = rechercheCtrl.comparerHeureDepart(trajets);
    std::cout << "[comparerHeureDepart] : ";
    for (auto& t : parHeure) std::cout << t.getDescription() << ' ';
    std::cout << "\n";

    auto parEtapes = rechercheCtrl.comparerPointIntermediaire(trajets);
    std::cout << "[comparerPointIntermediaire] : ";
    for (auto& t : parEtapes) std::cout << t.getDescription() << ' ';
    std::cout << "\n";

    auto defaut = rechercheCtrl.comparer(trajets);
    std::cout << "[comparer par défaut] : ";
    for (auto& t : defaut) std::cout << t.getDescription() << ' ';
    std::cout << "\n";

    return 0;
}
