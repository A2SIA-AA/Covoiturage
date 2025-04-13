#ifndef INSCRIPTION_INTERFACE_HPP
#define INSCRIPTION_INTERFACE_HPP

#include <string>

/**
 * @file InscriptionInterface.hpp
 * @brief Interface pour l'inscription de nouveaux utilisateurs.
 */
class InscriptionInterface {
public:
    /**
     * @brief Méthode pour inscrire un nouvel utilisateur : Cette méthode doit prendre les informations nécessaires pour créer un nouveau compte utilisateur et l'enregistrer dans le système.
     * @param nom Le nom de l'utilisateur.
     * @param prenom Le prénom de l'utilisateur.
     * @param email L'adresse email de l'utilisateur.
     * @param telephone Le numéro de téléphone de l'utilisateur.
     * @param motDePasse Le mot de passe de l'utilisateur.
     * @return bool Retourne true si l'inscription réussit, false sinon.
     */
    virtual bool sInscrire(const std::string& nom, const std::string& prenom,
                             const std::string& email, const std::string& telephone,
                             const std::string& motDePasse) = 0;
};

#endif // INSCRIPTION_INTERFACE_HPP
