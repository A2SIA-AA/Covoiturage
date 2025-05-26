#include "../Modele_hpp/Reservation.hpp"



Reservation::Reservation(int idTrajet, bool statut,float prix, int idPassager)
        : prix(prix),
          statut(statut), idPassager(idPassager), idTrajet(idTrajet) {}

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


