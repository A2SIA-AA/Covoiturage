#ifndef CONNEXIONCONSOLE_HPP
#define CONNEXIONCONSOLE_HPP

#include <string>
#include "../ConnexionInterface.hpp"

class ConnexionConsole : public ConnexionInterface {
public:
    // surcharge de l'interface
    bool seConnecter(const std::string& email,
                     const std::string& motDePasse) override;

    // votre méthode sans paramètres
    bool seConnecter();

    // destructeur virtuel
    ~ConnexionConsole() override;
};

#endif // CONNEXIONCONSOLE_HPP
