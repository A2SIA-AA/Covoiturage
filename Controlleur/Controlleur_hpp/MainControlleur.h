#ifndef MAINCONTROLLEUR_H
#define MAINCONTROLLEUR_H

//les fenetre
#include "../../Interface/Interface_graphique/headers/InscriptionFenetre.h"
#include "../../Interface/Interface_graphique/headers/ConnexionFenetre.h"
#include "../../Interface/Interface_graphique/headers/AccueilFenetre.h"
#include "../../Interface/Interface_graphique/headers/ModifierProfilFenetre.h"
#include "../../Interface/Interface_graphique/headers/PublierTrajetFenetre.h"
#include "../../Interface/Interface_graphique/headers/RechercherTrajetFenetre.h"
#include "../../Interface/Interface_graphique/headers/MesAnnoncesFenetre.h"
#include "../../Interface/Interface_graphique/headers/DetailTrajetFenetre.h"
#include "../../Interface/Interface_graphique/headers/DetailTrajetReservationFenetre.h"
#include "../../Interface/Interface_graphique/headers/MesReservationsFenetre.h"

//les controlleurs
#include "InscriptionControlleur.hpp"
#include "ConnexionControlleur.hpp"
#include "ModifierProfilControlleur.hpp"
#include "TrajetControlleur.hpp"
#include "RechercheControlleur.hpp"

//base de données
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"


#include <QObject>

class MainControlleur : public QObject {
    Q_OBJECT

public:
    MainControlleur();
    void demarrerApplication();
    ~MainControlleur();


private:
    Database base;

    // controlleur
    InscriptionControlleur inscriptionControlleur;
    ConnexionControlleur connexionControlleur;
    ModifierProfilControlleur modifierProfilControlleur;
    TrajetControlleur trajetControlleur;
    RechercheControlleur rechercheControlleur;

    // fenetre
    InscriptionFenetre *fenetreInscription;
    ConnexionFenetre* fenetreConnexion;
    AccueilFenetre* fenetreAccueil;
    ModifierProfilFenetre* fenetreModifierProfil;
    PublierTrajetFenetre* fenetrePublierTrajet;
    RechercherTrajetFenetre *fenetreRechercherTrajet;
    MesAnnoncesFenetre* fenetreMesAnnonces;
    DetailTrajetFenetre* fenetreDetailTrajet;
    DetailTrajetReservationFenetre * fenetreDetailReservation;
    MesReservationsFenetre *fenetreMesReservations;



    std::optional<Utilisateur> utilisateurConnecte;
    std::vector<Trajet> trajetsCourants;


    void connecterSignauxSlots();
};




#endif // MAINCONTROLLEUR_H
