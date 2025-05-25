#ifndef __CONNEXIONCONTROLLEUR_HPP__
#define __CONNEXIONCONTROLLEUR_HPP__
#include <optional>

#include <string>

#include "BaseControlleur.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"

/**
 * @class ConnexionControlleur
 * @brief Gère la connexion des utilisateurs.
 */
class ConnexionControlleur : public BaseControlleur{

public:

    /**
     * @brief Constructeur implicite à partir de la base de données.
     * @param db Référence à l'objet Database partagé.
     */
    explicit ConnexionControlleur(Database& db)
        : BaseControlleur(db)
    {
    }

    /**private:
    Database& baseDeDonnees;
    * @brief Vérifie si un utilisateur existe dans la base de données et si le mot de passe est correct.
    * @param email L'adresse e-mail de l'utilisateur.
    * @param motPasse Le mot de passe de l'utilisateur.
    * @return l'utlisateur si il est present sinon un nulopt
    */
    std::optional<Utilisateur> verifierUtilisateur(std::string email, std::string motPasse);

    /**
    * @brief Traite la connexion d'un utilisateur (si la connexion s'est bien passé, on le renvoie à "AccueilInterface")
    * @param email L'adresse e-mail de l'utilisateur.
    * @param motPasse Le mot de passe de l'utilisateur.
    */
    void traiterConnexion(std::string email, std::string motPasse);

};
#endif