#ifndef MODIFIERPROFILCONSOLE_HPP
#define MODIFIERPROFILCONSOLE_HPP

#include "../ModifierProfilInterface.hpp"

class ModifierProfilConsole : public ModifierProfilInterface {
public:
    ~ModifierProfilConsole() override;

    // signée pure dans l’interface
    bool modifierCoordonnees(const std::string& nom,
                             const std::string& prenom,
                             const std::string& email,
                             const std::string& motPasse,
                             const std::string& adressePostale,
                             bool fumeur) override;

    // overload sans paramètre pour l’interaction console
    bool modifierCoordonnees();
};

#endif // MODIFIERPROFILCONSOLE_HPP
