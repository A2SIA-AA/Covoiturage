#ifndef TRAJET_INTERFACE_HPP
#define TRAJET_INTERFACE_HPP

#include <vector>
#include "../../Modele/Modele_hpp/Trajet.hpp"

/**
 * @class TrajetInterface
 * @brief Cette classe est responsable de l'affichage des trajets dans le terminal et de la gestion de l'interface utilisateur pour les recherches de trajets.
 *
 * Elle permet d’afficher les trajets correspondant à une recherche utilisateur, de proposer des filtres de tri et de rediriger vers le menu principal si besoin.
 */
class TrajetInterface {
    private:
        /**
         * @brief Affiche la liste des trajets dans le terminal suite à une recherche.  Seules les informations essentielles de chaque trajet seront affichées sous forme de résumé.
         * 
         * @param trajets la liste des trajets à afficher 
         */
        virtual void afficherTrajets(const std::vector<Trajet>& trajets) =0;

        /**
         * @brief Affiche le menu de filtres disponibles à l'utilisateur.
         * 
         */
        virtual void afficherMenuFiltres() = 0;

        /**
         * @brief Affiche le résultat du filtrage choisi par l'utilisateur
         * 
         * @param trajets Référence au vecteur de trajets à filtrer.
         * @param choix
         */
        virtual void afficherFiltrage(const std::vector<Trajet>& trajets,int choix) =0;

        /**
        * @brief Affiche un message pour permettre à l'utilisateur de retourner à l'accueil.
        */
        virtual void afficherMenuPrincipal() =0;

        /**
         * @brief Affiche les détails d’un trajet sélectionné et une fois cela fait,  
         * donné la possibilité à l'utilisateur de le réserver ou de revenir à la liste des trajets.
         * @param trajet Le trajet à détailler.
         */
        virtual void afficherDetailsTrajet(const Trajet& trajet) =0 ;

    public:
        /**
         * @brief Affiche le résultat suite à la recherche des trajets dans le terminal.
         *
         * Cette méthode reçoit une liste de trajets à afficher. Si la liste est vide, elle affiche
         * un message à l'utilisateur et propose de retourner au menu principal.
         * Sinon, elle :
         * - Affiche les trajets trouvés
         * - Affiche le menu de filtres disponibles et lui permet d'appliquer un filtre si le souhaite
         * - Propose de retourner au menu principal(Acceuil)
         * - Propose à l'utilisateur de voir les détails d’un trajet puis de le réserver, ou revenir en arrière
         *
         * @param trajets Vecteur de trajets à afficher et potentiellement filtrer. Il peut être vide.
         */
        virtual void afficherInterfaceRecherche(const std::vector<Trajet>& trajets) = 0;

        /**
         * @brief Destructeur virtuel de la classe TrajetInterface.
         *
         * Permet de garantir la destruction propre des objets dérivés lorsque la suppression
         * se fait par un pointeur de type base (TrajetInterface).
         */
        virtual ~TrajetInterface() = default;
    };

#endif