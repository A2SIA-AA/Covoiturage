#include "Modele_hpp/Reservation.hpp"

int Reservation::compteurReservation = 0;

Reservation::Reservation(float prix, bool statut) {
    compteurReservation++;
    this->prix = prix;
    this->idReservation = compteurReservation;
    this->statut = statut;
}
// Getters
float Reservation::getPrix() {
    return prix;
}

int Reservation::getIdReservation() {
    return idReservation;
}

bool Reservation::getStatut() {
    return statut;
}

// Setters
void Reservation::setPrix(float prix) {
    this->prix = prix;
}

void Reservation::setIdReservation(int IDrev) {
    this->idReservation = IDrev;
}

void Reservation::setStatut(bool statut) {
    this->statut = statut;
}

