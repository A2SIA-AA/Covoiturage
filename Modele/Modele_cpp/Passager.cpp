#include "Modele_hpp/Passager.hpp"


Passager::Passager(int idUtilisateur, std::string nom, std::string prenom,
                   std::string email, std::string motPasse,
                   std::string adressePostale, bool fumeur, std::vector<Reservation> listeReservation)
        : Utilisateur(idUtilisateur, nom, prenom, email, motPasse, adressePostale, fumeur) {

}

std::vector<Reservation> getListeReservation(){
    return listeReservation;
}

void setListeReservation(const std::vector<Reservation>& reservation) {
    listeReservation = reservation;
}

/**
 * Ajouter une reservation dans la liste des reservations du passager
 * @param res
 */
void ajouterReservation(const Reservation& res){

}

