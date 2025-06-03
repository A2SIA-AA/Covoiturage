// MesReservationsConsole.hpp

#ifndef MESRESERVATIONSCONSOLE_HPP
#define MESRESERVATIONSCONSOLE_HPP

#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../MesReservationsInterface.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"

/**
 * @brief Classe permettant de gérer et d'afficher les réservations d'un passager via une interface console.
 *
 * MesReservationsConsole hérite de MesReservationsInterface et implémente les fonctionnalités spécifiques
 * pour afficher les réservations associées à un passager, supprimer des réservations,
 * et fournir une interaction utilisateur via la console.
 */
class MesReservationsConsole : public MesReservationsInterface {
public:
    /**
     * @brief Constructeur de la classe MesReservationsConsole.
     *
     * Ce constructeur initialise la classe avec une référence vers la base de données centrale du système.
     * Il permet ainsi d'accéder aux données des réservations, des trajets et des passagers lors des opérations
     * effectuées dans cette interface console.
     *
     * @param db Référence vers l'objet Database utilisé pour interagir avec les données.
     */

    explicit MesReservationsConsole(Database& db);

    /**
     * @brief Destructeur de la classe MesReservationsConsole.
     *
     * Garantit la libération correcte des éventuelles ressources allouées par cette classe.
     */

    ~MesReservationsConsole() override;

    /**
 * @brief Affiche la liste des réservations du passager spécifié.
 *
 * Cette méthode permet d'afficher, dans la console, toutes les réservations associées à un objet Passager passé en paramètre.
 * Elle récupère la liste des réservations pour ce passager et affiche les détails de chacune.
 *
 * @param passager Le passager pour lequel afficher les réservations.
 */

    void afficherReservations(const Passager& passager) override;

    /**
     * @brief Affichage interactif des réservations pour l'utilisateur courant.
     *
     * Demande à l'utilisateur de saisir son identifiant, affiche la liste de ses réservations,
     * puis permet de supprimer une réservation à partir de son identifiant ou de retourner au menu principal.
     * Gère l'interaction complète avec l'utilisateur via la console.
     */

    void afficherReservations();

private:
    Database& db;
    TrajetControlleur controller;

    /**
 * @brief Supprime une réservation à partir de son identifiant.
 *
 * Cette méthode supprime, via la base de données et le contrôleur associé, la réservation correspondant
 * à l'identifiant fourni. L'opération met à jour la base de données en conséquence.
 *
 * @param idReservation Identifiant de la réservation à supprimer.
 */

    void supprimerReservation(int idReservation);
};

#endif // MESRESERVATIONSCONSOLE_HPP
