/**
 * @class Database
 * @brief Gère la connexion à la base de données SQLite et les opérations associées (Créer, Lire, Mettre à jour, et Supprimer une donnée).
 *
 *  Cette classe permet la création des tables, l'ajout et la récupération des entités métier telles que
 * les utilisateurs, les trajets, les réservations, les avis, les conducteurs et les passagers.
 *
 * Toutes les opérations s'appuient sur une base SQLite accessible via la bibliothèque `sqlite3`.
 */
#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Utilisateur.hpp"
#include "Trajet.hpp"
#include "Avis.hpp"
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
* @brief Ajoute un nouvel utilisateur à la base de données.
* @param nom Nom de l'utilisateur.
* @param prenom Prénom de l'utilisateur.
* @param email Adresse email.
* @param mdp Mot de passe.
* @param adressePostale Adresse postale complète.
* @param fumer booléen Indiquant si l'utilisateur est fumeur.
*/
    void ajouterUtilisateur(std::string nom, std::string prenom, std::string email, std::string mdp, std::string adressePostale, bool fumer);

    /**
     * @brief Permet de récupérer un utilisateur à partir de son email et son mot de passe.
     * @param email: Adresse email de l'utilisateur.
     * @param mdp: Mot de passe.
     * @return Objet Utilisateur correspondant.
     */
    Utilisateur getUtilisateurByEmailAndMDP(std::string email, std::string mdp);
    /**
* @brief Ajoute un trajet à la base de données avec ses informations données.
* @param idTrajet L'identifiant du trajet.
* @param date La date de départ du trajet.
* @param heureDepart L'heure du départ du trajet.
* @param heureArrivee L'heure du départ du trajet.
* @param lieuDepart La ville du départ du trajet
* @param lieuArrivee La ville d'arrivée.
* @param segmentsPrix Liste des segments du trajet avec leurs prix associés.
* @param villesEtapes Liste des villes étapes entre le départ et l’arrivée.
* @param disponible Un boleen qui indique si le trajet est actuellement disponible à la réservation.
* @param allerRetour Bollen qui précise si le trajet admet un retour.
* @param animaux Boleen indiquant si les animaux sont autorisés pendant le trajet.
* @param voiture Description du véhicule utilisé pour le trajet.
* @param nombrePlaceDispo Nombre de places disponibles dans la voiture
* @param etat État indiquant si le trajet est déjà passé ou bien c'est à venir.
* @param emissionCO2 Estimation des émissions de CO2 pour ce trajet.
* @param description Informations supplémentaires sur le trajet à ajouter (description libre)
*/
    void ajouterTrajet(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);
    /**
 * @brief Ajoute une réservation à la base de données.
 * @param prix Prix payé.
 * @param ID Identifiant de la réservation.
 * @param statut Statut de la réservation (acceptée ou refusée).
 */
    void ajouterReservation(float prix, int ID, bool statut);
    /**
* @brief Ajoute un avis à propos d'un trajet.
* @param note Note attribuée (1-5).
* @param commentaire Commentaire écrit.
* @param typeAvis Précise si c'est un avis laissé ou bien un avis reçu.
*/
    void ajouterAvis(int note, std::string commentaire, std::string typeAvis);
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
* @brief Récupère un avis lié à un trajet.
* @param IDTrajet L’identifiant du trajet.
* @return L'objet Avis associé au trajet.
*/
    Avis getAvisByIdTrajet(int IDTrajet);
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
     * Cette methode permet d'avoir le nom de la personne qui a laisse un avis et le nom de la personne a qui il a laisse l'avis
     * @param idTrajet
     * @return le couple des noms de l'emetteur et du recepteur d'un avis
     */
    std::pair<std::string, std::string> getNomsEmetteurEtRecepteurAvisParTrajet(int idTrajet);




};

#endif
