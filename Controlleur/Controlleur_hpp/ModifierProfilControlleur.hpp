#ifndef MODIFIERPROFILCONTROLLEUR_H
#define MODIFIERPROFILCONTROLLEUR_H

#include <string>
#include <vector>
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "BaseControlleur.hpp"

/**
 * @class ModifierProfilControlleur
 * @brief Contrôleur responsable de la modification du profil utilisateur.
 */
class ModifierProfilControlleur : public BaseControlleur{


public:

    /**
    * @brief Constructeur implicite à partir de la base de données.
    * @param db Référence à l'objet Database partagé.
    */
    explicit ModifierProfilControlleur(Database& db)
        : BaseControlleur(db)
    {
    }

    /**
     * @brief Modifie le profil de l'utilisateur.
     * @param id l'id de l'utilisateur qui fait la demande.
     * @param choix Une chaîne représentant l'element du profil à modifier.
     * @param modification Une chaîne représentant les nouvelles informations du profil.
     * Cette méthode permet de modifier le profil d’un utilisateur avec les
     * informations fournies dans le paramètre.
     */
    void ModifierProfil(int id, std::string choix, std::string modification);
};

#endif // MODIFIERPROFILCONTROLLEUR_H
