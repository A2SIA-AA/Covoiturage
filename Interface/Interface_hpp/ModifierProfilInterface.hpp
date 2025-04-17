#ifndef MODIFIERPROFILINTERFACE_HPP
#define MODIFIERPROFILINTERFACE_HPP

#include "AccueilInterface.hpp"
#include <string>

/**
 * @file ModifierProfilInterface.hpp
 * @brief Interface graphique pour la modification du profil utilisateur.
 */
class ModifierProfilInterface : public AccueilInterface {
public:
    /**
     * @brief Affiche l'interface de modification et soumet les nouvelles informations du profil utilisateur.
     * @param nom Nouveau nom de l'utilisateur.
     * @param prenom Nouveau prénom de l'utilisateur.
     * @param email Nouvel email de l'utilisateur.
     * @param telephone Nouveau numéro de téléphone de l'utilisateur.
     * @return true si la modification a réussi, false sinon.
     */
    virtual bool modifierCoordonnees(const std::string& nom,
                                     const std::string& prenom,
                                     const std::string& email,
                                     const std::string& telephone) = 0;

    virtual ~ModifierProfilInterface() = default;
};

#endif // MODIFIERPROFILINTERFACE_HPP
