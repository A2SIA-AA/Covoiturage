#ifndef CONNEXIONCONSOLE_HPP
#define CONNEXIONCONSOLE_HPP

#include <string>

#include "../../../Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include "../ConnexionInterface.hpp"
#include "../../../Modele/Modele_hpp/Utilisateur.hpp"

class ConnexionConsole : public ConnexionInterface {

public:
    Database& db;
    std::optional<Utilisateur> utilisateurConnecte;
    ConnexionControlleur controller;
    // surcharge de l'interface
    bool seConnecter(const std::string& email,
                     const std::string& motDePasse) override;

    // votre méthode sans paramètres
    bool seConnecter();

    // destructeur virtuel
    ~ConnexionConsole() override;
    std::optional<Utilisateur> getUtilisateurConnecte() const { return utilisateurConnecte; }

    explicit ConnexionConsole(Database& db) : db(db), controller(db)
    {
    }
};


#endif // CONNEXIONCONSOLE_HPP
