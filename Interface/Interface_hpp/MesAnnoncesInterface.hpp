#ifndef MES_ANNONCES_INTERFACE_HPP
#define MES_ANNONCES_INTERFACE_HPP

#include <vector>
#include <string>

/**
 * @file MesAnnoncesInterface.hpp
 * @brief Interface pour la consultation des annonces de trajets d'un utilisateur.
 */
class MesAnnoncesInterface {
public:
    /**
     * @brief Destructeur virtuel.
     */
    virtual ~MesAnnoncesInterface() = default;

    /**
     * @brief Récupère la liste des annonces (trajets) publiées par l'utilisateur.
     *
     * Cette méthode permet d'obtenir toutes les annonces de trajets créées par l'utilisateur, qu'elles soient passées ou à venir.
     * Chaque annonce est retournée sous forme de chaîne de caractères résumant les informations principales du trajet (par exemple : date, heure, lieu de départ, lieu d'arrivée, etc.).
     *
     * @param utilisateurId L'identifiant unique de l'utilisateur dont on souhaite consulter ses annonces.
     * @return std::vector<std::string> Un vecteur de chaînes de caractères, chaque élément représentant une annonce.
     */
    virtual std::vector<std::string> listerAnnonces(int utilisateurId) = 0;
};

#endif // MES_ANNONCES_INTERFACE_HPP
