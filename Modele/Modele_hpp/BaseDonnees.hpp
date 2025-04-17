/**
 * @class Database
 * @brief Gère la connexion à la base de données SQLite et les opérations associées (Créer, Lire, Mettre à jour, et Supprimer une donnée).
 *
 *  Cette classe permet la création des tables, l'ajout et la récupération des entités métier telles que
 * les utilisateurs, les trajets, les réservations, les conducteurs et les passagers.
 *
 * Toutes les opérations s'appuient sur une base SQLite accessible via la bibliothèque `sqlite3`.
 */
#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Utilisateur.hpp"
#include "Trajet.hpp"
#include "Paiement.hpp"
#include "Reservation.hpp"
#include "Conducteur.hpp"
#include "Passager.hpp"

class Database {

private: sqlite3* db; ///< Pointeur vers l'objet base de données SQLite
public:
    /**
 * @brief Constructeur de la classe Database.
 * @param filename Chemin du fichier SQLite à ouvrir ou créer.
 */
    Database(const std::string& filename);

    /**
     * @brief Destructeur de la classe Database.
     * Ferme la connexion à la base de données.
     */
    ~Database();

    /**
     * @brief Exécute une requête SQL arbitraire.
     * @param query Requête SQL à exécuter.
     * @return true si la requête a réussi, false sinon.
     */
    bool execute(const std::string& query);
    /**
* @brief Initialise les tables nécessaires dans la base de données si elles n'existent pas.
*/
    void initTables();
    /**
     * Ajouter un utilisateur a la base de donnees
     * @param u un utilisateur a rajouter
     */
    void ajouterUtilisateur(Utilisateur u);

    /**
     * @brief Permet de récupérer un utilisateur à partir de son email et son mot de passe.
     * @param email: Adresse email de l'utilisateur.
     * @param mdp: Mot de passe.
     * @return Objet Utilisateur correspondant.
     */
    Utilisateur getUtilisateurByEmailAndMDP(std::string email, std::string mdp);
/**
 * Ajouter un trajet a la base de donnees
 * @param t un trajet a rajouter
 */
    void ajouterTrajet(Trajet t);



    /**
     * Ajouter une reservation a la base de donnees
     * @param r une reservation a rajouter
     */
    void ajouterReservation(Reservation r);

/**
 * @brief Récupère un trajet connaissant sa ville de départ et d’arrivée et sa date.
 * @param villeDepart La ville de départ du trajet.
 * @param villeArrivee La ville d’arrivée du trajet.
 * @param date La date de depart du trajet
 * @return L'objet Trajet correspondant.
 */
    Trajet getTrajetByVilleDepartEtArriveeEtDateDepart(std::string villeDepart, std::string villeArrivee,std::string date);

/**
 * Récupère un trajet connaissant sa ville de départ et d’arrivée et sa date et son prix.
 * @param villeDepart
 * @param villeArrivee
 * @param date
 * @param prix
 * @return  L'objet Trajet correspondant.
 */
    Trajet getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(std::string villeDepart, std::string villeArrivee,std::string date, int prix);

/**
 * Récupère un trajet connaissant sa ville de départ et d’arrivée et sa date et son emission CO2.
 * @param villeDepart
 * @param villeArrivee
 * @param date
 * @param emissionCO2
 * @return  L'objet Trajet correspondant.
 */
    Trajet getTrajetByVilleDepartEtArriveeEtEmissionCO2(std::string villeDepart, std::string villeArrivee,std::string date, float emissionCO2);



    /**
* @brief Récupère une réservation par son ID.
* @param ID L'identifiant de la réservation.
* @return L'objet Reservation correspondant.
*/
    Reservation getReservationByID(int ID);
    /**
* @brief Récupère les émissions de CO2 d’un trajet donné.
* @param IDTrajet L’identifiant du trajet.
* @return La quantité de CO2 émise.
*/
    float getEmissionCO2ByIdTrajet(int IDTrajet);
    /**
* @brief Récupère les prix par segment pour un trajet donné.
* @param IDTrajet L’identifiant du trajet.
* @return Un vecteur de paires <ville, prix>.
*/
    std::vector<std::pair<std::string, float>> getPrixByIdTrajet(int idTrajet);
    /**
* @brief Récupère les villes étapes d’un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return Les noms de villes étapes du trajet.
*/
    std::vector<std::string> getPointIntermediaireByIdTrajet(int IDTrajet);
    /**
* @brief Récupère la date de départ d’un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return La date du départ du trajet correspondant.
*/
    std::string getDateDepatByIdTrajet(int IDTrajet);
    /**
* @brief Récupère la date d’arrivée d’un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return La date d'arrivée du trajet correspondant.
*/
    std::string getDateArriveeByIdTrajet(int IDTrajet);
    /**
* @brief Récupère l’heure d’arrivée d’un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return L'heure d'arrivée du trajet correspondant.
*/
    std::string getHeureArriveeByIdTrajet(int IDTrajet);

    /**
     * @brief Récupère l’heure de départ d’un trajet.
     * @param IDTrajet L’identifiant du trajet.
     * @return  L'heure de départ du trajet indiqué.
     */
    std::string getHeureDepartByIdTrajet(int IDTrajet);
    /**
* @brief Récupère la ville d’arrivée d’un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return Le nom de la ville d’arrivée.
*/
    std::string getVilleArriveeByIdTrajet(int IDTrajet);
    /**
* @brief Récupère la ville de départ d’un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return Le nom de la ville de départ.
*/
    std::string getVilleDepartByIdTrajet(int IDTrajet);

    /**
* @brief Récupère les informations d’un conducteur via son ID.
* @param idUtilisateur L’identifiant de l’utilisateur.
* @return L'objet Conducteur correspondant.
*/
    Conducteur getConducteurByID(int idUtilisateur);
    /**
* @brief Récupère les informations d’un passager via son ID.
* @param idUtilisateur L’identifiant de l’utilisateur.
* @return L'objet Passager correspondant.
*/
    Passager getPassagerByID(int idUtilisateur);



    /**
     * Ajouter un point intermediaire dans le trajet
     * @param idTrajet
     * @param NomVille
     */

    void ajouterPointIntermediaire(int idTrajet, std::string nomVille);
};

#endif
