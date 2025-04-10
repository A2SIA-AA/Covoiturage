#ifndef __RESERVATION_HPP__
#define __RESERVATION_HPP__

#include <string>

class Reservation{
private:
    float prix;
    int idReservation;
    bool statut;

public:
    Reservation(float prix, int ID, bool statut);

    float getPrix();
    int getIdReservation();
    bool getStatut();
    void setPrix(float prix);
    void setIdReservation(int ID);
    void setStatut(bool statut);

};
#endif