#ifndef TRAJETCONSOLE_HPP
#define TRAJETCONSOLE_HPP

#include <vector>

#include "../../../Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "../TrajetInterface.hpp"
/**
 * @brief Classe gérant l'affichage et l'interaction utilisateur pour les trajets via la console.
 *
 * TrajetConsole hérite de TrajetInterface et propose toutes les fonctionnalités nécessaires à la gestion
 * de l'affichage, la recherche, le filtrage et la consultation des trajets. Elle permet d'interagir
 * directement avec l'utilisateur via la console.
 */
class TrajetConsole : public TrajetInterface {
private:
    /**
 * @brief Référence à la base de données de l'application.
 *
 * Permet d'effectuer des requêtes sur les trajets et d'assurer la persistance des données.
 */

    Database& db;
    /**
 * @brief Contrôleur dédié à la gestion des trajets.
 */

    TrajetControlleur trajetCtrl;

    /**
 * @brief Contrôleur dédié aux opérations de recherche sur les trajets.
 */

    RechercheControlleur rechercheCtrl;

    /**
 * @brief Affiche une liste de trajets dans la console.
 * @param trajets Vecteur contenant les trajets à afficher.
 */
   void afficherTrajets(const std::vector<Trajet>& trajets) override;
   /**
     * @brief Affiche tous les trajets disponibles dans la console.
     */
   void afficherTrajets();

   /**
 * @brief Affiche le menu des filtres permettant de restreindre la recherche.
 */

    void afficherMenuFiltres() override;

   /**
 * @brief Affiche l'interface de filtrage permettant à l'utilisateur de saisir des critères.
 */

    void afficherFiltrage();

   /**
 * @brief Affiche le menu principal dédié à la gestion des trajets.
 */

    void afficherMenuPrincipal() override;

   /**
 * @brief Affiche le détail d'un trajet spécifique.
 * @param trajet Trajet dont les détails doivent être affichés.
 */

    void afficherDetailsTrajet(const Trajet& trajet) override;
   /**
    * @brief Affiche le détail d'un trajet (mode interactif, saisie utilisateur).
    */
   void afficherDetailsTrajet();

public:
   /**
 * @brief Affiche le résultat du filtrage selon le choix utilisateur.
 * @param trajets Vecteur des trajets à filtrer.
 * @param choix Option de filtrage sélectionnée.
 */
    void afficherFiltrage(const std::vector<Trajet>& trajets, int choix);
   /**
 * @brief Constructeur recevant la référence de la base de données.
 * @param db Référence vers la base de données principale.
 */
    explicit TrajetConsole(Database& db); // constructeur avec DB

   /**
 * @brief Affiche l'interface de recherche des trajets selon les résultats obtenus.
 * @param trajets Liste des trajets à afficher.
 */
    void afficherInterfaceRecherche(const std::vector<Trajet>& trajets) override;

   /**
 * @brief Affiche l'interface de recherche des trajets (mode interactif).
 */
    void afficherInterfaceRecherche();

   /**
 * @brief Destructeur, assure la libération des ressources.
 */

    ~TrajetConsole() override;
};

#endif //TRAJETCONSOLE_HPP
