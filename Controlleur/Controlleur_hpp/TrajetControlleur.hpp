#ifndef __TRAJETCONTROLLEUR_HPP__
#define __TRAJETCONTROLLEUR_HPP__

#include <string>
#include <vector>
#include "Modele/Modele_hpp/Trajet.hpp"

/**
 * @class TrajetControlleur
 * @brief Gère la gestion des trajets et les réservations associées.
 */
class TrajetControlleur{

public:
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
    void verifierSaisie(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);

    /**
     * @brief Effectue une réservation pour un trajet donné.
     * @param trajet Le trajet à réserver.
     * @param nom Nom du passager.
     * @param prenom Prénom du passager.
     * @param email Adresse e-mail du passager.
     * @param numeroTelephone Numéro de téléphone du passager.
     */
    void reservation(Trajet trajet, std::string nom, std::string prenom, std::string email, int numeroTelephone);

    /**
     * @brief Retourne un trajet spécifique.
     * @return Un objet de type Trajet contenant les détails du trajet.
     */
    Trajet obtenirTrajet();

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
    void creerTrajet(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, enum etat, float emissionCO2, std::string description);


};
#endif