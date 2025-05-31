#include "../Controlleur_hpp/InscriptionControlleur.hpp"
#include "../../Interface/Interface_hpp/Console_hpp/ConnexionConsole.hpp"
#include <regex>
#include <iostream>
#include "../../Modele/Modele_hpp/Utilisateur.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../Interface/Interface_hpp/Console_hpp/InscriptionConsole.hpp"

bool InscriptionControlleur::verifierSaisieInscription(
    std::string nom,
    std::string prenom,
    std::string email,
    std::string motPasse,
    std::string adressePostal,
    bool fumeur) {
    // Vérifier que tous les champs sont remplis
    if (nom.empty() || prenom.empty() || email.empty() || motPasse.empty() || adressePostal.empty() || (fumeur != false && fumeur != true)) {
        return false;
    }
    // Vérification basique du format d'email
    const std::regex emailPattern(
    R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");

    if (!std::regex_match(email, emailPattern)) {
        return false;
    }
    // Longueur minimale du mot de passe
    if (motPasse.length() < 6) {
        return false;
    }
    return true;
}

void InscriptionControlleur::traiterInscription(
    std::string nom,
    std::string prenom,
    std::string email,
    std::string motPasse,
    std::string adressePostale,
    bool fumeur) {
    if (!verifierSaisieInscription(nom, prenom, email, motPasse, adressePostale, fumeur)) {
        throw std::runtime_error("Erreur lors de l'inscription : données invalides.");
    }

    Utilisateur utilisateur(nom, prenom, email, motPasse, adressePostale, fumeur);

    if (!baseDeDonnees.ajouterUtilisateur(utilisateur)) {
        throw std::runtime_error("Erreur : impossible d'ajouter l'utilisateur en base.");
    }
    std::cout << "Inscription réussie ! Vous pouvez désormais vous connecter." << std::endl;
    //InscriptionConsole vue;
    //vue.sInscrire(nom, prenom, email,telephone, motPasse);
}
