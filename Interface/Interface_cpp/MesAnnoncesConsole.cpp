#include "../Interface_hpp/Console_hpp/MesAnnoncesConsole.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include <iostream>
#include <limits>
#include <sstream>

// 1) Définition du destructeur
MesAnnoncesConsole::~MesAnnoncesConsole() = default;

MesAnnoncesConsole::MesAnnoncesConsole(Database& db): db(db)
{
}


// 2) Implémentation de la méthode pure virtuelle
std::vector<std::string> MesAnnoncesConsole::listerAnnonces(int utilisateurId) {
    std::vector<std::string> annonces;
    try {
        Conducteur conducteur = db.getConducteurByID(utilisateurId);
        auto trajets = conducteur.getListeTrajet();
        for (const auto& trajet : trajets) {
            std::ostringstream oss;
            oss << "Trajet #" << trajet.getIdTrajet() << " : "
                << trajet.getLieuDepart() << " -> " << trajet.getLieuArrive()
                << " le " << trajet.getDate() << " à " << trajet.getHeureDepart();
            annonces.push_back(oss.str());
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la récupération des annonces : " << e.what() << std::endl;
    }
    return annonces;
}


// 3) Version interactive qui pose la question à l'utilisateur
std::vector<std::string> MesAnnoncesConsole::listerAnnonces() {
    int utilisateurId;
    std::cout << "=== Consultation de vos annonces ===" << std::endl;
    std::cout << "Veuillez entrer votre identifiant utilisateur : ";
    std::cin >> utilisateurId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto annonces = listerAnnonces(utilisateurId);

    if (annonces.empty()) {
        std::cout << "Aucune annonce trouvée pour cet utilisateur." << std::endl;
    } else {
        std::cout << "\nVos annonces :" << std::endl;
        for (const auto& annonce : annonces) {
            std::cout << "- " << annonce << std::endl;
        }
    }

    return annonces;
}
