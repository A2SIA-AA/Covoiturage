#ifndef MES_RESERVATIONS_HPP
#define MES_RESERVATIONS_HPP

#include "../../Modele/Modele_hpp/Passager.hpp"

/**
 * @class MesReservationsInterface
 * @brief Cette classe permet l'affichage des réservations du passager connecté.
 */
class MesReservationsInterface {
public:
    /**
     * @brief Affiche toutes les réservations du passager connecté.
     * @param passager L’utilisateur connecté dont on veut afficher les réservations.
     */
    virtual void afficherReservations(const Passager& passager) = 0 ;

    /**
     * @brief Destructeur virtuel de la classe MesReservationsInterface.
     *
     * Ce destructeur est défini pour permettre la suppression polymorphique correcte
     * des objets dérivés de cette interface.
     */
    virtual ~MesReservationsInterface() = default;

};

#endif
