#ifndef INSCRIPTIONCONSOLE_HPP
#define INSCRIPTIONCONSOLE_HPP

#include "../InscriptionInterface.hpp"
#include <string>

#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../../Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"

class InscriptionConsole : public InscriptionInterface {
private:
    Database& db;
    InscriptionControlleur controller;

public:
    explicit InscriptionConsole(Database& dbRef)
        : db(dbRef), controller(dbRef) {}

    bool sInscrire();

    ~InscriptionConsole() override = default;

    // implémentation de l'interface
    bool sInscrire(const std::string& nom,
                   const std::string& prenom,
                   const std::string& email,
                   const std::string& motPasse,
                   const std::string& adressePostale,
                   bool fumeur) override;

};

#endif // INSCRIPTIONCONSOLE_HPP
