#include "../Modele_hpp/Reservation.hpp"
#include "../Modele_hpp/Passager.hpp"

Passager::Passager(std::string nom, std::string prenom, std::string email, std::string motPasse, std::string adressePostale, bool fumeur, std::vector<Reservation> listeReservation)
        : Utilisateur( nom, prenom, email, motPasse, adressePostale, fumeur),
          listeReservation(listeReservation) {

}


std::vector<Reservation> Passager::getListeReservation() const{
    return listeReservation;
}

void Passager::setListeReservation(std::vector<Reservation> reservation) {
    listeReservation = reservation;
}

void Passager::ajouterReservation(const Reservation& res) {
    listeReservation.push_back(res);
}


