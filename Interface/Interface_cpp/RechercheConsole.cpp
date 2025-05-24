#include "Interface_hpp/Console_hpp/RechercheConsole.hpp"
#include <iostream>
#include <string>
#include <tuple>

void RechercheConsole::afficherMenuPrincipal() const {
    std::cout << "=== Menu principal ===" << std::endl;
    std::cout << "Pour retourner à l'accueil, appuyez sur Entrée." << std::endl;
    std::string entree;
    std::getline(std::cin, entree);
}

std::tuple<std::string, std::string, std::string> RechercheConsole::rechercher() const {
    std::string villeDepart, villeArrivee, date;

    std::cout << "=== Recherche de trajet ===" << std::endl;
    std::cout << "Lieu de départ (ou 'retour' pour l'accueil) : ";
    std::getline(std::cin, villeDepart);
    if (villeDepart == "retour") {
        afficherMenuPrincipal();
        return std::make_tuple("", "", ""); // Tuple vide pour indiquer l'annulation
    }

    std::cout << "Lieu d'arrivée : ";
    std::getline(std::cin, villeArrivee);

    std::cout << "Date de départ (ex: 2024-05-25) : ";
    std::getline(std::cin, date);

    return std::make_tuple(villeDepart, villeArrivee, date);
}
