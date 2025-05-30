#include "../Interface_hpp/Console_hpp/ModifierProfilConsole.hpp"
#include "../../Controlleur/Controlleur_hpp/ModifierProfilControlleur.hpp"
#include <iostream>
#include <limits>

ModifierProfilConsole::~ModifierProfilConsole() = default;

ModifierProfilConsole::ModifierProfilConsole(Database& db) : db(db)
{
}


// 1) Méthode « pure » : on reçoit tout depuis l’appelant
bool ModifierProfilConsole::modifierCoordonnees(
    const std::string& nom,
    const std::string& prenom,
    const std::string& email,
    const std::string& motPasse,
    const std::string& adressePostale,
    bool fumeur)
{
    // Demander l’ID, le champ et la nouvelle valeur
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

// 2) Version interactive qui ne prend rien en paramètre
bool ModifierProfilConsole::modifierCoordonnees()
{
    std::string nom, prenom, email, motPasse, adressePostale;
    bool fumeur = false;

    std::cout << "=== Modification de profil ===\n";
    std::cout << "Nom actuel : ";    std::getline(std::cin, nom);
    std::cout << "Prénom actuel : "; std::getline(std::cin, prenom);
    std::cout << "Email actuel : ";  std::getline(std::cin, email);
    std::cout << "Mot de passe actuel : [masqué]\n";
    std::cout << "Adresse postale actuelle : "; std::getline(std::cin, adressePostale);
    std::cout << "Fumeur (O/N) actuel : "; std::string rep; std::getline(std::cin, rep);
    fumeur = (rep == "O" || rep == "o");

    // On délègue tout de suite à la version « pure »
    return modifierCoordonnees(nom, prenom, email, motPasse, adressePostale, fumeur);
}
