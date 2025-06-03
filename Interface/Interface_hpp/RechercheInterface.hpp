#ifndef RECHERCHE_INTERFACE_HPP
#define RECHERCHE_INTERFACE_HPP

#include <string>

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
    virtual void afficherMenuPrincipal() const = 0;

public:
    /**
     * @brief Cette méthode permet d'afficher l'interface de recherche de trajets
     * 
     * @return std::tuple<std::string, std::string, std::string> un tuple contenant le lieu de départ, le lieu d'arrivée et la date de départ souhaité pour le trajet  
     */
    [[nodiscard]] virtual std::tuple<std::string, std::string, std::string> rechercher() const =0 ;

    /**
     * @brief Destructeur virtuel de la classe RechercheInterface.
     *
     * Ce destructeur permet une destruction appropriée des objets dérivés via un pointeur
     * de type RechercheInterface, garantissant ainsi le respect du polymorphisme.
     */
    virtual ~RechercheInterface() = default;
};

#endif
