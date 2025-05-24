#include "Interface_hpp/Console_hpp/InscriptionConsole.hpp"
#include "../Controlleur_hpp/InscriptionControlleur.hpp"
#include <iostream>
#include <string>

bool InscriptionConsole::sInscrire(const std::string& /*nom*/, const std::string& /*prenom*/,
                                   const std::string& /*email*/, const std::string& /*motPasse*/,
                                   const std::string& /*adressePostale*/, bool /*fumeur*/) {
    std::string nom, prenom, email, motPasse, adressePostale;
    bool fumeur;

    std::cout << "=== Inscription ===" << std::endl;
    std::cout << "Nom : ";
    std::getline(std::cin, nom);

    std::cout << "Prénom : ";
    std::getline(std::cin, prenom);

    std::cout << "Email : ";
    std::getline(std::cin, email);

    std::cout << "Mot de passe : ";
    std::getline(std::cin, motPasse);

    std::cout << "Adresse postale (rue, code postal, ville) : ";
    std::getline(std::cin, adressePostale);

    std::cout << "Fumeur (O/N) : ";
    std::string choixFumeur;
    std::getline(std::cin, choixFumeur);
    fumeur = (choixFumeur == "O" || choixFumeur == "o");

    InscriptionControlleur controlleur;

    // On vérifie la saisie avec le contrôleur
    if (controlleur.verifierSaisieInscription(nom, prenom, email, motPasse, adressePostale, fumeur)) {
        try {
            controlleur.traiterInscription(nom, prenom, email, motPasse, adressePostale, fumeur);
            return true;
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return false;
        }
    } else {
        std::cout << "Erreur lors de l'inscription : données invalides." << std::endl;
        return false;
    }
}