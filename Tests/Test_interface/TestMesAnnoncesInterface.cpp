#include "MesAnnoncesInterface.hpp"
#include <iostream>


/**
 * @brief Fonction pour tester la méthode listerAnnonces.
 */
void testListerAnnonces() {
    MesAnnoncesInterface annonces;

    // Cas 1 : Utilisateur avec plusieurs annonces (cas classique)
    auto liste = annonces.listerAnnonces(1);
    if (liste.size() == 2 &&
        liste[0] == "2024-05-01 | 08:00 | Paris → Lyon" &&
        liste[1] == "2024-06-15 | 14:00 | Marseille → Nice") {
        std::cout << "Cas 1 - Plusieurs annonces : Réussi" << std::endl;
    } else {
        std::cout << "Cas 1 - Plusieurs annonces : Échoué" << std::endl;
    }

    // Cas 2 : Utilisateur avec une seule annonce
    liste = annonces.listerAnnonces(2);
    if (liste.size() == 1 && liste[0] == "2024-07-10 | 09:30 | Lille → Bordeaux") {
        std::cout << "Cas 2 - Une seule annonce : Réussi" << std::endl;
    } else {
        std::cout << "Cas 2 - Une seule annonce : Échoué" << std::endl;
    }

    // Cas 3 : Utilisateur sans annonces
    liste = annonces.listerAnnonces(3);
    if (liste.empty()) {
        std::cout << "Cas 3 - Aucune annonce : Réussi" << std::endl;
    } else {
        std::cout << "Cas 3 - Aucune annonce : Échoué" << std::endl;
    }

    // Cas 4 : Utilisateur inexistant (doit être traité comme sans annonces)
    liste = annonces.listerAnnonces(99999);
    if (liste.empty()) {
        std::cout << "Cas 4 - Utilisateur inexistant : Réussi" << std::endl;
    } else {
        std::cout << "Cas 4 - Utilisateur inexistant : Échoué" << std::endl;
    }
}

int main() {
    std::cout << "--- Début des tests unitaires pour MesAnnoncesInterface ---" << std::endl;
    testListerAnnonces();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}
