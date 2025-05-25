// AccueilConsole.hpp
#ifndef ACCUEILCONSOLE_HPP
#define ACCUEILCONSOLE_HPP

#include <string>
#include "../AccueilInterface.hpp"

class AccueilConsole : public AccueilInterface {
public:
    std::string accueil() override;
};

#endif
