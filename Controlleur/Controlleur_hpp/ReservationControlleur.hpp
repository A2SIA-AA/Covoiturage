#ifndef __RESERVATIONCONTROLLEUR_HPP__
#define __RESERVATIONCONTROLLEUR_HPP__

#include <string>
#include "Modele/Modele_hpp/Paiement.hpp"

/**
 * @class Reservation
 * @brief Gère la réservation et le paiement d'un trajet.
 */
class Reservation{
private:
    /**
     * @brief Envoie une demande de paiement.
     * @param montant Le montant à payer.
     */
    void envoiePaiement(float montant);

    /**
     * @brief Crée un paiement pour la réservation.
     * @param idPaiement Identifiant unique du paiement.
     * @param montant Montant du paiement.
     * @param datePaiement Date du paiement sous forme de chaîne de caractères.
     * @return Un objet de type Paiement contenant les informations du paiement.
     */
    Paiement creerPaiement(int idPaiement, float montant, std::string datePaiement );


    /**
     * @brief Crée une nouvelle réservation.
     * @param prix Le prix total de la réservation.
     * @param idReservation L'identifiant unique de la réservation.
     * @param statut Statut de la réservation (Accepté, refusé).
     * @return Un objet de type Reservation avec les détails de la réservation.
     */
    Reservation creerReservation(float prix, int idReservation, bool statut);
};
#endif
