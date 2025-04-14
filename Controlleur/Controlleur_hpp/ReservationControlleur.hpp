#ifndef __RESERVATIONCONTROLLEUR_HPP__
#define __RESERVATIONCONTROLLEUR_HPP__

#include <string>
#include "Modele/Modele_hpp/Paiement.hpp"

/**
 * @class ReservationControlleur
 * @brief Gère le paiement d'un trajet.
 */
class ReservationControlleur{

public:
    /**
     * @brief Envoie une demande de paiement.
     * @param montant Le montant à payer.
     */
    void envoiePaiement(float montant);

};
#endif
