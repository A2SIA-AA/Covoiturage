#include "Controlleur/Controlleur_hpp/InscriptionControlleur.hpp"
#include "Controlleur/Controlleur_hpp/ConnexionControlleur.hpp"
#include "Controlleur/Controlleur_hpp/TrajetControlleur.hpp"
#include "Controlleur/Controlleur_hpp/RechercheControlleur.hpp"
#include "Controlleur/Controlleur_hpp/ModifierProfilControlleur.hpp"
/*
#include "Interface/Interface_hpp/AccueilInterface.hpp"
#include "Interface/Interface_hpp/TrajetInterface.hpp"
#include "Interface/Interface_hpp/ConnexionInterface.hpp"
#include "Interface/Interface_hpp/InscriptionInterface.hpp"
#include "Interface/Interface_hpp/RechercheInterface.hpp"
#include "Interface/Interface_hpp/MesAnnoncesInterface.hpp"
#include "Interface/Interface_hpp/MesReservationsInterface.hpp"
#include "Interface/Interface_hpp/ModifierProfilInterface.hpp"

*/
#include "Modele/Modele_hpp/Conducteur.hpp"
#include "Modele/Modele_hpp/Message.hpp"
#include "Modele/Modele_hpp/Trajet.hpp"
#include "Modele/Modele_hpp/Reservation.hpp"
#include "Modele/Modele_hpp/Passager.hpp"
#include "Modele/Modele_hpp/Utilisateur.hpp"
#include "Modele/Modele_hpp/BaseDonnees.hpp"

int main() {
    Database db("maBase.sqlite");
    InscriptionControlleur inscriptionCtrl(db);

    try {
        inscriptionCtrl.traiterInscription("Jean", "Dupont", "jean.dupont@example.com", "secure123", "75001", true);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Arrêt propre du programme en cas d’erreur
    }


    ConnexionControlleur connexionCtrl(db);
    bool connexionReussie = connexionCtrl.verifierUtilisateur("jean.dupont@example.com", "secure123");

    if (connexionReussie) {
        std::cout << "Connexion réussie ! Bienvenue Jean Dupont.\n";
    } else {
        std::cout << "Échec de la connexion : Email ou mot de passe incorrect.\n";
    }
    return 0;
}