#include "../Interface_hpp/Console_hpp/MesReservationsConsole.hpp"
#include <iostream>
#include <limits>

// 1) Définition du destructeur
MesReservationsConsole::~MesReservationsConsole() = default;

// 2) Constructeur avec base de données et contrôleur
MesReservationsConsole::MesReservationsConsole(Database& db)
    : db(db), controller(db)
{
}

// 3) Affichage des réservations à partir d’un passager donné
void MesReservationsConsole::afficherReservations(const Passager& passager) {
    std::cout << "=== Vos réservations ===" << std::endl;
    auto reservations = passager.getListeReservation();
    if (reservations.empty()) {
        std::cout << "Aucune réservation trouvée." << std::endl;
    } else {
        for (const auto& reservation : reservations) {
            std::cout << "- Réservation #" << reservation.getIdReservation()
                      << " sur le trajet #" << reservation.getIdTrajet()
                      << " (statut: " << (reservation.getStatut() ? "confirmée" : "en attente") << ")" << std::endl;
        }
    }
}

// 4) Version interactive : l’utilisateur entre son ID
void MesReservationsConsole::afficherReservations() {
    int idPassager;
    std::cout << "=== Consultation de vos réservations ===" << std::endl;
    std::cout << "Veuillez entrer votre identifiant utilisateur (passager) : ";
    std::cin >> idPassager;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Récupération des réservations depuis le contrôleur
    std::map<Reservation, Trajet> reservationsMap = controller.obtenirResvervationEtTrajetUtilisateur(idPassager);

    if (reservationsMap.empty()) {
        std::cout << "Aucune réservation trouvée." << std::endl;
        return;
    }

    // Création du Passager pour compatibilité avec méthode existante
    Passager passager("", "", "", "", "", false, {});
    passager.setIdUtilisateur(idPassager);

    // Ajouter les réservations à l’objet Passager
    for (const auto& pair : reservationsMap) {
        passager.ajouterReservation(pair.first);
    }

    // Affichage via la méthode principale
    afficherReservations(passager);
}
