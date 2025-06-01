//
// Created by amzil on 20/05/25.
//

#ifndef MESANNONCESCONSOLE_HPP
#define MESANNONCESCONSOLE_HPP

#include <vector>
#include <string>
#include "../MesAnnoncesInterface.hpp"
#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"


class MesAnnoncesConsole : public MesAnnoncesInterface {
private:
    Database db;
public:
    ~MesAnnoncesConsole() override;

    std::vector<std::string> listerAnnonces(int utilisateurId) override;

    std::vector<std::string> listerAnnonces();

    MesAnnoncesConsole(Database& db);

    void afficherAnnonces();
};


#endif //MESANNONCESCONSOLE_HPP
