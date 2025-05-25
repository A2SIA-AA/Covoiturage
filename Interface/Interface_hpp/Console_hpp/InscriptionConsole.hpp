#ifndef INSCRIPTIONCONSOLE_HPP
#define INSCRIPTIONCONSOLE_HPP

#include "../InscriptionInterface.hpp"
#include <string>

class InscriptionConsole : public InscriptionInterface {
public:
    // implémentation de l'interface
    bool sInscrire(const std::string& nom,
                   const std::string& prenom,
                   const std::string& email,
                   const std::string& motPasse,
                   const std::string& adressePostale,
                   bool fumeur) override;

    // version interactive
    bool sInscrire();

    // destructeur virtuel
    ~InscriptionConsole() override;
};

#endif // INSCRIPTIONCONSOLE_HPP
