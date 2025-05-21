#ifndef __InscriptionControlleur_HPP__
#define __InscriptionControlleur_HPP__

#include <string>
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"

/**
 * Contient les méthodes en lien avec l'inscription d'un nouvel utilisateur
 */
class InscriptionControlleur{

private:
    Database& baseDeDonnees;

public:
    InscriptionControlleur(Database& db) : baseDeDonnees(db) {}
    /**
     * Permet de vérifier la saisie lors d'une nouvelle inscription.
     * @param nom
     * @param prenom
     * @param email
     * @param motPasse
     * @param numéroTelephone
     * @param fumeur
     * @return true si les saisie respectent la norme
     */
    bool verifierSaisieInscription(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string numéroTelephone, bool fumeur);

    /**
     * @brief Traite l'inscription d'un utilisateur (si l'inscription s'est bien passé, on le renvoie à "ConnexionInterface")
     * @param nom
     * @param prenom
     * @param email
     * @param motPasse
     * @param numéroTelephone
     * @param fumeur
     */
    void traiterInscription(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string numéroTelephone, bool fumeur);

};
#endif