#include "AccueilControlleur.hpp"
#include "../../Interface/Interface_hpp/ModifierProfilInterface.hpp"
#include "../../Interface/Interface_hpp/RechercheInterface.hpp"
#include "../../Interface/Interface_hpp/MesReservationsInterface.hpp"
#include "../../Interface/Interface_hpp/MesAnnoncesInterface.hpp"

void AccueilControlleur::TraiterModifierProfil() {
    ModifierProfilInterface vue;
    vue.afficher();
}

void AccueilControlleur::TraiterRecherche() {
    RechercheInterface vue;
    vue.afficher();
}

void AccueilControlleur::TraiterMesReservation() {
    MesReservations vue;
    vue.afficher();
}

void AccueilControlleur::TraiterMesAnnonces() {
    MesAnnoncesInterface vue;
    vue.afficher();
}