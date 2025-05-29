//
// Created by amzil on 20/05/25.
//

#ifndef TRAJETCONSOLE_HPP
#define TRAJETCONSOLE_HPP

#include <vector>
#include "../TrajetInterface.hpp"

class TrajetConsole : public TrajetInterface {
    private:


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
    ~TrajetConsole() override;
};

#endif //TRAJETCONSOLE_HPP
