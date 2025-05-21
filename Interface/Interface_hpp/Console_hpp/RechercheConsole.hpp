//
// Created by amzil on 20/05/25.
//

#ifndef RECHERCHECONSOLE_HPP
#define RECHERCHECONSOLE_HPP

#include "RechercheInterface.hpp"
#include <tuple>
#include <string>
#include <vector>


class RechercheConsole : public RechercheInterface {
private:
    void afficherMenuPrincipal() override;

public:
    std::tuple<std::string, std::string, std::string> rechercher() const override;
};

#endif //RECHERCHECONSOLE_HPP
