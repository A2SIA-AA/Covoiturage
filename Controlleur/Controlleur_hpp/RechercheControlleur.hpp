#ifndef __RECHERCHE__
#define __RECHERCHE__

#include <vector>
#include <string>

#include "BaseControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"

/**
 * Contient les méthodes en lien avec la recherche d'un trajet.
 */
class RechercheControlleur : public BaseControlleur{

public:

    /**
    * @brief Constructeur implicite à partir de la base de données.
    * @param db Référence à l'objet Database partagé.
    */
    explicit RechercheControlleur(Database& db)
        : BaseControlleur(db)
    {
    }

    /**
     * Permet de récuperer tout les trajet des covoiturages et les affiche
     * @param villeDepart
     * @param villeArrivee
     * @param Date Correspond à la date à laquelle l'utilisateur aimerait partir
     * @return Liste de tout les covoiturage disponible
     */
    std::vector<Trajet> rechercherTrajet(std::string villeDepart, std::string villeArrivee, std::string Date);

    /**
     * Trie les trajets de covoiturage selon le prix croissant.
     * @param trajetsDisponibles Liste de trajets covoiturage
     * @return Liste triée par prix
     */
    std::vector<Trajet> comparerPrix(const std::vector<Trajet>& trajetsDisponibles);

    /**
     * Trie les trajets de covoiturage selon les émissions de CO2 (ordre croissant).
     * @param trajetsDisponibles Liste de trajets covoiturage
     * @return Liste triée par émissions de CO2
     */
    std::vector<Trajet> comparerEmission(const std::vector<Trajet>& trajetsDisponibles);

    /**
     * Calcule l'empreinte carbone d'un véhicule.
     * @param distance Distance entre le départ et l'arrivée
     * @param voiture Type de voiture (diesel, essence, ...)
     * @param consommationMoyenne
     * @return L'empreinte carbone estimée
     */
    float calculerEmission(float distance, std::string voiture, float consommationMoyenne);

    /**
     * Trie les trajets de covoiturage selon la durée (ordre croissant).
     * @param trajetsDisponibles Liste de trajets covoiturage
     * @return Liste triée par durée
     */
    std::vector<Trajet> comparerDuree(const std::vector<Trajet>& trajetsDisponibles);

    /**
     * Trie les trajets de covoiturage selon l'heure de départ (ordre croissant).
     * @param trajetsDisponibles Liste de trajets covoiturage
     * @return Liste triée par heure de départ
     */
    std::vector<Trajet> comparerHeureDepart(const std::vector<Trajet>& trajetsDisponibles);

    /**
     * Trie les trajets de covoiturage selon le nombre de points intermédiaires (ordre croissant).
     * @param trajetsDisponibles Liste de trajets covoiturage
     * @return Liste triée par nombre de points intermédiaires
     */
    std::vector<Trajet> comparerPointIntermediaire(const std::vector<Trajet>& trajetsDisponibles);

    /**
     * Trie les trajets de covoiturage selon un critère par défaut (prix ou durée, etc.)
     * @param trajetsDisponibles Liste de trajets covoiturage
     * @return Liste triée par critère par défaut
     */
    std::vector<Trajet> comparer(const std::vector<Trajet>& trajetsDisponibles);
};

#endif
