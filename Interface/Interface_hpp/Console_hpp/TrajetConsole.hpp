//
// Created by amzil on 20/05/25.
//

#ifndef TRAJETCONSOLE_HPP
#define TRAJETCONSOLE_HPP

#include <vector>
#include "Interface_hpp/TrajetInterface.hpp"

class TrajetConsole : public TrajetInterface {
private:
    void afficherTrajets(const std::vector<Trajet>& trajets) override;

    void afficherMenuFiltres() override;

    void afficherFiltrage(const std::vector<Trajet>& trajets) override;

    void afficherMenuPrincipal() override;

    void afficherDetailsTrajet(const Trajet& trajet) override;

public:
    void afficherInterfaceRecherche(const std::vector<Trajet>& trajets) override;
};

#endif //TRAJETCONSOLE_HPP
