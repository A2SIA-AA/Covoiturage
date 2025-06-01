#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "../../Modele/Modele_hpp/Trajet.hpp"
#include <iostream>

void testObtenirTrajets() {
    Database db(":memory");
    TrajetControlleur controleur(db);

    // Cas nominal : trajet existant
    std::vector<Trajet> trajets = controleur.obtenirTrajets("Paris", "Lyon", "2025-05-01");
    if (!trajets.empty()) {
        std::cout << "Test Trajet Existant : Réussi ("
                  << trajets.size() << " trajet(s) trouvé(s))" << std::endl;
    } else {
        std::cout << "Test Trajet Existant : Échoué (aucun trajet trouvé)" << std::endl;
    }

    // Cas d'erreur : date invalide (format incorrect)
    trajets = controleur.obtenirTrajets("Paris", "Lyon", "01-05-2025");
    if (trajets.empty()) {
        std::cout << "Test Date Invalide : Réussi (aucun trajet retourné)" << std::endl;
    } else {
        std::cout << "Test Date Invalide : Échoué (trajets trouvés alors que date invalide)" << std::endl;
    }

    // Cas aux limites : ville de départ vide
    trajets = controleur.obtenirTrajets("", "Lyon", "2025-05-01");
    if (trajets.empty()) {
        std::cout << "Test Lieu Départ Vide : Réussi" << std::endl;
    } else {
        std::cout << "Test Lieu Départ Vide : Échoué" << std::endl;
    }

    // Cas aux limites : ville d’arrivée vide
    trajets = controleur.obtenirTrajets("Paris", "", "2025-05-01");
    if (trajets.empty()) {
        std::cout << "Test Lieu Arrivée Vide : Réussi" << std::endl;
    } else {
        std::cout << "Test Lieu Arrivée Vide : Échoué" << std::endl;
    }

    // Cas où aucun trajet ne correspond
    trajets = controleur.obtenirTrajets("Paris", "Marseille", "2030-12-31");
    if (trajets.empty()) {
        std::cout << "Test Aucun Trajet Correspondant : Réussi" << std::endl;
    } else {
        std::cout << "Test Aucun Trajet Correspondant : Échoué" << std::endl;
    }
}

int main() {
    testObtenirTrajets();
    return 0;
}
