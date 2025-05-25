#ifndef BASE_CONTROLLEUR_HPP
#define BASE_CONTROLLEUR_HPP

#include "../../Modele/Modele_hpp/BaseDonnees.hpp"

/**
 * @class BaseControlleur
 * @brief Classe de base pour tous les contrôleurs, fournit l'accès à la base de données.
 */
class BaseControlleur {
protected:
    Database& baseDeDonnees;

public:
    /**
     * @brief Constructeur de la classe de base.
     * @param db Référence à l'objet Database partagé.
     */
    explicit BaseControlleur(Database& db) : baseDeDonnees(db) {}

    // empêcher l'utilisation du constructeur par défaut sans DB
    BaseControlleur() = delete;
    virtual ~BaseControlleur() = default;
};

#endif // BASE_CONTROLLEUR_HPP