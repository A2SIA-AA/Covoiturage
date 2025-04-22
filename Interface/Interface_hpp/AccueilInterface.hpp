#ifndef ACCUEILINTERFACE_HPP
#define ACCUEILINTERFACE_HPP

#include "MesAnnoncesInterface.hpp"
#include "MesReservationsInterface.hpp"
#include "ModifierProfilInterface.hpp"
#include "RechercheInterface.hpp"
#include "ReservationInterface.hpp"
#include "TrajetInterface.hpp"

/**
 * @file AccueilInterface.hpp
 * @brief Interface graphique pour la page d'accueil utilisateur.
 *
 * Cette interface permet de rediriger les actions principales vers les interfaces spécialisées.
 */
class AccueilInterface {
public:
    virtual ~AccueilInterface() = default;

    /**
     * @brief Accède à l'interface de recherche de trajets.
     */
    virtual RechercheInterface* getRechercheInterface() = 0;

    /**
     * @brief Accède à l'interface de réservation.
     */
    virtual ReservationInterface* getReservationInterface() = 0;

    /**
     * @brief Accède à l'interface de modification du profil.
     */
    virtual ModifierProfilInterface* getModifierProfilInterface() = 0;

    /**
     * @brief Accède à l'interface de consultation des réservations (passager).
     */
    virtual MesReservationsInterface* getMesReservationsInterface() = 0;

    /**
     * @brief Accède à l'interface de consultation des annonces (conducteur).
     */
    virtual MesAnnoncesInterface* getMesAnnoncesInterface() = 0;

    /**
     * @brief Accède à l'interface de saisie d'un nouveau trajet (conducteur).
     */
    virtual TrajetInterface* getTrajetInterface() = 0;

};

#endif // ACCUEILINTERFACE_HPP

