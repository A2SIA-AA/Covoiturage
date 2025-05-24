#ifndef __TRAJETCONTROLLEUR_HPP__
#define __TRAJETCONTROLLEUR_HPP__

#include <string>
#include <vector>
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../Modele/Modele_hpp/Reservation.hpp"

/**
 * @class TrajetControlleur
 * @brief Gère la gestion des trajets et les réservations associées.
 */
class TrajetControlleur{

private:

    Database& baseDeDonnees;


public:
    TrajetControlleur(Database& db) : baseDeDonnees(db) {}
    /**
     * @brief Vérifie que toutes les informations du trajet sont valides.
     * @param idTrajet Identifiant unique du trajet.
     * @param date Date du trajet ().
     * @param heureDepart Heure de départ ().
     * @param heureArrivee Heure d'arrivée ().
     * @param lieuDepart Lieu de départ du trajet.
     * @param lieuArrivee Lieu d'arrivée du trajet.
     * @param segmentsPrix Liste des segments du trajet avec leur prix associé.
     * @param villesEtapes Liste des villes étapes du trajet.
     * @param disponible Indique si le trajet est disponible pour réservation.
     * @param allerRetour Indique si le trajet est un aller-retour.
     * @param animaux Indique si les animaux sont acceptés.
     * @param voiture Modèle du véhicule utilisé.
     * @param nombrePlaceDispo Nombre de places disponibles.
     * @param etat Indique si le trajet est a venir ou passé.
     * @param emissionCO2 Niveau d'émission de CO2 du trajet.
     * @param description Description supplémentaire du trajet.
     */
    bool verifierSaisieTrajet(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);

    /**
     * @brief Effectue une réservation pour un trajet spécifique.
     *
     * Cette fonction permet d'enregistrer une réservation pour un trajet identifié par son ID.
     * @param idTrajet Identifiant du trajet à réserver.
     * @param prix Prix de la réservation.
     * @param idPassager Identifiant unique du passager.
     * @param statut Statut de la réservation (true si confirmée, false sinon).
     */
    void reservation(int idTrajet, float prix, int idPassager, bool statut);

        /**
     * @brief Recherche les trajets correspondant aux critères spécifiés.
     *
     * Cette méthode permet de récupérer tous les trajets qui correspondent à un
     * lieu de départ, un lieu d'arrivée et une date donnés. Elle est utile pour
     * permettre aux utilisateurs de consulter les trajets disponibles selon leurs besoins.
     *
     * @param lieuDepart Le lieu de départ des trajets recherchés.
     * @param lieuArrivee Le lieu d'arrivée des trajets recherchés.
     * @param date La date des trajets (format : AAAA-MM-JJ).
     * @return Un vecteur de trajets (`std::vector<Trajet>`) correspondant aux critères.
     *         Le vecteur peut être vide s’il n’existe aucun trajet correspondant.
     */
    std::vector<Trajet> obtenirTrajets(std::string lieuDepart, std::string lieuArrivee, std::string date);

    /**
         * @brief Crée un nouveau trajet avec les informations fournies.
         * @param idTrajet Identifiant unique du trajet.
         * @param date Date du trajet (format: AAAA-MM-JJ).
         * @param heureDepart Heure de départ (format: HH:MM).
         * @param heureArrivee Heure d'arrivée (format: HH:MM).
         * @param lieuDepart Lieu de départ du trajet.
         * @param lieuArrivee Lieu d'arrivée du trajet.
         * @param segmentsPrix Liste des segments du trajet avec leur prix associé.
         * @param villesEtapes Liste des villes étapes du trajet.
         * @param disponible Indique si le trajet est disponible pour réservation.
         * @param allerRetour Indique si le trajet est un aller-retour.
         * @param animaux Indique si les animaux.
         * @param voiture Modèle du véhicule utilisé.
         * @param nombrePlaceDispo Nombre de places disponibles.
         * @param etat Indique si le trajet est passée  ou à venir .
         * @param emissionCO2 Niveau d'émission de CO2 du trajet.
         * @param description Description supplémentaire du trajet.
         */
    void creerTrajet(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);

    /**
     * @brief Supprime un trajet qu'un conducteur a posté
     * @param idTrajet ID du trajet à supprimer
     */
    void supprimerTrajet(int idTrajet);

    /**
     * @brief Supprime une réservation qu'un passager à effectuer
     * @param idReservation ID de la réservation à supprimer
     */
    void supprimerReservation(int idReservation);

    /**
     * @brief Redirige l'utilisateur vers "TrajetInterface"
     */
    void TraiterTrajet();


};
#endif