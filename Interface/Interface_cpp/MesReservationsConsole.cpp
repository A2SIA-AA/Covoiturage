// MesReservationsConsole.cpp

#include "../Interface_hpp/Console_hpp/MesReservationsConsole.hpp"

#include <iostream>
#include <limits>

// 1) Constructeur avec injection de la base de données
MesReservationsConsole::MesReservationsConsole(Database& db)
    : db(db), controller(db)
{}

// 2) Destructeur
MesReservationsConsole::~MesReservationsConsole() = default;

// 3) Affichage (non interactif) à partir d’un Passager déjà rempli
void MesReservationsConsole::afficherReservations(const Passager& passager) {
    std::cout << "=== Vos réservations ===\n";
    auto reservations = passager.getListeReservation();
    if (reservations.empty()) {
        std::cout << "Aucune réservation trouvée.\n";
    } else {
        for (const auto& reservation : reservations) {
            std::cout << "- Réservation #"
                      << reservation.getIdReservation()
                      << " sur le trajet #"
                      << reservation.getIdTrajet()
                      << " (statut: "
                      << (reservation.getStatut() ? "confirmée" : "en attente")
                      << ")\n";
        }
    }
}

// 4) Version interactive : l’utilisateur entre son ID passager,
//    on récupère sa liste, on l’affiche, puis on peut supprimer ou revenir
void MesReservationsConsole::afficherReservations() {
    int idPassager;
    std::cout << "=== Consultation de vos réservations ===\n";
    std::cout << "Veuillez entrer votre identifiant utilisateur (passager) : ";
    std::cin >> idPassager;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // On appelle le contrôleur pour récupérer la map<Reservation,Trajet>
    std::map<Reservation, Trajet> resMap;
    try {
        resMap = controller.obtenirResvervationEtTrajetUtilisateur(idPassager);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la récupération des réservations : " << e.what() << "\n";
        return;
    }

    if (resMap.empty()) {
        std::cout << "Aucune réservation trouvée.\n";
        return;
    }

    // Construire un Passager pour utiliser la méthode d’affichage existante
    Passager passager("", "", "", "", "", false, {});
    passager.setIdUtilisateur(idPassager);
    for (const auto& pairRT : resMap) {
        passager.ajouterReservation(pairRT.first);
    }

    bool quitter = false;
    while (!quitter) {
        // 4.1) On affiche la liste
        afficherReservations(passager);

        // 4.2) On propose un sous-menu
        std::cout << "\nQue souhaitez-vous faire ?\n"
                  << "1. Supprimer une réservation\n"
                  << "2. Retour\n"
                  << "Votre choix : ";
        int choix;
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choix == 1) {
            std::cout << "Entrez l’ID de la réservation à supprimer : ";
            int idRes;
            std::cin >> idRes;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // On appelle la méthode de suppression
            supprimerReservation(idRes);

            // Après suppression, on actualise le passager en rechargeant ses réservations
            // pour que l’affichage soit à jour
            passager = Passager("", "", "", "", "", false, {});
            passager.setIdUtilisateur(idPassager);
            try {
                auto nouveauMap = controller.obtenirResvervationEtTrajetUtilisateur(idPassager);
                for (const auto& kv : nouveauMap) {
                    passager.ajouterReservation(kv.first);
                }
            } catch (...) {
                // en cas d’erreur, on sort
                std::cerr << "Erreur lors de la mise à jour des réservations.\n";
                quitter = true;
            }
        }
        else if (choix == 2) {
            quitter = true;
        }
        else {
            std::cout << "Choix invalide.\n\n";
        }
    }
}

// 5) Méthode interne : supprime la réservation (via le contrôleur)
void MesReservationsConsole::supprimerReservation(int idReservation) {
    try {
        controller.supprimerReservation(idReservation);
        std::cout << "Réservation #" << idReservation << " supprimée avec succès.\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur à la suppression : " << e.what() << "\n";
    }
}
