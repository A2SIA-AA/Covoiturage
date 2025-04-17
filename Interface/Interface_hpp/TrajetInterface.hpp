#ifndef TRAJET_INTERFACE_HPP
#define TRAJET_INTERFACE_HPP

#include <vector>
#include <string>
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
        void afficherTrajets(const std::vector<Trajet>& trajets);

        /**
         * @brief Affiche le menu de filtres disponibles à l'utilisateur.
         * 
         */
        void afficherMenuFiltres();

        /**
         * @brief Affiche le résultat du filtrage choisi par l'utilisateur
         * 
         * @param trajets Référence au vecteur de trajets à filtrer.
         */
        void afficherFiltrage(const std::vector<Trajet>& trajets);

        /**
        * @brief Affiche un message pour permettre à l'utilisateur de retourner à l'accueil.
        */
        void afficherMenuPrincipal();

        /**
         * @brief Affiche les détails d’un trajet sélectionné et une fois cela fait,  
         * donné la possibilité à l'utilisateur de le réserver ou de revenir à la liste des trajets.
         * @param trajet Le trajet à détailler.
         */
        void afficherDetailsTrajet(const Trajet& trajet);

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
        void afficherInterfaceRecherche(const std::vector<Trajet>& trajets);
    };

#endif