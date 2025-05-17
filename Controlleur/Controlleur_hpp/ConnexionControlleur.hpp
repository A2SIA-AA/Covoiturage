#ifndef __CONNEXIONCONTROLLEUR_HPP__
#define __CONNEXIONCONTROLLEUR_HPP__

#include <string>
#include "Modele/Modele_hpp/BaseDonnees.hpp"

/**
 * @class ConnexionControlleur
 * @brief Gère la connexion des utilisateurs.
 */
class ConnexionControlleur{

private:
    BaseDonnees baseDeDonnees;

public:

    /**
    * @brief Vérifie si un utilisateur existe dans la base de données et si le mot de passe est correct.
    * @param email L'adresse e-mail de l'utilisateur.
    * @param motPasse Le mot de passe de l'utilisateur.
    */
    void verifierUtilisateur(std::string email, std::string motPasse);

    /**
    * @brief Traite la connexion d'un utilisateur (si la connexion s'est bien passé, on le renvoie à "AccueilInterface")
    * @param email L'adresse e-mail de l'utilisateur.
    * @param motPasse Le mot de passe de l'utilisateur.
    */
    void traiterConnexion(std::string email, std::string motPasse);

};
#endif