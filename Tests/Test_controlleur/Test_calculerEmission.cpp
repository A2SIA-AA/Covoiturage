#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include <iostream>

void TestcalculerEmission() {
    Database db(":memory:");
    RechercheControlleur controleur(db);

    //Cas nominal : voiture diesel, conso moyenne normale
    float distance = 100.0f;
    std::string voiture = "diesel";
    float conso = 5.0f;
    int anciennete = 5;
    float resultat = controleur.calculerEmission(distance, "diesel", conso,anciennete);
    std::cout << "Test Cas Nominal : Emission = " << resultat << " -> "
              << ((resultat > 0) ? "Réussi" : "Échoué") << std::endl;

    //Cas aux limites : distance nulle
    distance = 0.0f;
    resultat = controleur.calculerEmission(distance, "diesel", conso,anciennete);
    std::cout << "Test Distance Nulle : Emission = " << resultat << " -> "
              << ((resultat == 0.0f) ? "Réussi" : "Échoué") << std::endl;

    //Cas erreur : consommation négative
    conso = -4.0f;
    resultat = controleur.calculerEmission(100.0f, "diesel", conso,anciennete);

    std::cout << "Test Conso Négative " << resultat << " -> "
          << ((resultat <= 0.0f) ? "Réussi" : "Échoué") << std::endl;
}

int main() {
    TestcalculerEmission();
    return 0;
}
