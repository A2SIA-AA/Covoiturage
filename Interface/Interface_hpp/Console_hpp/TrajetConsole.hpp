//
// Created by amzil on 20/05/25.
//

#ifndef TRAJETCONSOLE_HPP
#define TRAJETCONSOLE_HPP

#include <vector>
#include "Interface_hpp/TrajetInterface.hpp"

class TrajetConsole : public TrajetInterface {
private:
    ~TrajetConsole() override;


    void afficherTrajets(const std::vector<Trajet>& trajets) override;
    void afficherTrajets();


    void afficherMenuFiltres() override;


    void afficherFiltrage(const std::vector<Trajet>& trajets) override;
    void afficherFiltrage();


    void afficherMenuPrincipal() override;


    void afficherDetailsTrajet(const Trajet& trajet) override;
    void afficherDetailsTrajet();

public:
    void afficherInterfaceRecherche(const std::vector<Trajet>& trajets) override;
    void afficherInterfaceRecherche();
};

#endif //TRAJETCONSOLE_HPP
