#include "../Interface_hpp/Console_hpp/ConnexionConsole.hpp"
#include "../../Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include <iostream>
#include <optional>

// 1) Définition du destructeur (même s’il est default dans le header)
ConnexionConsole::~ConnexionConsole() = default;

// 2) Implémentation de la méthode pure virtuelle
bool ConnexionConsole::seConnecter(const std::string& email,
                                   const std::string& motDePasse)
{
    // On peut soit refactorer une version "console" qui prend email/motDePasse
    // en argument, soit déléguer à la version interactive.
    // Ici on fait simple : on appelle le contrôleur directement :
    Database db("maBase.sqlite");
    ConnexionControlleur controller(db);
    auto utilisateur = controller.verifierUtilisateur(email, motDePasse);
    if (utilisateur) {
        std::cout << "Connexion réussie !" << std::endl;
        return true;
    } else {
        std::cout << "Connexion échouée : email ou mot de passe incorrect." << std::endl;
        return false;
    }
}

// 3) Votre version interactive
bool ConnexionConsole::seConnecter()
{
    std::string email, motDePasse;
    std::cout << "=== Connexion ===\nEmail : ";
    std::getline(std::cin, email);
    std::cout << "Mot de passe : ";
    std::getline(std::cin, motDePasse);
    return seConnecter(email, motDePasse);
}
