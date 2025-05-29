//
// Created by amzil on 20/05/25.
//

#ifndef MESRESERVATIONSCONSOLE_HPP
#define MESRESERVATIONSCONSOLE_HPP

#include "ConnexionControlleur.hpp"
#include "TrajetControlleur.hpp"
#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../MesReservationsInterface.hpp"


class MesReservationsConsole : public MesReservationsInterface {
private:
    Database& db;
    TrajetControlleur controller;


public:

    ~MesReservationsConsole() override;

    void afficherReservations(const Passager& passager) override;

    void afficherReservations();
    MesReservationsConsole(Database& db);
};

#endif //MESRESERVATIONSCONSOLE_HPP
