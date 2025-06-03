/**
* @file InscriptionConsole.hpp
 * @brief Déclaration de la classe InscriptionConsole pour la gestion des inscriptions via la console.
 *
 * Cette classe dérive de InscriptionInterface et permet d’assurer la création d’un nouvel utilisateur
 * en réceptionnant les informations saisies depuis une interface en ligne de commande.
 * Elle exploite une référence à la base de données et fait appel à un contrôleur dédié pour
 * la logique d'inscription.
 */
#ifndef INSCRIPTIONCONSOLE_HPP
#define INSCRIPTIONCONSOLE_HPP

#include "../InscriptionInterface.hpp"
#include <string>

#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../../Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
/**
 * @class InscriptionConsole
 * @brief Permet l’inscription d’un nouvel utilisateur via la console.
 *
 * Gère la collecte des données utilisateur et interagit avec la couche contrôleur pour réaliser l’inscription
 * dans la base de données.
 */
class InscriptionConsole : public InscriptionInterface {
private:
    Database& db;
    InscriptionControlleur controller;

public:
    /**
 * @brief Constructeur prenant en paramètre une référence à la base de données.
 * @param dbRef La base de données dans laquelle inscrire les utilisateurs.
 */

    explicit InscriptionConsole(Database& dbRef)
        : db(dbRef), controller(dbRef) {}

    /**
 * @brief Lance le processus d’inscription interactif via la console.
 * @return true si l’inscription réussit, false sinon.
 */

    bool sInscrire();

    /**
 * @brief Destructeur virtuel par défaut.
 */

    ~InscriptionConsole() override = default;

    /**
 * @brief Implémente l'interface pour inscrire un utilisateur avec toutes ses informations.
 * @param nom Nom de l'utilisateur.
 * @param prenom Prénom de l'utilisateur.
 * @param email Adresse e-mail de l'utilisateur.
 * @param motPasse Mot de passe choisi.
 * @param adressePostale Adresse postale de l'utilisateur.
 * @param fumeur Indique si l'utilisateur est fumeur.
 * @return true si l'inscription a réussi, false sinon.
 */

    bool sInscrire(const std::string& nom,
                   const std::string& prenom,
                   const std::string& email,
                   const std::string& motPasse,
                   const std::string& adressePostale,
                   bool fumeur) override;

};

#endif // INSCRIPTIONCONSOLE_HPP
