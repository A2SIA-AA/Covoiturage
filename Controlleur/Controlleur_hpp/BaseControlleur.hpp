#ifndef BASE_CONTROLLEUR_HPP
#define BASE_CONTROLLEUR_HPP

#include "../../Modele/Modele_hpp/BaseDonnees.hpp"

/**
 *
 */
class BaseControlleur {
protected:
    Database& baseDeDonnees;

public:
    /**
     * @brief Constructeur explicit de la classe BaseControlleur utilisant une base de données.
     *
     * Empêche l'initialisation de l'objet sans fournir une référence à un objet Database.
     *
     * @param db Référence à un objet Database utilisé pour l'initialisation.
     */
    explicit BaseControlleur(Database& db) : baseDeDonnees(db) {}


    BaseControlleur() = delete;

    /**
     * @brief Destructeur virtuel par défaut de la classe BaseControlleur.
     *
     * Permet la destruction adéquate des objets dérivés tout en garantissant la libération
     * correcte des ressources associées à la classe de base.
     */
    virtual ~BaseControlleur() = default;
};

#endif // BASE_CONTROLLEUR_HPP