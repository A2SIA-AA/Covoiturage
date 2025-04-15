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

public:
    Reservation(float prix, int ID, bool statut);

    float getPrix();
    int getIdReservation();
    bool getStatut();
    int getIdTrajet();
    int getIDPassager();
    void setIDPassager(int nomPassager);
    void setPrix(float prix);
    void setIdReservation(int ID);
    void setStatut(bool statut);
    void setIdTrajet(int idTrajet);

};
#endif