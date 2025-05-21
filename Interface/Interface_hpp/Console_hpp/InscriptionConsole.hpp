//
// Created by amzil on 20/05/25.
//

#ifndef INSCRIPTIONCONSOLE_HPP
#define INSCRIPTIONCONSOLE_HPP

#include "Interface_hpp/InscriptionInterface.hpp"
#include <string>


class InscriptionConsole : public InscriptionInterface {
public:
    bool sInscrire(const std::string& nom, const std::string& prenom,
                   const std::string& email, const std::string& telephone,
                   const std::string& motDePasse) override;
};

#endif //INSCRIPTIONCONSOLE_HPP
