#ifndef MES_RESERVATIONS_HPP
#define MES_RESERVATIONS_HPP

#include "../../Modele/Modele_hpp/Passager.hpp"

/**
 * @class MesReservations
 * @brief Cette classe permet l'affichage des réservations du passager connecté.
 */
class MesReservations {
public:
    /**
     * @brief Affiche toutes les réservations du passager connecté.
     * @param passager L’utilisateur connecté dont on veut afficher les réservations.
     */
    void afficherReservations(const Passager& passager);
};

#endif
