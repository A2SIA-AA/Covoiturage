//
// Created by amzil on 20/05/25.
//

#ifndef MESANNONCESCONSOLE_HPP
#define MESANNONCESCONSOLE_HPP

#include <vector>
#include <string>
#include "Interface_hpp/MesAnnoncesInterface.hpp"


class MesAnnoncesConsole : public MesAnnoncesInterface {
public:
    std::vector<std::string> listerAnnonces(int utilisateurId) override;
};


#endif //MESANNONCESCONSOLE_HPP
