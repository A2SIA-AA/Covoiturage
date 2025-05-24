#include "AccueilControlleur.hpp"
#include "../../Interface/Interface_hpp/Console_hpp/AccueilConsole.hpp"
#include "../../Interface/Interface_hpp/RechercheInterface.hpp"
#include "../../Interface/Interface_hpp/MesReservationsInterface.hpp"
#include "../../Interface/Interface_hpp/MesAnnoncesInterface.hpp"

AccueilControlleur::AccueilControlleur(){}


void AccueilControlleur::TraiterModifierProfil() {
    AccueilConsole vue;
    vue.accueil();
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