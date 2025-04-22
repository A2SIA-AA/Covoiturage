#ifndef ACCUEILINTERFACE_HPP
#define ACCUEILINTERFACE_HPP

#include <string>

/**
 * @file AccueilInterface.hpp
 * @brief Interface pour la page d'accueil utilisateur.
 *
 * Cette interface permet de rediriger les actions principales vers les interfaces spécialisées à l'aide des contrôleurs.
 * L'utilisateur choisit l'interface vers laquelle il souhaite aller, cette information est transmise aux contrôleurs qui effectuent ensuite le traitement nécessaire.
 */
class AccueilInterface {
public:
    virtual ~AccueilInterface() = default;

    /**
     * @brief Affiche l'accueil et retourne le choix de l'utilisateur.
     * @return Le choix de l'utilisateur sous forme de chaîne de caractères.
     */
    virtual std::string accueil() = 0;
};

#endif // ACCUEILINTERFACE_HPP
