#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <tuple>
#include "../../Interface/Interface_hpp/RechercheInterface.hpp"

class RechercheInterfaceTest : public ::testing::Test {
    protected:
        void setInput(const std::string& input) {
            inputStream.str(input);                 // injecte le texte dans le flux
            inputStream.clear();                    // réinitialise le statut du flux
            std::cin.rdbuf(inputStream.rdbuf());    // redirige std::cin vers le flux simulé
        }
    
        std::istringstream inputStream; // flux simulé
    };
    


TEST_F(RechercheInterfaceTest, rechercher_CasNominal) {
    RechercheInterface interface;
    setInput("1\nParis\nLyon\n2025-06-01\n");

    auto [depart, arrivee, date] = interface.rechercher();

    EXPECT_EQ(depart, "Paris");
    EXPECT_EQ(arrivee, "Lyon");
    EXPECT_EQ(date, "2025-06-01");
}

TEST_F(RechercheInterfaceTest, rechercher_RetourAccueil) {
    RechercheInterface interface;
    setInput("0\n");

    auto [depart, arrivee, date] = interface.rechercher();

    EXPECT_EQ(depart, "");
    EXPECT_EQ(arrivee, "");
    EXPECT_EQ(date, "");
}


TEST_F(RechercheInterfaceTest, Recherche_ChampsVides) {
    RechercheInterface interface;
    setInput("1\n\n\n\n");

    auto [depart, arrivee, date] = interface.rechercher();

    EXPECT_EQ(depart, "");
    EXPECT_EQ(arrivee, "");
    EXPECT_EQ(date, "");
}
