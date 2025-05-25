#include "../Controlleur_hpp/ModifierProfilControlleur.hpp"
#include "../../Interface/Interface_hpp/ConnexionInterface.hpp"
#include "../../Interface/Interface_hpp/AccueilInterface.hpp"
#include <iostream>
#include <regex>
#include <algorithm>

void ModifierProfilControlleur::ModifierProfil(int id, std::string choix, std::string modification) {
    const std::vector<std::string> champsValides = {
        "nom", "prenom", "email", "motPasse", "adressePostale", "fumeur"
    };

    if (std::find(champsValides.begin(), champsValides.end(), choix) == champsValides.end()) {
        std::cerr << "Champ invalide pour modification : " << choix << std::endl;
        return;
    }

    // Récupère l'utilisateur depuis la base
    Utilisateur utilisateur = baseDeDonnees.getUtilisateurByID((id));

    if (choix == "nom" || choix == "prenom" || choix == "motPasse") {
        if (modification.empty()) {
            std::cerr << choix << " ne peut pas être vide." << std::endl;
            return;
        }
    }
    else if (choix == "email") {
        const std::regex emailPattern(R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");
        if (!std::regex_match(modification, emailPattern)) {
            std::cerr << "Email invalide : " << modification << std::endl;
            return;
        }
    }
    else if (choix == "adressePostale") {
        // On attend une chaîne numérique (ex. code postal)
        if (!std::all_of(modification.begin(), modification.end(), ::isdigit)) {
            std::cerr << "Adresse postale doit être un entier valide : "
                      << modification << std::endl;
            return;
        }
    }
    else if (choix == "fumeur") {
        // On attend "0" (non fumeur) ou "1" (fumeur)
        if (modification != "0" && modification != "1") {
            std::cerr << "Valeur invalide pour fumeur (doit être '0' ou '1') : "
                      << modification << std::endl;
            return;
        }
    }

    // Appliquer la modification
    if (choix == "nom") utilisateur.setNom(modification);
    else if (choix == "prenom") utilisateur.setPrenom(modification);
    else if (choix == "email") utilisateur.setEmail(modification);
    else if (choix == "motPasse") utilisateur.setMotPasse(modification);
    else if (choix == "adressePostal") utilisateur.setAdressePostale(modification);
    else if (choix == "fumeur") utilisateur.setFumeur(modification == "1");
    baseDeDonnees.modifierUtilisateur(utilisateur);
}
