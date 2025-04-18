#ifndef RECHERCHE_INTERFACE_HPP
#define RECHERCHE_INTERFACE_HPP

#include <string>
#include <vector>
#include "../../Modele/Modele_hpp/Trajet.hpp"

/**
 * @class RechercheInterface
 * @brief Interface utilisateur pour saisir les critères de recherche de trajets.
 *
 * Cette vue permet à l'utilisateur de renseigner le lieu de départ, le lieu d'arrivée,
 * ainsi que la date du trajet. Elle propose également de retourner à l'accueil s'il le souhaite
 * Après saisie, elle redirige vers la TrajetInterface qui lui affiche le résultat de sa recherche.
 */
class RechercheInterface {
private:
    /**
    * @brief Affiche un message pour permettre à l'utilisateur de retourner à l'accueil.
    */
    void afficherMenuPrincipal();

public:
    /**
     * @brief Cette méthode permet d'afficher l'interface de recherche de trajets
     * 
     * @return std::tuple<std::string, std::string, std::string> un tuple contenant le lieu de départ, le lieu d'arrivée et la date de départ souhaité pour le trajet  
     */
    std::tuple<std::string, std::string, std::string> rechercher() const;
};

#endif
