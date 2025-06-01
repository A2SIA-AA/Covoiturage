#ifndef MODIFIERPROFILCONSOLE_HPP
#define MODIFIERPROFILCONSOLE_HPP

#include "../ModifierProfilInterface.hpp"
#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"

class ModifierProfilConsole : public ModifierProfilInterface {
private:
    Database db;
public:
    ~ModifierProfilConsole() override;


    // overload sans paramètre pour l’interaction console
    bool modifierCoordonnees();

    ModifierProfilConsole(Database& db);
};

#endif // MODIFIERPROFILCONSOLE_HPP
