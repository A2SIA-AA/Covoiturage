#include "../Interface_hpp/Console_hpp/TrajetConsole.hpp"
#include "../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

// 1) Définition du destructeur
TrajetConsole::~TrajetConsole() = default;

// 2) Implémentation de la méthode pure virtuelle (interface)
void TrajetConsole::afficherTrajets(const std::vector<Trajet>& trajets) {
    if (trajets.empty()) {
        std::cout << "Aucun trajet trouvé." << std::endl;
        return;
    }
    for (const auto& trajet : trajets) {
        std::cout << "Trajet #" << trajet.getIdTrajet()
                  << " : " << trajet.getLieuDepart()
                  << " -> " << trajet.getLieuArrive()
                  << " le " << trajet.getDate()
                  << " à " << trajet.getHeureDepart()
                  << " (places: " << trajet.getNombrePlaceDispo() << ")"
                  << " (prix: " << trajet.getPrixTotal() << " €)"
                  << std::endl;
    }
}

// 3) Version interactive qui pose les questions à l'utilisateur
void TrajetConsole::afficherTrajets() {
    // Exemple d'interactivité : demande à l'utilisateur s'il veut voir les trajets
    std::cout << "Voulez-vous afficher les trajets ? (O/N) ";
    char choix;
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choix == 'O' || choix == 'o') {
        // Ici, il faudrait récupérer la liste des trajets (par exemple depuis un contrôleur)
        // Pour l'exemple, on suppose qu'on a reçu la liste ailleurs
        // afficherTrajets(trajets); // À remplacer par la liste réelle
        std::cout << "Aucune liste de trajets fournie. Utilisez la version avec paramètre." << std::endl;
    }
}

// 2) Implémentation de la méthode pure virtuelle (interface)
void TrajetConsole::afficherMenuFiltres() {
    std::cout << "=== Menu de filtres ===" << std::endl;
    std::cout << "1. Trier par prix croissant" << std::endl;
    std::cout << "2. Trier par durée croissante" << std::endl;
    std::cout << "3. Trier par émissions de CO2 croissantes" << std::endl;
    std::cout << "4. Trier par heure de départ croissante" << std::endl;
    std::cout << "5. Trier par nombre de points intermédiaires" << std::endl;
    std::cout << "6. Retour à la liste des trajets" << std::endl;
}


// 2) Implémentation de la méthode pure virtuelle (interface)
void TrajetConsole::afficherFiltrage(const std::vector<Trajet>& trajets) {
    Database db("maBase.sqlite");
    RechercheControlleur ctrl(db);
    int choix;
    std::cout << "Choisissez un filtre : ";
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Trajet> resultats;
    switch (choix) {
        case 1: resultats = ctrl.comparerPrix(trajets); break;
        case 2: resultats = ctrl.comparerDuree(trajets); break;
        case 3: resultats = ctrl.comparerEmission(trajets); break;
        case 4: resultats = ctrl.comparerHeureDepart(trajets); break;
        case 5: resultats = ctrl.comparerPointIntermediaire(trajets); break;
        case 6: return; // Retour à la liste
        default: std::cout << "Choix invalide." << std::endl; return;
    }
    afficherTrajets(resultats);
}

// 3) Version interactive qui pose les questions à l'utilisateur
void TrajetConsole::afficherFiltrage() {
    // Exemple d'interactivité : demande la liste des trajets à l'utilisateur
    // (dans la vraie application, la liste est fournie par le contrôleur)
    std::cout << "Veuillez fournir la liste des trajets à filtrer." << std::endl;
    // afficherFiltrage(trajets); // À remplacer par la liste réelle
    std::cout << "Aucune liste de trajets fournie. Utilisez la version avec paramètre." << std::endl;
}

// 2) Implémentation de la méthode pure virtuelle (interface)
void TrajetConsole::afficherMenuPrincipal() {
    std::cout << "=== Menu principal ===" << std::endl;
    std::cout << "Pour retourner à l'accueil, appuyez sur Entrée." << std::endl;
    std::string entree;
    std::getline(std::cin, entree);
}


// 2) Implémentation de la méthode pure virtuelle (interface)
void TrajetConsole::afficherDetailsTrajet(const Trajet& trajet) {
    std::cout << "=== Détails du trajet ===" << std::endl;
    std::cout << "ID: " << trajet.getIdTrajet() << std::endl;
    std::cout << "Date: " << trajet.getDate() << std::endl;
    std::cout << "Heure départ: " << trajet.getHeureDepart() << std::endl;
    std::cout << "Heure arrivée: " << trajet.getHeureArrive() << std::endl;
    std::cout << "Lieu départ: " << trajet.getLieuDepart() << std::endl;
    std::cout << "Lieu arrivée: " << trajet.getLieuArrive() << std::endl;
    std::cout << "Voiture: " << trajet.getVoiture() << std::endl;
    std::cout << "Places disponibles: " << trajet.getNombrePlaceDispo() << std::endl;
    std::cout << "Prix total: " << trajet.getPrixTotal() << " €" << std::endl;
    std::cout << "Émissions CO2: " << trajet.getEmissionCO2() << " kg" << std::endl;
    std::cout << "Description: " << trajet.getDescription() << std::endl;

    std::cout << "Voulez-vous réserver ce trajet ? (O/N) ";
    char choix;
    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choix == 'O' || choix == 'o') {
        int idPassager;
        std::cout << "Entrez votre ID utilisateur (passager) : ";
        std::cin >> idPassager;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        float prix = trajet.getPrixTotal();
        Database db("maBase.sqlite");
        TrajetControlleur ctrl(db);
        ctrl.reservation(trajet.getIdTrajet(), prix, idPassager, true);
    }
}

// 3) Version interactive qui pose les questions à l'utilisateur
void TrajetConsole::afficherDetailsTrajet() {
    int idTrajet;
    std::cout << "Entrez l’ID du trajet à détailler : ";
    std::cin >> idTrajet;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Ici, il faudrait récupérer le trajet depuis la base de données ou la liste fournie
    // Pour l'exemple, on suppose qu'on a un trajet
    // afficherDetailsTrajet(trajet); // À remplacer par le trajet réel
    std::cout << "Aucun trajet fourni. Utilisez la version avec paramètre." << std::endl;
}

// 2) Implémentation de la méthode pure virtuelle (interface)
void TrajetConsole::afficherInterfaceRecherche(const std::vector<Trajet>& trajets) {
    if (trajets.empty()) {
        std::cout << "Aucun trajet trouvé. Retour au menu principal." << std::endl;
        afficherMenuPrincipal();
        return;
    }

    bool continuer = true;
    while (continuer) {
        afficherTrajets(trajets);
        afficherMenuFiltres();
        int choix;
        std::cout << "Choisissez une action : ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choix) {
            case 1: case 2: case 3: case 4: case 5:
                afficherFiltrage(trajets);
                break;
            case 6:
                continuer = false;
                break;
            default:
                std::cout << "Choix invalide." << std::endl;
                break;
        }
    }

    // Optionnel : proposer de voir les détails d’un trajet
    std::cout << "Voulez-vous voir les détails d’un trajet ? (O/N) ";
    char choixDetail;
    std::cin >> choixDetail;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choixDetail == 'O' || choixDetail == 'o') {
        int idTrajet;
        std::cout << "Entrez l’ID du trajet : ";
        std::cin >> idTrajet;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        auto it = std::find_if(trajets.begin(), trajets.end(),
            [idTrajet](const Trajet& t) { return t.getIdTrajet() == idTrajet; });
        if (it != trajets.end()) {
            afficherDetailsTrajet(*it);
        } else {
            std::cout << "Trajet non trouvé." << std::endl;
        }
    }

    afficherMenuPrincipal();
}

// 3) Version interactive qui pose les questions à l'utilisateur
void TrajetConsole::afficherInterfaceRecherche() {
    // Exemple d'interactivité : demande les critères de recherche à l'utilisateur
    std::cout << "=== Recherche de trajets ===" << std::endl;
    std::string villeDepart, villeArrivee, date;
    std::cout << "Lieu de départ : ";
    std::getline(std::cin, villeDepart);
    std::cout << "Lieu d'arrivée : ";
    std::getline(std::cin, villeArrivee);
    std::cout << "Date de départ (ex: 2024-05-25) : ";
    std::getline(std::cin, date);

    // Ici, il faudrait utiliser le contrôleur pour récupérer les trajets
    // Par exemple :
     Database db("maBase.sqlite");
     TrajetControlleur ctrl(db);
     std::vector<Trajet> trajets = ctrl.obtenirTrajets(villeDepart, villeArrivee, date);
     afficherInterfaceRecherche(trajets);

    // Pour l'exemple, on affiche un message
    std::cout << "Aucune liste de trajets fournie. Utilisez la version avec paramètre." << std::endl;
}
