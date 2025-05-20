#include "../Controlleur_hpp/InscriptionControlleur.hpp"
#include "../../Interface/Interface_hpp/ConnexionInterface.hpp"
#include <regex>
#include <iostream>
#include "../../Modele/Modele_hpp/Utilisateur.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"

bool InscriptionControlleur::verifierSaisieInscription(
    std::string nom,
    std::string prenom,
    std::string email,
    std::string motPasse,
    std::string numeroTelephone,
    bool fumeur) {
    // Vérifier que tous les champs sont remplis
    if (nom.empty() || prenom.empty() || email.empty() || motPasse.empty() || numeroTelephone.empty() || (fumeur != false && fumeur != true)) {
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
    // Vérifier que le numéro de téléphone contient uniquement des chiffres
    const std::regex phonePattern(R"(^\d+$)");
    if (!std::regex_match(numeroTelephone, phonePattern)) {
        return false;
    }
    return true;
}

void InscriptionControlleur::traiterInscription(
    std::string nom,
    std::string prenom,
    std::string email,
    std::string motPasse,
    std::string numeroTelephone,
    bool fumeur) {
    if (verifierSaisieInscription(nom, prenom, email, motPasse, numeroTelephone,fumeur)) {
        Utilisateur utilisateur(nom, prenom, email, motPasse, numeroTelephone,fumeur);
        Database database;
        database.ajouterUtilisateur(utilisateur);
        std::cout << "Inscription réussie ! Vous pouvez désormais vous connecter." << std::endl;
        ConnexionInterface vue;
        vue.afficher();
    } else {
        std::cout << "Erreur lors de l'inscription : données invalides." << std::endl;
    }
}
