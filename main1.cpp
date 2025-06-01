#include "Interface/Interface_hpp/Console_hpp/InscriptionConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/ConnexionConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/AccueilConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/MesReservationsConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/MesAnnoncesConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/ModifierProfilConsole.hpp"
#include "Interface/Interface_hpp/Console_hpp/TrajetConsole.hpp"
#include "Modele/Modele_hpp/BaseDonnees.hpp"
#include "Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include <iostream>

void saisirEtAjouterTrajet(int userId, TrajetControlleur& trajetCtrl) {
    int idTrajet = userId; // Pour simplifier, on utilise l'ID de l'utilisateur
    std::string date, heureDepart, heureArrivee, lieuDepart, lieuArrivee;
    std::string voiture, description;
    float prix;
    int nbPlaces;
    float emissionCO2;
    bool disponible = true, allerRetour, animaux, etat = false;

    std::cout << "Date (AAAA-MM-JJ): "; std::getline(std::cin, date);
    std::cout << "Heure de départ (HH:MM): "; std::getline(std::cin, heureDepart);
    std::cout << "Heure d'arrivée (HH:MM): "; std::getline(std::cin, heureArrivee);
    std::cout << "Lieu de départ: "; std::getline(std::cin, lieuDepart);
    std::cout << "Lieu d'arrivée: "; std::getline(std::cin, lieuArrivee);

    std::cout << "Prix: "; std::cin >> prix; std::cin.ignore();
    std::cout << "Voiture utilisée: "; std::getline(std::cin, voiture);
    std::cout << "Nombre de places disponibles: "; std::cin >> nbPlaces; std::cin.ignore();
    std::cout << "Aller-retour ? (1: Oui, 0: Non): "; std::cin >> allerRetour; std::cin.ignore();
    std::cout << "Animaux acceptés ? (1: Oui, 0: Non): "; std::cin >> animaux; std::cin.ignore();
    std::cout << "Émissions de CO2 (g/km): "; std::cin >> emissionCO2; std::cin.ignore();
    std::cout << "Description: "; std::getline(std::cin, description);

    std::vector<std::pair<std::string, float>> segments = {{lieuDepart + " - " + lieuArrivee, prix}};
    std::vector<std::string> villesEtapes;

    if (trajetCtrl.verifierSaisieTrajet(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, segments, villesEtapes, disponible, allerRetour, animaux, voiture, nbPlaces, etat, emissionCO2, description)) {
        trajetCtrl.creerTrajet(idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, segments, villesEtapes, disponible, allerRetour, animaux, voiture, nbPlaces, etat, emissionCO2, description);
        std::cout << "Trajet crée avec succés !\n";
    } else {
        std::cout << "Erreur lors de la saisie du trajet.\n";
    }
}

int main() {
    Database db("base_test.sqlite");

    InscriptionConsole inscConsole(db);
    ConnexionConsole connConsole(db);
    bool inscrit = false, connecte = false;

    std::cout << "Bienvenue sur Insa'Volant !\n";
    std::cout << "1) S'inscrire\n2) Se connecter\nChoix : ";
    std::string choix0; std::getline(std::cin, choix0);

    if (choix0 == "1") {
        while (!inscrit) {
            inscrit = inscConsole.sInscrire();
            if (!inscrit) std::cout << "Recommencez l'inscription.\n";
        }
    }

    while (!connecte) {
        connecte = connConsole.seConnecter();
        if (!connecte) {
            std::cout << "Voulez-vous réessayer ? (O/N) : ";
            std::string rep; std::getline(std::cin, rep);
            if (rep != "O" && rep != "o") return 0;
        }
    }

    int userId = -1;
    if (connConsole.getUtilisateurConnecte().has_value()) {
        userId = connConsole.getUtilisateurConnecte().value().getIdUtilisateur();
    } else {
        std::cout << "Erreur : l'utilisateur n'a pas été correctement authentifié.\n";
        return 1;
    }


    AccueilConsole accueil;
    ModifierProfilConsole modifConsole(db);
    RechercheControlleur rechercheCtrl(db);
    TrajetControlleur trajetCtrl(db);
    MesReservationsConsole reservationsConsole(db);
    MesAnnoncesConsole annoncesConsole(db);
    TrajetConsole trajetConsole(db);

    bool quitter = false;
    while (!quitter) {
        std::string choix = accueil.accueil();
        if (choix == "1") {
            modifConsole.modifierCoordonnees();
        }
        else if (choix == "2") {
            std::string depart, arrivee, date;
            std::cout << "Ville de départ : "; std::getline(std::cin, depart);
            std::cout << "Ville d'arrivée : "; std::getline(std::cin, arrivee);
            std::cout << "Date (AAAA-MM-JJ) : "; std::getline(std::cin, date);

            auto trajets = rechercheCtrl.rechercherTrajet(depart, arrivee, date);
            trajetConsole.afficherInterfaceRecherche(trajets);
            std::cout << "Appuyez sur Entrée pour revenir au menu principal..."; std::cin.get();
        }
        else if (choix == "3") {
            reservationsConsole.afficherReservations();
        }
        else if (choix == "4") {
            auto annonces = annoncesConsole.listerAnnonces(userId);
            for (const auto& annonce : annonces) std::cout << annonce << "\n";
        }
        else if (choix == "5") {
            saisirEtAjouterTrajet(userId, trajetCtrl);
        }
        else if (choix == "6") {
            quitter = true;
        }
        else {
            std::cout << "Choix invalide.\n";
        }
    }

    std::cout << "Merci d'avoir utilisé Insa'Volant !\n";
    return 0;
}
