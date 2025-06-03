#ifndef MODIFIERPROFILINTERFACE_HPP
#define MODIFIERPROFILINTERFACE_HPP

#include <string>

/**
 * @file ModifierProfilInterface.hpp
 * @brief Interface graphique pour la modification du profil utilisateur.
 */
class ModifierProfilInterface {
public:
    /**
     * @brief Affiche l'interface de modification et soumet les nouvelles informations du profil utilisateur.
     * @param nom Nouveau nom de l'utilisateur.
     * @param prenom Nouveau prénom de l'utilisateur.
     * @param email Nouvel email de l'utilisateur.
     * @param motPasse Le mot de passe de l'utilisateur.
     * @param adressePostale L'adresse postale de l'utilisateur.
     * @param fumeur Indique si l'utilisateur est fumeur.
     * @return true si la modification a réussi, false sinon.
     */
    virtual bool modifierCoordonnees() = 0;

    /**
     * @brief Détruit l'instance de ModifierProfilInterface.
     *
     * Cette méthode virtuelle par défaut permet une gestion appropriée de la destruction
     * des instances de classes dérivées lorsque manipulées via un pointeur de type base.
     */
    virtual ~ModifierProfilInterface() = default;
};

#endif // MODIFIERPROFILINTERFACE_HPP
