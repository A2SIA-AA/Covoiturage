#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../../Interface/Interface_hpp/TrajetInterface.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"


TEST(TrajetInterfaceTest, CasNominal_AffichageDePlusieursTrajets) {
    TrajetInterface interface;
    std::vector<Trajet> trajets;

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
    

    trajets.emplace_back(trajet1);
    trajets.emplace_back(trajet2);

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    interface.afficherInterfaceRecherche(trajets);

    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    EXPECT_NE(output.find("Paris"), std::string::npos);
    EXPECT_NE(output.find("Bordeaux"), std::string::npos);
    EXPECT_NE(output.find("08:00"), std::string::npos);
    EXPECT_NE(output.find("12:30"), std::string::npos);
    EXPECT_NE(output.find("3"), std::string::npos);
    EXPECT_NE(output.find("Lyon"), std::string::npos);
    EXPECT_NE(output.find("Marseille"), std::string::npos);
    EXPECT_NE(output.find("14:00"), std::string::npos);
    EXPECT_NE(output.find("18:00"), std::string::npos);
    EXPECT_NE(output.find("2"), std::string::npos);

}

TEST(TrajetInterfaceTest, CasLimite_AucunTrajetTrouve) {
    TrajetInterface interface;
    std::vector<Trajet> trajets; // vide

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    interface.afficherInterfaceRecherche(trajets);

    std::cout.rdbuf(oldCout);
    std::string output = buffer.str();
    EXPECT_NE(output.find("Aucun trajet trouvé"), std::string::npos);
}


