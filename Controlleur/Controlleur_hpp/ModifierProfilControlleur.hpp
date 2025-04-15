#ifndef MODIFIERPROFILCONTROLLEUR_H
#define MODIFIERPROFILCONTROLLEUR_H

#include <string>
#include <vector>

/**
 * @class ModifierProfilControlleur
 * @brief Contrôleur responsable de la modification du profil utilisateur.
 *
 * Cette classe fournit une interface pour modifier les informations du profil
 * d'un utilisateur. Elle encapsule la logique nécessaire pour effectuer cette
 * opération.
 */
class ModifierProfilControlleur {

public:

    /**
     * @brief Modifie le profil de l'utilisateur.
     * @param nouveauProfil Une chaîne représentant les nouvelles informations du profil.
     *
     * Cette méthode permet de modifier le profil d’un utilisateur avec les
     * informations fournies dans le paramètre.
     */
    void ModifierProfil(std::string nouveauProfil);
};

#endif // MODIFIERPROFILCONTROLLEUR_H
