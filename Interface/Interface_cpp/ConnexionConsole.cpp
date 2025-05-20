#include "Interface_hpp/ConnexionConsole.hpp"

#include "ConnexionControlleur.hpp" // Inclure le contrôleur
#include <iostream>

/**
 * @brief Affiche l'interface de connexion console, demande à l'utilisateur son email et son mot de passe,
 *        puis délègue la vérification au contrôleur.
 */
bool ConnexionConsole::seConnecter(const std::string& /*email*/, const std::string& /*motDePasse*/) {
    std::string email, motDePasse;

    std::cout << "=== Connexion ===" << std::endl;
    std::cout << "Email : ";
    std::getline(std::cin, email);

    std::cout << "Mot de passe : ";
    std::getline(std::cin, motDePasse);

    // Création du contrôleur
    ConnexionControlleur controlleur;

    // Appel du contrôleur pour vérifier l'utilisateur
    bool resultat = controlleur.verifierUtilisateur(email, motDePasse);

    return resultat;
}
