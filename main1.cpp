#include "Interface/Interface_hpp/Console_hpp/InscriptionConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/ConnexionConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/AccueilConsole.hpp"
#include "Modele/Modele_hpp/BaseDonnees.hpp"
#include <iostream>

#include "Interface/Interface_hpp/Console_hpp/ModifierProfilConsole.hpp"

int main() {
    Database db("maBase.sqlite");

    // 1) Inscription ou connexion
    InscriptionConsole inscConsole;
    ConnexionConsole connConsole;
    bool inscrit = false;
    bool connecte = false;

    std::cout << "Bienvenue sur Insa'Volant !\n";
    std::cout << "1) S'inscrire\n"
                 "2) Se connecter\n"
                 "Choix : ";
    std::string choix0;
    std::getline(std::cin, choix0);

    if (choix0 == "1") {
        // boucle tant que l’inscription échoue
        while (!inscrit) {
            inscrit = inscConsole.sInscrire();
            if (!inscrit) std::cout << "Recommencez l'inscription.\n";
        }
        // après inscription, on retombe sur la connexion
    }

    // connexion (boucle jusqu’à réussite ou quitte)
    while (!connecte) {
        connecte = connConsole.seConnecter();
        if (!connecte) {
            std::cout << "Voulez-vous réessayer ? (O/N) : ";
            std::string rep; std::getline(std::cin, rep);
            if (rep != "O" && rep != "o") {
                std::cout << "Au revoir !\n";
                return 0;
            }
        }
    }

    // 2) Affichage du menu principal
    AccueilConsole accueil;
    ModifierProfilConsole modifConsole;
    bool quitter = false;
    while (!quitter) {
        std::string choix = accueil.accueil();
        if (choix == "1") {
            if (!modifConsole.modifierCoordonnees()) {
                std::cout << "La modification a échoué.\n";
            } else {
                std::cout << "Profil mis à jour avec succès.\n";
            }
        }
        else if (choix == "2") {
            std::cout << "[À implémenter] Recherche de trajet\n";
        }
        else if (choix == "3") {
            std::cout << "[À implémenter] Mes réservations\n";
        }
        else if (choix == "4") {
            std::cout << "[À implémenter] Mes annonces\n";
        }
        else if (choix == "5") {
            quitter = true;
        }
        else {
            std::cout << "Choix non reconnu, réessayez.\n";
        }
    }

    std::cout << "Merci d'avoir utilisé Insa'Volant, à bientôt ! \n";
    return 0;
}
