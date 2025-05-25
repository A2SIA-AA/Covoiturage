#include "Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
#include "Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include "Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "Controlleur/Controlleur_hpp/ModifierProfilControlleur.hpp"
/*
#include "Interface/Interface_hpp/AccueilInterface.hpp"
#include "Interface/Interface_hpp/TrajetInterface.hpp"
#include "Interface/Interface_hpp/ConnexionInterface.hpp"
#include "Interface/Interface_hpp/InscriptionInterface.hpp"
#include "Interface/Interface_hpp/RechercheInterface.hpp"
#include "Interface/Interface_hpp/MesAnnoncesInterface.hpp"
#include "Interface/Interface_hpp/MesReservationsInterface.hpp"
#include "Interface/Interface_hpp/ModifierProfilInterface.hpp"

*/
#include "Modele/Modele_hpp/Conducteur.hpp"
#include "Modele/Modele_hpp/Message.hpp"
#include "Modele/Modele_hpp/Trajet.hpp"
#include "Modele/Modele_hpp/Reservation.hpp"
#include "Modele/Modele_hpp/Passager.hpp"
#include "Modele/Modele_hpp/Utilisateur.hpp"
#include "Modele/Modele_hpp/BaseDonnees.hpp"

int main() {
        Database db("maBase.sqlite");
/*
    InscriptionControlleur inscriptionCtrl(db);

    try {
        inscriptionCtrl.traiterInscription("dicko", "loraine", "loraine.dicko@gmail.com", "123457", "76800", false);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Arrêt propre du programme en cas d’erreur
    }

*/




    ConnexionControlleur connexionCtrl(db);
    auto utilisateurOptionel = connexionCtrl.verifierUtilisateur("joelle.farhat@gmail.com", "123456");

    if (utilisateurOptionel) {
        std::cout << "Connexion réussie ! Bienvenue.\n";
    } else {
        std::cout << "Échec de la connexion : Email ou mot de passe incorrect.\n";
    }
    ModifierProfilControlleur modifProfCtrl(db);
    modifProfCtrl.ModifierProfil(utilisateurOptionel->getIdUtilisateur(), "motPasse", "111111");


    /*

    TrajetControlleur trajetCtrl(db);
    trajetCtrl.creerTrajet(
    utilisateurOptionel->getIdUtilisateur(),
    "2025-06-15",                            // date
    "08:45",                                 // heureDepart
    "12:00",                                 // heureArrivee
    "Paris",                                 // lieuDepart
    "lille",                                  // lieuArrivee
    {                                        // segmentsPrix
        {"Paris-lille", 15.0}
    },
    {},                             // villesEtapes
    true,                                    // disponible
    false,                                   // allerRetour
    true,                                    // animaux
    "Renault Clio - Bleu",                   // voiture
    1,                                       // nombrePlaceDispo
    true,                                    // etat
    123,                                  // emissionCO2
    "Trajet agreable avec pause à Orléans"   // description
);

*/

/*

    TrajetControlleur trajetCtrl(db);
    std::vector<Trajet> trajets = trajetCtrl.obtenirTrajets("Paris", "lille", "2025-06-15" );


    if (trajets.empty()) {
        std::cout << "Aucun trajet trouvé.\n";

    }

    for ( auto& trajet : trajets) {
        std::cout << "---------------------------\n";
        std::cout << "ID Trajet: " << trajet.getIdTrajet() << "\n";
        std::cout << "Date: " << trajet.getDate() << "\n";
        std::cout << "Heure départ: " << trajet.getHeureDepart() << "\n";
        std::cout << "Heure arrivée: " << trajet.getHeureArrive() << "\n";
        std::cout << "Lieu départ: " << trajet.getLieuDepart() << "\n";
        std::cout << "Lieu arrivée: " << trajet.getLieuArrive() << "\n";
        std::cout << "Voiture: " << trajet.getVoiture() << "\n";
        std::cout << "Places dispo: " << trajet.getNombrePlaceDispo() << "\n";
        std::cout << "CO2: " << trajet.getEmissionCO2() << " g/km\n";
        std::cout << "Description: " << trajet.getDescription() << "\n";
    }
    std::cout << "---------------------------\n";

    //TrajetControlleur trajetCtrl(db);
    //trajetCtrl.reservation(2, 15, utilisateurOptionel->getIdUtilisateur(), true);
    trajetCtrl.supprimerReservation(2);


    std::vector<Trajet> trajetsNew = trajetCtrl.obtenirTrajets("Paris", "lille", "2025-06-15" );


    if (trajetsNew.empty()) {
        std::cout << "Aucun trajet trouvé.\n";

    }

    for ( auto& trajet : trajetsNew) {
        std::cout << "---------------------------\n";
        std::cout << "ID Trajet: " << trajet.getIdTrajet() << "\n";
        std::cout << "Date: " << trajet.getDate() << "\n";
        std::cout << "Heure départ: " << trajet.getHeureDepart() << "\n";
        std::cout << "Heure arrivée: " << trajet.getHeureArrive() << "\n";
        std::cout << "Lieu départ: " << trajet.getLieuDepart() << "\n";
        std::cout << "Lieu arrivée: " << trajet.getLieuArrive() << "\n";
        std::cout << "Voiture: " << trajet.getVoiture() << "\n";
        std::cout << "Places dispo: " << trajet.getNombrePlaceDispo() << "\n";
        std::cout << "CO2: " << trajet.getEmissionCO2() << " g/km\n";
        std::cout << "Description: " << trajet.getDescription() << "\n";
    }
    std::cout << "---------------------------\n";

*/

    /*
    RechercheControlleur rechercheCtrl(db);

    float x = rechercheCtrl.calculerEmission(200, "diesel", 6.5f, 10);
    std::cout << "emission 10 ans : " << x << "\n";

    float x1 = rechercheCtrl.calculerEmission(200, "diesel", 6.5f, 20);
    std::cout << "emission 20 ans : " << x1 << "\n";
    */

    /*
    RechercheControlleur rechercheCtrl;

    rechercheCtrl.comparerHeureDepart()

    TrajetControlleur trajetCtrl(db);
    trajetCtrl.supprimerTrajet(4);

    */


    return 0;

}