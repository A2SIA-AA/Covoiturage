#include "../Interface_hpp/Console_hpp/RechercheConsole.hpp"
#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include <iostream>
#include <string>
#include <tuple>


RechercheConsole::~RechercheConsole() = default;

// 1) Méthode « pure » : on reçoit tout depuis l’appelant
std::tuple<std::string, std::string, std::string>
RechercheConsole::rechercher(const std::string& villeDepart,
                             const std::string& villeArrivee,
                             const std::string& date)
{
    try {
        Database db("maBase.sqlite");
        RechercheControlleur ctrl(db);
        std::vector<Trajet> resultats = ctrl.rechercherTrajet(villeDepart, villeArrivee, date);
        // (Normalement, c'est la TrajetInterface qui affiche les résultats, donc on ne fait rien ici)
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la recherche : " << e.what() << "\n";
    }
    // On retourne le tuple avec les critères saisis
    return std::make_tuple(villeDepart, villeArrivee, date);
}

// 2) Version interactive qui ne prend rien en paramètre
std::tuple<std::string, std::string, std::string> RechercheConsole::rechercher() const
{
    std::string villeDepart, villeArrivee, date;

    std::cout << "=== Recherche de trajet ===\n";
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

    // On délègue tout de suite à la version « pure »
    return rechercher(villeDepart, villeArrivee, date);
}

void RechercheConsole::afficherMenuPrincipal() const
{
    std::cout << "=== Menu principal ===\n";
    std::cout << "Pour retourner à l'accueil, appuyez sur Entrée.\n";
    std::string entree;
    std::getline(std::cin, entree);
}
