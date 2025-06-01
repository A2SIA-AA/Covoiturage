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
#include <map>
#include "Utilisateur.hpp"
#include "Trajet.hpp"
#include "Reservation.hpp"
#include "Conducteur.hpp"
#include "Passager.hpp"

class Database {

private:
    std::string filename;
    sqlite3 *db; ///< Pointeur vers l'objet base de données SQLite
public:
    /**
 * @brief Constructeur de la classe Database.
 * @param filename Chemin du fichier SQLite à ouvrir ou créer.
 */
    explicit Database(const std::string &filename);

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
    bool execute(const std::string query);

    bool isConnected() const;

    void close();

    /**
    * @brief Initialise les tables nécessaires dans la base de données si elles n'existent pas.
    */
    void initTables();

/**
 * @ brief Ajouter un utilisateur dans la base de donnees
 * @param u un utilisateur a rajouter
 * @return vrai si il a bien etait ajouter et faux sinon
 */
    bool ajouterUtilisateur(Utilisateur u);

    /**
     * @brief Permet de récupérer un utilisateur à partir de son email et son mot de passe.
     * @param email: Adresse email de l'utilisateur.
     * @param mdp: Mot de passe.
     * @return Objet Utilisateur correspondant.
     */
    Utilisateur getUtilisateurByEmailAndMDP(std::string email, std::string mdp);

    /**
     * @brief Cette methode permet me modifier les informations d'un utilisateur dans la table quand il modifie son compte
     * @param u
     * @return vrai si la modification a reussi et faux sinon
     */
    bool modifierUtilisateur(Utilisateur u);

/**
 * @brief Ajouter un trajet dans la base de donnees
 * @param t un trajet a rajouter
 * @param idConducteur id du conducteur qui publie le trajet
 * @return vrai si il a bien etait ajouter et faux sinon
 */
    bool ajouterTrajet(Trajet t, int idConducteur);


    /**
     * @brief Ajouter une reservation a la base de donnees
     * @param r une reservation a rajouter
     * return vrai si elle a bien etait ajouter et faux sinon
     */
    bool ajouterReservation(Reservation r);

/**
 * @brief Récupère une liste de trajet connaissant sa ville de départ et d’arrivée et sa date.
 * @param villeDepart La ville de départ du trajet.
 * @param villeArrivee La ville d’arrivée du trajet.
 * @param date La date de depart du trajet
 * @return L'objet Trajet correspondant.
 */
    std::vector<Trajet>
    getTrajetByVilleDepartEtArriveeEtDateDepart(const std::string &villeDepart, const std::string &villeArrivee,
                                                const std::string &date);

/**
 *  @brief Récupère une liste de trajet connaissant sa ville de départ et d’arrivée et sa date et son prix.
 * @param villeDepart
 * @param villeArrivee
 * @param date
 * @param prix
 * @return  L'objet Trajet correspondant.
 */
    std::vector<Trajet>
    getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(const std::string &villeDepart, const std::string &villeArrivee,
                                                      const std::string &date, int prix);

/**
 * @brief Récupère un trajet connaissant sa ville de départ et d’arrivée et sa date et son emission CO2.
 * @param villeDepart
 * @param villeArrivee
 * @param date
 * @param emissionCO2
 * @return  L'objet Trajet correspondant.
 */
    std::vector<Trajet>
    getTrajetByVilleDepartEtArriveeEtEmissionCO2(const std::string &villeDepart, const std::string &villeArrivee,
                                                 const std::string &date, const float emissionCO2);

    /**
     * @brief Obtenir un trajet par son ID
     * @param idTrajet id du trajet qu'on veut obtenir
     * @return un objet Trajet correcpondant
     */
    Trajet getTrajetByIdTrajet(int idTrajet);

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
    Conducteur getConducteurByID(int idConducteur);

    /**
* @brief Récupère les informations d’un passager via son ID.
* @param idUtilisateur L’identifiant de l’utilisateur.
* @return L'objet Passager correspondant.
*/
    Passager getPassagerByID(int inPassager);


    /**
     * @brief Ajouter un point intermediaire dans le trajet
     * @param idTrajet
     * @param NomVille
     * return vrai si il a bien etait ajouter et faux sinon
     */

    bool ajouterPointIntermediaire(int idTrajet, std::string nomVille);

    /**
     * @brief Ajouter le prix d'un segment du trajet
     * @param idTrajet
     * @param prix
     * @return vrai si il a bien etait ajouter et faux sinon
     */
    bool ajouterSegmentsPrix(int idTrajet, const std::string &segment, float prix);

    /**
     * @brief Supprimer un trajet de la base de donnees
     * @param idTrajet respresente l'id du trajet qu'on veut supprimer
     */
    void supprimerTrajetByIDTrajet(int idTrajet);


    /**
     * @brief Supprimer une reservation de la base de donnees
     * @param idReservation id de la reservation à annuler
     */
    void supprimerReservationByIDReservation(int idReservation);

/**
 * @brief Cette methode permet d'obtenir un utilisateur a partir de son ID
 * @param idUtilisateur
 * @return un objet Utilisateur correspondant a l'ID
 */

    Utilisateur getUtilisateurByID(int idUtilisateur);


/*
 * Cette methode permet de verifier que le prix du trajet reservé rentré par le passager est correcte et correspond bien au trajet qu'il a choisit
 * @param idTrajet id du trajet à reserver
 * @param prix prix rentré par le passager
 * @param villeDepart ville de depart du trajet voulu
 * @param villeArrivee ville d'arrivée du trajet voulu


    bool verifierPrix(int idTrajet, float prix, const std::string& villeDepart, const std::string& villeArrivee);*/

    /**
     * Cette methode permet de retourner la liste de toutes les reservations d'un passager avec les informations des trajets de chaque reservation
     * @param idPassager id du passager qui veut voir ses reservations
     * @return une pair de reservations et trajets
     */
    std::vector<std::pair<Reservation, Trajet>> getReservationEtTrajetByIdPassager(int idPassager);

    /**
     * @brief Cette methode permet d'ajouter un conducteur à la table conducteurs
     * @param idUtilisateur
     * @return vrai si le conducteur a bien été ajouté et false sinon
     */
    bool ajouterConducteur(int idUtilisateur);

    /**
     * @brief Cette methode permet d'ajouter un passager à la table passagers
     * @param idUtilisateur
     * @return vrai si le passager a bien été ajouté et false sinon
     */
    bool ajouterPassager(int idUtilisateur);

};
#endif
