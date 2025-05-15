#include "../Controlleur_hpp/InscriptionControlleur.hpp"
#include "../../Interface/Interface_hpp/ConnexionInterface.hpp"
#include <regex>
#include <iostream>

bool InscriptionControlleur::verifierSaisieInscription(
    std::string nom,
    std::string prenom,
    std::string email,
    std::string motPasse,
    std::string numeroTelephone) {
    // Vérifier que tous les champs sont remplis
    if (nom.empty() || prenom.empty() || email.empty() || motPasse.empty() || numeroTelephone.empty()) {
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
    std::string numeroTelephone) {
    if (verifierSaisieInscription(nom, prenom, email, motPasse, numeroTelephone)) {
        std::cout << "Inscription réussie ! Vous pouvez désormais vous connecter." << std::endl;
        ConnexionInterface vue;
        vue.afficher();
    } else {
        std::cout << "Erreur lors de l'inscription : données invalides." << std::endl;
    }
}
