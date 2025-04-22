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
     * @param numéroTelephone
     * @return true si les saisie respectent la norme
     */
    bool verifierSaisieInscription(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string numéroTelephone);

    /**
     * @brief Traite l'inscription d'un utilisateur (si l'inscription s'est bien passé, on le renvoie à "ConnexionInterface")
     * @param nom
     * @param prenom
     * @param email
     * @param motPasse
     * @param numéroTelephone
     */
    void traiterInscription(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string numéroTelephone);

};
#endif