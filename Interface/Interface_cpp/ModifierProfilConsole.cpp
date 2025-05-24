#include "Interface_hpp/Console_hpp/modifierProfilConsole.hpp"
#include "../Controlleur_hpp/modifierProfilControlleur.hpp"
#include <iostream>
#include <string>

bool ModifierProfilConsole::modifierCoordonnees(
    const std::string& nom, const std::string& prenom,
    const std::string& email, const std::string& motPasse,
    const std::string& adressePostale, bool fumeur)
{
    // 1. Afficher le profil actuel
    std::cout << "=== Profil actuel ===" << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Prénom: " << prenom << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Mot de passe: [masqué]" << std::endl; // Pour la sécurité
    std::cout << "Adresse postale: " << adressePostale << std::endl;
    std::cout << "Fumeur: " << (fumeur ? "Oui" : "Non") << std::endl;

    // 2. Demander l'ID de l'utilisateur
    int idUtilisateur;
    std::cout << "Entrez l'ID de l'utilisateur à modifier : ";
    std::cin >> idUtilisateur;
    std::cin.ignore(); // Pour consommer le retour à la ligne restant

    // 3. Demander le champ à modifier
    std::cout << "=== Modification du profil ===" << std::endl;
    std::cout << "Quel champ souhaitez-vous modifier ?\n"
              << "1. nom\n2. prenom\n3. email\n4. motPasse\n5. adressePostale\n6. fumeur\n"
              << "Votre choix (1-6) : ";
    std::string choixMenu;
    std::getline(std::cin, choixMenu);

    std::string champ;
    if (choixMenu == "1") champ = "nom";
    else if (choixMenu == "2") champ = "prenom";
    else if (choixMenu == "3") champ = "email";
    else if (choixMenu == "4") champ = "motPasse";
    else if (choixMenu == "5") champ = "adressePostale";
    else if (choixMenu == "6") champ = "fumeur";
    else {
        std::cout << "Choix invalide !" << std::endl;
        return false;
    }

    // 4. Demander la nouvelle valeur
    std::cout << "Nouvelle valeur pour " << champ << " : ";
    std::string nouvelleValeur;
    std::getline(std::cin, nouvelleValeur);

    // 5. Appeler le contrôleur
    ModifierProfilControlleur controlleur;
    controlleur.ModifierProfil(idUtilisateur, champ, nouvelleValeur);

    std::cout << "Modification effectuée !" << std::endl;
    return true;
}
