//
// Created by amzil on 20/05/25.
//

#ifndef MESANNONCESCONSOLE_HPP
#define MESANNONCESCONSOLE_HPP

#include <vector>
#include <string>
#include "../MesAnnoncesInterface.hpp"


class MesAnnoncesConsole : public MesAnnoncesInterface {
public:
    ~MesAnnoncesConsole() override;

    std::vector<std::string> listerAnnonces(int utilisateurId) override;

    std::vector<std::string> listerAnnonces();
};


#endif //MESANNONCESCONSOLE_HPP
