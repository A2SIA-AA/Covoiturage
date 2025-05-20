#include "../Modele_hpp/Reservation.hpp"

int Reservation::compteurReservation = 0;

Reservation::Reservation(float prix, bool statut)
        : prix(prix), idReservation(compteurReservation++),
          statut(statut), idPassager(0), idTrajet(0) {}

float Reservation::getPrix() {
    return prix;
}

int Reservation::getIdReservation() {
    return idReservation;
}

bool Reservation::getStatut() {
    return statut;
}

int Reservation::getIdTrajet() const {
    return idTrajet;
}

int Reservation::getIdPassager() const {
    return idPassager;
}

void Reservation::setIdPassager(int idPassager) {
    this->idPassager = idPassager;
}

void Reservation::setPrix(float prix) {
    this->prix = prix;
}

void Reservation::setIdReservation(int ID) {
    idReservation = ID;
}

void Reservation::setStatut(bool statut) {
    this->statut = statut;
}

void Reservation::setIdTrajet(int idTrajet) {
    this->idTrajet = idTrajet;
}
