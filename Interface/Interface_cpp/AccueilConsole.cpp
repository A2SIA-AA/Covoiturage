#include "../Interface_hpp/Console_hpp/AccueilConsole.hpp"

#include <iostream>

std::string AccueilConsole::accueil() {
    std::cout << "=== Menu d'accueil ===" << std::endl;
    std::cout << "1. Modifier le profil" << std::endl;
    std::cout << "2. Recherche" << std::endl;
    std::cout << "3. Mes réservations" << std::endl;
    std::cout << "4. Mes annonces" << std::endl;
    std::cout << "5. Ajouter un trajet" << std::endl;
    std::cout << "6. Quitter" << std::endl;
    std::cout << "Votre choix : ";

    std::string choix;
    std::getline(std::cin, choix);
    return choix;
}
