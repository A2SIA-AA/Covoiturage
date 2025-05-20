#include "../Controlleur_hpp/ModifierProfilControlleur.hpp"
#include "../../Interface/Interface_hpp/ConnexionInterface.hpp"
#include "../../Interface/Interface_hpp/AccueilInterface.hpp"
#include <iostream>
#include <regex>
#include <algorithm>

void ModifierProfilControlleur::ModifierProfil(int id, std::string choix, std::string modification) {
    const std::vector<std::string> champsValides = {
        "nom", "prenom", "email", "motPasse", "adressePostal", "fumeur"
    };

    if (std::find(champsValides.begin(), champsValides.end(), choix) == champsValides.end()) {
        std::cerr << "Champ invalide pour modification : " << choix << std::endl;
        return;
    }

    if (choix == "nom" || choix == "prenom") {
        if (modification.empty()) {
            std::cerr << choix << " ne peut pas être vide." << std::endl;
            return;
        }
    } else if (choix == "email") {
        const std::regex emailPattern(R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");
        if (!std::regex_match(modification, emailPattern)) {
            std::cerr << "Email invalide : " << modification << std::endl;
            return;
        }
    } else if (choix == "adressePostal") {
        if (!std::all_of(modification.begin(), modification.end(), ::isdigit)) {
            std::cerr << "Adresse postale doit être un entier valide : " << modification << std::endl;
            return;
        }
    } else if (choix == "fumeur") {
        if (modification != "0" && modification != "1") {
            std::cerr << "Valeur invalide pour fumeur (doit être '0' ou '1') : " << modification << std::endl;
            return;
        }
    }

    // Pas de validation pour motPasse ici, tu peux en ajouter si besoin

    baseDeDonnees.mettreAJourChampProfil(id, choix, modification);
}
