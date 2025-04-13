#ifndef ACCUEIL_INTERFACE_HPP
#define ACCUEIL_INTERFACE_HPP

#include <string>

/**
 * @file AccueilInterface.hpp
 * @brief Interface pour la gestion du profil utilisateur.
 */
class AccueilInterface {
public:
    /**
     * @brief Méthode pour modifier les informations du profil utilisateur :  Cette méthode permet à un utilisateur authentifié de modifier ses informations personnelles.
     * @param nom Le nouveau nom de l'utilisateur.
     * @param prenom Le nouveau prénom de l'utilisateur.
     * @param email La nouvelle adresse email de l'utilisateur.
     * @param telephone Le nouveau numéro de téléphone de l'utilisateur.
     * @return bool Retourne true si la mise à jour réussit, false sinon.
     */
    virtual bool modifierCoordonnees(const std::string& nom, const std::string& prenom,
                                 const std::string& email, const std::string& telephone) = 0;
};

#endif // ACCUEIL_INTERFACE_HPP
