#ifndef MES_ANNONCES_INTERFACE_HPP
#define MES_ANNONCES_INTERFACE_HPP

#include "AccueilInterface.hpp"
#include <vector>
#include <string>

/**
 * @file MesAnnoncesInterface.hpp
 * @brief Interface pour afficher et gérer les annonces de l'utilisateur.
 */
class MesAnnoncesInterface {
public:
    /**
     * @brief Méthode pour récupérer et afficher les réservations de l'utilisateur : Cette méthode permet de récupérer la liste des réservations de l'utilisateur qu'elles soient passées ou futures, et de les afficher à l'écran.
     * Elle utilise le TrajetControlleur pour obtenir les trajets.
     * @param utilisateurId L'identifiant unique de l'utilisateur.
     * @return std::vector<std::string> Une liste de chaînes de caractères représentant les réservations. Chaque chaîne peut contenir des informations comme la date, l'heure, la destination, etc.
     */
    virtual std::vector<std::string> afficherReservations(int utilisateurId) = 0;

    /**
     * @brief Méthode pour afficher les détails d'un trajet spécifique :  Cette méthode permet d'afficher les détails d'un trajet spécifique en utilisant l'identifiant du trajet.
     * @param trajetId L'identifiant unique du trajet.
     * @return std::string Une chaîne de caractères contenant les détails du trajet.
     */
    virtual std::string afficherDetailsTrajet(int trajetId) = 0;
};

#endif // MES_ANNONCES_INTERFACE_HPP
