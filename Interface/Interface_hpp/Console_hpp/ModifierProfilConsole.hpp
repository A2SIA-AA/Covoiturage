//
// Created by amzil on 20/05/25.
//

#ifndef MODIFIERPROFILCONSOLE_HPP
#define MODIFIERPROFILCONSOLE_HPP

#include "ModifierProfilInterface.hpp"
#include <string>


class ModifierProfilConsole : public ModifierProfilInterface {
public:
    bool modifierCoordonnees(const std::string& nom,
                             const std::string& prenom,
                             const std::string& email,
                             const std::string& telephone) override;
};

#endif //MODIFIERPROFILCONSOLE_HPP
