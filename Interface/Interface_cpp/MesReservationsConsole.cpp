#include "../Interface_hpp/Console_hpp/MesReservationsConsole.hpp"
#include <iostream>
#include <limits>

// 1) Définition du destructeur
MesReservationsConsole::~MesReservationsConsole() = default;

// 2) Implémentation de la méthode pure virtuelle
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

// 3) Version interactive qui pose les questions à l'utilisateur
void MesReservationsConsole::afficherReservations() {
    // On suppose que tu as un moyen de récupérer le Passager connecté (par exemple via un ID)
    // Ici, on va demander l'ID du passager à l’utilisateur pour simuler la connexion

    int idPassager;
    std::cout << "=== Consultation de vos réservations ===" << std::endl;
    std::cout << "Veuillez entrer votre identifiant utilisateur (passager) : ";
    std::cin >> idPassager;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Exemple de récupération du Passager (à adapter selon ton modèle)
    // Database db("maBase.sqlite");
    // Passager passager = db.getPassagerByID(idPassager);
    // Si tu n’as pas cette méthode, il faut l’ajouter ou adapter la logique

    // Pour l’exemple, on crée un Passager vide (à remplacer par ta logique)
    // (Dans la vraie application, il faut récupérer le Passager dans la base ou le service)
    Passager passager("", "", "", "", "", false, {});
    passager.setIdUtilisateur(idPassager); // Si tu as un setter pour l’ID (sinon, il faut l’ajouter ou adapter)

    // Ici, il faudrait récupérer les réservations du passager depuis la base de données
    // Exemple : std::vector<Reservation> reservations = db.getReservationsByPassagerId(idPassager);
    // passager.setListeReservation(reservations);

    // Appel à la méthode principale
    afficherReservations(passager);
}
