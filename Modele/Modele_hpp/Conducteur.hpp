#ifndef __CONDUCTEUR_HPP__
#define __CONDUCTEUR_HPP__

#include <string>
#include "Utilisateur.hpp"
#include "Trajet.hpp"

/**
 * @class Conducteur
 * @brief Représente un utilisateur ayant le rôle de conducteur dans l'application.
 *
 * La classe Conducteur hérite de la classe Utilisateur. Elle permet de distinguer les utilisateurs
 * qui proposent des trajets (conducteurs) de ceux qui en réservent (passagers).
 *
 * @see Utilisateur
 */
class Conducteur : public Utilisateur{

private:
    std::vector<Trajet> listeTrajet;

public:
    std::vector<Trajet> getListeTrajet();
    void setListeTrajet(std::vector<Trajet> trajet);
    Conducteur(int idUtilisateur, std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale, bool fumeur);

};
#endif
