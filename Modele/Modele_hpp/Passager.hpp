#ifndef __PASSAGER_HPP__
#define __PASSAGER_HPP__
/**
 * @class Passager
 * @brief Représente un utilisateur ayant le rôle de passager dans l'application.
 *
 * La classe Passager hérite de la classe Utilisateur. Elle permet de distinguer les utilisateurs
 * qui prennent des trajets (passagers) de ceux qui en proposent (conducteurs).
 *
 * @see Utilisateur
 */
#include <string>
#include <vector>
#include "Utilisateur.hpp"
#include "Reservation.hpp"

class Passager : public Utilisateur{

private:
    std::vector<Reservation> listeReservation;

public:
    std::vector<Reservation> getListeReservation();
    void setListeReservation(std::vector<Reservation> reservation);
    Passager(int idUtilisateur, std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale, bool fumeur, std::vector<Reservation> listeReservation);
    void ajouterReservation(const Reservation& res);
};

#endif