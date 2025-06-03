#ifndef CONNEXION_INTERFACE_HPP
#define CONNEXION_INTERFACE_HPP

#include <string>

/**
 * @file ConnexionInterface.hpp
 * @brief Interface pour la connexion des utilisateurs.
 */
class ConnexionInterface {
public:
    /**
     * @brief Méthode pour connecter un utilisateur : Cette méthode doit vérifier les informations d'identification de l'utilisateur et établir une session si les informations sont valides.
     * @param email L'adresse email de l'utilisateur.
     * @param motDePasse Le mot de passe de l'utilisateur.
     * @return bool Retourne true si la connexion réussit, false sinon.
     */
    virtual bool seConnecter(const std::string& email, const std::string& motDePasse) = 0;

    /**
     * @brief Destructeur virtuel par défaut : Permet la destruction correcte et propre des objets dérivés via un pointeur vers la classe de base.
     */
    virtual ~ConnexionInterface() = default;
};

#endif // CONNEXION_INTERFACE_HPP
