#ifndef __RECHERCHE__
#define __RECHERCHE__

#include <vector>
#include <string>
#include "../../Modele/Modele_hpp/Trajet.hpp"

/**
 * Contient les méthodes en lien avec la recherche d'un trajet.
 */
class RechercheControlleur{


public:
    /**
     * Permet la recherche d'un trajet selon un certain critère d'ordonnancement.
     * @param villeDepart
     * @param villeArrivee
     * @param Horaire Correspond à l'horaire à laquelle l'utilisateur aimerait partir
     * @param Filtre
     */
    void rechercherTrajet(std::string villeDepart, std::string villeArrivee, std::string Horaire, std::string Filtre);

    /**
     * Compare le prix de chaque trajet disponible avec ceux des trains
     * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
     * @param trajetsTrain Liste de tout les trajet disponible des trains
     * @param CritèreDeComparaison Ici le critère sera le prix
     * @return 2 listes triées par prix croissant
     */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparerPrix(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain, std::string CritèreDeComparaison);

    /**
    * Compare l'emission de CO2 de chaque trajet disponible avec ceux des trains
    * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
     * @param trajetsTrain Liste de tout les trajet disponible des trains
     * @param CritèreDeComparaison Ici le critère sera l'emission de CO2
     * @return 2 listes triées par émission de carbone croissant
     */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparerEmission(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain, std::string CritèreDeComparaison);

    /**
    * Compare la distance de chaque trajet disponible avec ceux des trains
    * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
    * @param trajetsTrain Liste de tout les trajet disponible des trains
    * @param CritèreDeComparaison Ici le critère sera la distance (en km)
    * @return 2 listes triées par distance croissante
    */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparerDistanceTrajet(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain, std::string CritèreDeComparaison);

    /**
     * Calcule l'empreinte carbone d'un véhicule.
     * @param distance Distance entre le départ et l'arrivée
     * @param voiture Correspond au type de la voiture (diesel, essence, ...)
     * @param consommationMoyenne
     * @return L'empreinte carbone en tonnes d'émission
     */
    float calculerEmission(float distance, std::string voiture, float consommationMoyenne );

    /**
    * Compare la durée de chaque trajet disponible avec ceux des trains
    * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
    * @param trajetsTrain Liste de tout les trajet disponible des trains
    * @param CritèreDeComparaison Ici le critère sera la durée (en min)
    * @return 2 listes triées par temps croissant
    */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparerDuree(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain, std::string CritèreDeComparaison);

    /**
    * Compare l'heure de départ de chaque trajet disponible avec ceux des trains
    * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
    * @param trajetsTrain Liste de tout les trajet disponible des trains
    * @param CritèreDeComparaison Ici le critère sera l'heure de départ
    * @return 2 listes triées par heure de départ croissant
    */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparerHeureDepart(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain, std::string CritèreDeComparaison);

    /**
    * Compare le nombre de point intermédiaire de chaque trajet disponible avec ceux des trains
    * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
    * @param trajetsTrain Liste de tout les trajet disponible des trains
    * @param CritèreDeComparaison Ici le critère sera le nombre d'arrêt
    * @return 2 listes triées par nombre de point intermediaire croissant
    */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparerPointIntermediaire(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain, std::string CritèreDeComparaison);

    /**
    * Compare 2 trajets selon le critères de base
    * @param trajetsDisponibles Liste de tout les trajets disponible sur la plateforme
    * @param trajetsTrain Liste de tout les trajet disponible des trains
    * @return
    */
    std::pair<std::vector<Trajet>, std::vector<Trajet>> comparer(const std::vector<Trajet>& trajetsDisponibles, const std::vector<Trajet>& trajetsTrain);

};
#endif