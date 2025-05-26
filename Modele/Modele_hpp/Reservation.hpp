#ifndef __RESERVATION_HPP__
#define __RESERVATION_HPP__

#include <string>
/**
 * @class Reservation
 * Permet de modeliser et definir une reservation d'un trajet et servira pour l'historique

 */
class Reservation{
private:

    float prix;
    int idReservation;
    bool statut;
    int idPassager;
    int idTrajet;

public:
    Reservation(int idReservation, int idTrajet, bool statut,float prix, int idPassager);
    float getPrix();
    int getIdReservation();
    bool getStatut();
    int getIdTrajet() const;
    int getIdPassager() const;
    void setIdPassager(int idPassager);
    void setPrix(float prix);
    void setIdReservation(int ID);
    void setStatut(bool statut);
    void setIdTrajet(int idTrajet);

};
#endif