//
// Created by amzil on 20/05/25.
//

#ifndef MESRESERVATIONSCONSOLE_HPP
#define MESRESERVATIONSCONSOLE_HPP

#include "MesReservations.hpp"
#include "../../Modele/Modele_hpp/Passager.hpp"


class MesReservationsConsole : public MesReservations {
public:
    void afficherReservations(const Passager& passager) override;
};

#endif //MESRESERVATIONSCONSOLE_HPP
