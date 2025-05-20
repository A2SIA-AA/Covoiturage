// AccueilConsole.hpp
#ifndef ACCUEILCONSOLE_HPP
#define ACCUEILCONSOLE_HPP

#include "AccueilInterface.hpp"
#include <string>

class AccueilConsole : public AccueilInterface {
public:
    std::string accueil() override;
};

#endif
