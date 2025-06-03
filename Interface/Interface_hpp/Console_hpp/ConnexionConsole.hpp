/**
* @file ConnexionConsole.hpp
 * @brief Déclaration de la classe ConnexionConsole, permettant la gestion de la connexion via la console.
 *
 * Cette classe hérite de ConnexionInterface et fournit une implémentation concrète pour la connexion utilisateur
 * à travers une interface console.
 * Elle référence un objet Database qui permet l'accès aux données utilisateurs,
 * stocke localement l'utilisateur actuellement connecté grâce à un std::optional,
 * et utilise un contrôleur de connexion pour gérer la logique métier.
 */
#ifndef CONNEXIONCONSOLE_HPP
#define CONNEXIONCONSOLE_HPP

#include <string>

#include "../../../Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include "../ConnexionInterface.hpp"
#include "../../../Modele/Modele_hpp/Utilisateur.hpp"
/**
 * @class ConnexionConsole
 * @brief Gère la connexion d'un utilisateur depuis la console.
 *
 * La classe ConnexionConsole offre les fonctionnalités nécessaires pour tenter une connexion
 * avec saisie des identifiants par la console. Elle permet d’accéder à l'utilisateur connecté
 * et d'interagir avec une base de données via le contrôleur de connexion.
 */

class ConnexionConsole : public ConnexionInterface {

public:
    Database& db;
    std::optional<Utilisateur> utilisateurConnecte;
    ConnexionControlleur controller;

    /**
     * @brief Tente de connecter un utilisateur via ses identifiants.
     * @param email Adresse e-mail de l'utilisateur.
     * @param motDePasse Mot de passe de l'utilisateur.
     * @return true si la connexion a réussi, false sinon.
     */

    bool seConnecter(const std::string& email,
                     const std::string& motDePasse) override;

    /**
 * @brief Tente de connecter un utilisateur en saisissant les informations via la console.
 * @return true si la connexion a réussi, false sinon.
 */

    bool seConnecter();

    /**
     * @brief Destructeur virtuel.
     */

    ~ConnexionConsole() override;
    /**
 * @brief Retourne l'utilisateur actuellement connecté, s'il existe.
 * @return std::optional<Utilisateur>
 */

    std::optional<Utilisateur> getUtilisateurConnecte() const { return utilisateurConnecte; }

    /**
 * @brief Constructeur de la classe ConnexionConsole.
 * @param db Référence vers la base de données à utiliser pour la connexion.
 */

    explicit ConnexionConsole(Database& db) : db(db), controller(db)
    {
    }
};


#endif // CONNEXIONCONSOLE_HPP
