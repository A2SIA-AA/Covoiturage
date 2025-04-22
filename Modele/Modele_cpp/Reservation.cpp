#include "Modele_hpp/Reservation.hpp"

Reservation::Reservation(float prix, int IDrev, bool statut) {
    this->prix = prix;
    this->idReservation = IDrev;
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

