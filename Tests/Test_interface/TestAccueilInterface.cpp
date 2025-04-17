#include "AccueilInterface.hpp"
#include <iostream>

/**
 * @brief Fonction pour tester que l'interface d’accueil redirige bien vers les modules spécialisés.
 */
void testAccueilInterface() {
    // Instancier l'implémentation concrète
    AccueilInterface accueil;

    // Test 1 : Vérifier que chaque getter retourne un pointeur non nul
    std::cout << "Test 1 - RechercheInterface : " << (accueil.getRechercheInterface() ? "Réussi" : "Échoué") << std::endl;
    std::cout << "Test 2 - ReservationInterface : " << (accueil.getReservationInterface() ? "Réussi" : "Échoué") << std::endl;
    std::cout << "Test 3 - ModifierProfilInterface : " << (accueil.getModifierProfilInterface() ? "Réussi" : "Échoué") << std::endl;
    std::cout << "Test 4 - MesReservationsInterface : " << (accueil.getMesReservationsInterface() ? "Réussi" : "Échoué") << std::endl;
    std::cout << "Test 5 - MesAnnoncesInterface : " << (accueil.getMesAnnoncesInterface() ? "Réussi" : "Échoué") << std::endl;
    std::cout << "Test 6 - TrajetInterface : " << (accueil.getTrajetInterface() ? "Réussi" : "Échoué") << std::endl;
    std::cout << "Test 7 - AvisInterface : " << (accueil.getAvisInterface() ? "Réussi" : "Échoué") << std::endl;
}

int main() {
    // Lancer les tests unitaires
    std::cout << "--- Début des tests unitaires pour AccueilInterface ---" << std::endl;
    testAccueilInterface();
    std::cout << "--- Fin des tests unitaires ---" << std::endl;
    return 0;
}

