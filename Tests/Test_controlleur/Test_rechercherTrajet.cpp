#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include <iostream>
#include <string>

void TestrechercherTrajet() {
    RechercheControlleur controleur;

    // Cas nominal
    try {
        controleur.rechercherTrajet("Paris", "Lyon", "08:00", "prix");
        std::cout << "Test Cas Nominal : Réussi" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Cas Nominal : Échoué " << e.what() << std::endl;
    }

    // Cas : ville de départ vide
    try {
        controleur.rechercherTrajet("", "Lyon", "08:00", "prix");
        std::cout << "Test Ville Départ Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Ville Départ Vide : Réussi " << e.what() << std::endl;
    }

    // Cas : ville d’arrivée vide
    try {
        controleur.rechercherTrajet("Paris", "", "08:00", "prix");
        std::cout << "Test Ville Arrivée Vide : Échoué " << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Ville Arrivée Vide : Réussi " << e.what() << std::endl;
    }

    // Cas : horaire incorrect
    try {
        controleur.rechercherTrajet("Paris", "Lyon", "25:99", "prix"); // horaire non valide
        std::cout << "Test Horaire Incorrect : Échoué" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Horaire Incorrect : Réussi " << e.what() << std::endl;
    }

    // Cas : filtre vide
    try {
        controleur.rechercherTrajet("Paris", "Lyon", "10:00", "");
        std::cout << "Test Filtre Vide : Échoué" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Filtre Vide : Réussi " << e.what() << std::endl;
    }
}

int main() {
    TestrechercherTrajet();
    return 0;
}
