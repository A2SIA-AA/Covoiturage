#include "Modele_hpp/Conducteur.hpp"


Conducteur::Conducteur(int idUtilisateur, std::string nom, std::string prenom,
                       std::string email, std::string motPasse,
                       std::string adressePostale, bool fumeur)
        : Utilisateur(idUtilisateur, nom, prenom, email, motPasse, adressePostale, fumeur) {

}

