//
// Created by amzil on 20/05/25.
//

#ifndef CONNEXIONCONSOLE_HPP
#define CONNEXIONCONSOLE_HPP

#include "ConnexionInterface.hpp"
#include <string>

class ConnexionConsole : public ConnexionInterface {
public:
    bool seConnecter(const std::string& email, const std::string& motDePasse) override;
};

#endif //CONNEXIONCONSOLE_HPP
