#include "../Interface_hpp/Console_hpp/ModifierProfilConsole.hpp"
#include "../../Controlleur/Controlleur_hpp/ModifierProfilControlleur.hpp"
#include <iostream>
#include <limits>

ModifierProfilConsole::~ModifierProfilConsole() = default;

ModifierProfilConsole::ModifierProfilConsole(Database& db) : db(db)
{
}



bool ModifierProfilConsole::modifierCoordonnees()
{
    int idUtilisateur;
    std::string champ, nouvelleValeur;

    std::cout << "Entrez l'ID de l'utilisateur à modifier : ";
    std::cin >> idUtilisateur;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Champ à modifier (nom, prenom, email, motPasse, adressePostale, fumeur) : ";
    std::getline(std::cin, champ);

    std::cout << "Nouvelle valeur pour " << champ << " : ";
    std::getline(std::cin, nouvelleValeur);

    // Appel au contrôleur
    try {
        ModifierProfilControlleur ctrl(db);
        ctrl.ModifierProfil(idUtilisateur, champ, nouvelleValeur);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Erreur de modification : " << e.what() << "\n";
        return false;
    }
}
