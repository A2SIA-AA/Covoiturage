#include "../Interface_hpp/Console_hpp/InscriptionConsole.hpp"
#include "../../Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include <iostream>
#include <stdexcept>

// 1) définition du destructeur
InscriptionConsole::~InscriptionConsole() = default;

// 2) implémentation de la méthode pure virtuelle
bool InscriptionConsole::sInscrire(const std::string& nom,
                                   const std::string& prenom,
                                   const std::string& email,
                                   const std::string& motPasse,
                                   const std::string& adressePostale,
                                   bool fumeur)
{
    Database db("maBase.sqlite");
    InscriptionControlleur controller(db);

    // Vérification de la saisie
    if (!controller.verifierSaisieInscription(nom, prenom, email, motPasse, adressePostale, fumeur)) {
        std::cout << "Erreur lors de l'inscription : données invalides.\n";
        return false;
    }

    // Traitement de l'inscription
    try {
        controller.traiterInscription(nom, prenom, email, motPasse, adressePostale, fumeur);
        std::cout << "Inscription réussie !\n";
        return true;
    } catch (const std::runtime_error& e) {
        std::cout << "Échec de l'inscription : " << e.what() << "\n";
        return false;
    }
}

// 3) version interactive qui pose les questions à l'utilisateur
bool InscriptionConsole::sInscrire()
{
    std::string nom, prenom, email, motPasse, adressePostale;
    bool fumeur = false;

    std::cout << "=== Inscription ===\n";
    std::cout << "Nom : ";            std::getline(std::cin, nom);
    std::cout << "Prénom : ";         std::getline(std::cin, prenom);
    std::cout << "Email : ";          std::getline(std::cin, email);
    std::cout << "Mot de passe : ";   std::getline(std::cin, motPasse);
    std::cout << "Adresse postale : ";std::getline(std::cin, adressePostale);
    std::cout << "Fumeur (O/N) : ";
    std::string choix; std::getline(std::cin, choix);
    fumeur = (choix == "O" || choix == "o");

    return sInscrire(nom, prenom, email, motPasse, adressePostale, fumeur);
}
