//
// Created by amzil on 20/05/25.
//

#ifndef MESRESERVATIONSCONSOLE_HPP
#define MESRESERVATIONSCONSOLE_HPP

#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../MesReservationsInterface.hpp"


class MesReservationsConsole : public MesReservationsInterface {
public:
    ~MesReservationsConsole() override;

    void afficherReservations(const Passager& passager) override;

    void afficherReservations();
};

#endif //MESRESERVATIONSCONSOLE_HPP
