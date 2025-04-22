#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "../../Interface/Interface_hpp/MesReservationsInterface.hpp"
#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include "../../Modele/Modele_hpp/Reservation.hpp"


TEST(MesReservationsTest, AffichageAvecReservations) {
    Passager  ali(1, "Ali", "Baba", "ali.baba@example.com", "motDePasse123", "12 rue de Paris, 75000 Paris", false);
    std::vector<std::pair<std::string, float>> segmentsPrix = {
        {"Bordeaux", 15.5},
        {"Orléans", 10.0},
        {"Tours", 12.5}
    };

    std::vector<std::string> villesEtapes = {"Orléans", "Tours"};
    Trajet trajet1(101, 
        "2025-04-20",                        // date
        "08:00",                             // heureDepart
        "12:30",                             // heureArrivee
        "Paris",                             // lieuDepart
        "Bordeaux",                          // lieuArrivee
        segmentsPrix,                        // segmentsPrix
        villesEtapes,                        // villesEtapes
        true,                                // disponible
        false,                               // allerRetour
        true,                                // animaux
        "Peugeot 308",                       // voiture
        3,                                   // nombrePlaceDispo
        true,                                // etat
        45.7,                                // emissionCO2
        "Trajet agréable avec pause à Tours" // description
    );


    std::vector<std::pair<std::string, float>> segmentsPrix2 = {
        {"Marseille", 18.0},
        {"Valence", 9.5},
        {"Avignon", 11.0}
    };
    
    std::vector<std::string> villesEtapes2 = {"Valence", "Avignon"};
    
    Trajet trajet2(
        102,                                 // idTrajet
        "2025-04-22",                        // date
        "14:00",                             // heureDepart
        "18:00",                             // heureArrivee
        "Lyon",                              // lieuDepart
        "Marseille",                         // lieuArrivee
        segmentsPrix2,                       // segmentsPrix
        villesEtapes2,                       // villesEtapes
        true,                                // disponible
        true,                                // allerRetour
        false,                               // animaux
        "Renault Clio",                      // voiture
        2,                                   // nombrePlaceDispo
        true,                                // etat
        38.2,                                // emissionCO2
        "Départ après-midi, clim dispo, bonne ambiance garantie" // description
    );
    

    Reservation res1(25.50f, 1, true); //en cours 
    Reservation res2(15.00f, 2, false); //finie
    ali.ajouterReservation(res1);
    ali.ajouterReservation(res2);

    MesReservations vue;

    // Capture cout
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    vue.afficherReservations(ali);

    std::cout.rdbuf(old); // Reset cout

    std::string output = buffer.str(); //je recupère ce qui devait être ecrit sur le terminal

    EXPECT_NE(output.find("Paris -> Lyon"), std::string::npos);
    EXPECT_NE(output.find("Lille -> Marseille"), std::string::npos);
    EXPECT_NE(output.find("Jean"), std::string::npos);
    EXPECT_NE(output.find("Claire"), std::string::npos);
}

TEST(VueMesReservationsTest, AffichageSansReservation) {
    Passager  ali(1, "Ali", "Baba", "ali.baba@example.com", "motDePasse123", "12 rue de Paris, 75000 Paris", false);


    MesReservations vue;

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    vue.afficherReservations(ali);

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    EXPECT_NE(output.find("aucune réservation"), std::string::npos);
}
