#ifndef __InscriptionControlleur_HPP__
#define __InscriptionControlleur_HPP__

#include <string>

/**
 * Contient les méthodes en lien avec l'inscription d'un nouvel utilisateur
 */
class InscriptionControlleur{


public:
    /**
     * Permet de vérifier la saisie lors d'une nouvelle inscription.
     * @param nom
     * @param prenom
     * @param email
     * @param motPasse
     * @param adressePostale
     */
    void verifierSaisieInscription(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale);


};
#endif