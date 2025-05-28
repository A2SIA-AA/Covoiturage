#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include <iostream>

void TestcalculerEmission() {
    RechercheControlleur controleur;

    //Cas nominal : voiture diesel, conso moyenne normale
    float distance = 100.0f;
    std::string voiture = "diesel";
    float conso = 5.0f;
    int anciennete = 5;
    float resultat = controleur.calculerEmission(distance, voiture, conso,anciennete);
    std::cout << "Test Cas Nominal : Emission = " << resultat << " -> "
              << ((resultat > 0) ? "Réussi" : "Échoué") << std::endl;

    //Cas aux limites : distance nulle
    distance = 0.0f;
    resultat = controleur.calculerEmission(distance, voiture, conso,anciennete);
    std::cout << "Test Distance Nulle : Emission = " << resultat << " -> "
              << ((resultat == 0.0f) ? "Réussi" : "Échoué") << std::endl;

    //Cas erreur : consommation négative
    try {
        conso = -4.0f;
        resultat = controleur.calculerEmission(100.0f, voiture, conso,anciennete);
        std::cout << "Test Conso Négative : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Conso Négative : Réussi " << e.what() << std::endl;
    }
}

int main() {
    TestcalculerEmission();
    return 0;
}
