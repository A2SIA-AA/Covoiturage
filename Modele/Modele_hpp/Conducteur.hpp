#ifndef __CONDUCTEUR_HPP__
#define __CONDUCTEUR_HPP__

#include <string>
#include "Utilisateur.hpp"

class Conducteur : public Utilisateur{

  public:
    Conducteur(int idUtilisateur, std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale, bool fumeur);

};
#endif
