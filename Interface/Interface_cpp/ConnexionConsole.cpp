#include "Interface_hpp/Console_hpp/ConnexionConsole.hpp"

#include "../Controlleur_hpp/ConnexionControlleur.hpp" // Inclure le contrôleur
#include <iostream>
#include <optional>

bool ConnexionConsole::seConnecter(const std::string& /*email*/, const std::string& /*motDePasse*/) {
    std::string email, motDePasse;

    std::cout << "=== Connexion ===" << std::endl;
    std::cout << "Email : ";
    std::getline(std::cin, email);

    std::cout << "Mot de passe : ";
    std::getline(std::cin, motDePasse);

    // Création du contrôleur (attention : il faut que la classe ait un constructeur par défaut)
    Database db("maBase.sqlite");
    ConnexionControlleur controlleur(db);

    // Appel du contrôleur pour vérifier l'utilisateur
    std::optional<Utilisateur> utilisateur = controlleur.verifierUtilisateur(email, motDePasse);

    if (utilisateur) {
        std::cout << "Connexion réussie !" << std::endl;
        return true;
    } else {
        std::cout << "Connexion échouée : email ou mot de passe incorrect." << std::endl;
        return false;
    }
}