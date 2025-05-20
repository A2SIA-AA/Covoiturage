#include "Interface_hpp/InscriptionConsole.hpp"
#include "../Controlleur_hpp/InscriptionControlleur.hpp"
#include <iostream>

bool InscriptionConsole::sInscrire(const std::string& /*nom*/, const std::string& /*prenom*/,
                                   const std::string& /*email*/, const std::string& /*telephone*/,
                                   const std::string& /*motDePasse*/) {
    std::string nom, prenom, email, telephone, motDePasse;

    std::cout << "=== Inscription ===" << std::endl;
    std::cout << "Nom : ";
    std::getline(std::cin, nom);

    std::cout << "Prénom : ";
    std::getline(std::cin, prenom);

    std::cout << "Email : ";
    std::getline(std::cin, email);

    std::cout << "Téléphone : ";
    std::getline(std::cin, telephone);

    std::cout << "Mot de passe : ";
    std::getline(std::cin, motDePasse);

    InscriptionControlleur controlleur;

    // On vérifie la saisie avec le contrôleur
    if (controlleur.verifierSaisieInscription(nom, prenom, email, motDePasse, telephone)) {
        controlleur.traiterInscription(nom, prenom, email, motDePasse, telephone);
        return true;
    }
    std::cout << "Erreur lors de l'inscription : données invalides." << std::endl;
    return false;
}
