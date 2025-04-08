#ifndef __PASSAGER_HPP__
#define __PASSAGER_HPP__

#include <string>
#include "Utilisateur.hpp"

class Passager{

public:
    Passager(int idUtilisateur, std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale, bool fumeur);

};
#endif