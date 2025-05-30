#ifndef TRAJETCONSOLE_HPP
#define TRAJETCONSOLE_HPP

#include <vector>

#include "RechercheControlleur.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "../TrajetInterface.hpp"

class TrajetConsole : public TrajetInterface {
private:
    Database& db;
    TrajetControlleur trajetCtrl;
    RechercheControlleur rechercheCtrl;

    void afficherTrajets(const std::vector<Trajet>& trajets) override;
    void afficherTrajets();

    void afficherMenuFiltres() override;

    void afficherFiltrage();

    void afficherMenuPrincipal() override;

    void afficherDetailsTrajet(const Trajet& trajet) override;
    void afficherDetailsTrajet();

public:
    void afficherFiltrage(const std::vector<Trajet>& trajets, int choix);
    explicit TrajetConsole(Database& db); // constructeur avec DB
    void afficherInterfaceRecherche(const std::vector<Trajet>& trajets) override;
    void afficherInterfaceRecherche();
    ~TrajetConsole() override;
};

#endif //TRAJETCONSOLE_HPP
