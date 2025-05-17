#ifndef MODIFIERPROFILCONTROLLEUR_H
#define MODIFIERPROFILCONTROLLEUR_H

#include <string>
#include <vector>
#include "Modele/Modele_hpp/BaseDonnees.hpp"

/**
 * @class ModifierProfilControlleur
 * @brief Contrôleur responsable de la modification du profil utilisateur.
 *
 * Cette classe fournit une interface pour modifier les informations du profil
 * d'un utilisateur. Elle encapsule la logique nécessaire pour effectuer cette
 * opération.
 */
class ModifierProfilControlleur {

private:
    BaseDonnees baseDeDonnees;

public:

    /**
     * @brief Modifie le profil de l'utilisateur.
     * @param id l'id de l'utilisateur qui fait la demande.
     * @param choix Une chaîne représentant l'element du profil à modifier.
     * @param modification Une chaîne représentant les nouvelles informations du profil.
     * Cette méthode permet de modifier le profil d’un utilisateur avec les
     * informations fournies dans le paramètre.
     */
    void ModifierProfil(int id, std::string choix, std::string modification);

    /**
     * @brief Redirige l'utilisateur vers "AccueilInterface" ou "ConnexionInterface" selon la modification
     * @param choix Une chaîne représentant l'element du profil à modifier.
     */
    void TraiterModificationProfil(std::string choix);
};

#endif // MODIFIERPROFILCONTROLLEUR_H
