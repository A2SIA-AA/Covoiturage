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
     * @param motPasse Le mot de passe de l'utilisateur.
     * @param adressePostale L'adresse postale de l'utilisateur.
     * @param fumeur Indique si l'utilisateur est fumeur.
     * @return bool Retourne true si l'inscription réussit, false sinon.
     */
    virtual bool sInscrire(const std::string& nom,
                           const std::string& prenom,
                           const std::string& email,
                           const std::string& motPasse,
                           const std::string& adressePostale,
                           bool fumeur) = 0;

    virtual ~InscriptionInterface() = default;
};

#endif // INSCRIPTION_INTERFACE_HPP
