#ifndef __CONNEXIONCONTROLLEUR_HPP__
#define __CONNEXIONCONTROLLEUR_HPP__

#include <string>

/**
 * @class ConnexionControlleur
 * @brief Gère la connexion des utilisateurs.
 */
class ConnexionControlleur{

private:

    /**
      * @brief Vérifie si un utilisateur existe dans la base de données.
      * @param email L'adresse e-mail de l'utilisateur.
      * @param motPasse Le mot de passe de l'utilisateur.
      */
    void verifierUtilisateur(std::string email, std::string motPasse);

};
#endif