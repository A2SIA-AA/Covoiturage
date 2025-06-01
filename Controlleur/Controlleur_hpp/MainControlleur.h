/**
 * @file MainControlleur.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe MainControlleur, contrôleur central de l'application. 
 * @version 0.1
 * 
 * Cette classe agit comme le point d'entrée principal de l’application. Elle centralise
 * la gestion des fenêtres, la navigation entre elles, ainsi que l’interaction entre l’interface graphique,
 * les contrôleurs métiers et la base de données.
 */
#ifndef MAINCONTROLLEUR_H
#define MAINCONTROLLEUR_H

// les fenêtres
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

// les contrôleurs
#include "InscriptionControlleur.hpp"
#include "ConnexionControlleur.hpp"
#include "ModifierProfilControlleur.hpp"
#include "TrajetControlleur.hpp"
#include "RechercheControlleur.hpp"

// base de données
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"


#include <QObject>

/**
 * @class MainControlleur
 * @brief Contrôleur principal orchestrant les interactions entre les composants de l'application.
 */
class MainControlleur : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Constructeur du contrôleur principal.
     * Initialise la base, les fenêtres et les contrôleurs.
     */
    MainControlleur();

     /**
     * @brief Démarre l'application en affichant la fenêtre d'inscription.
     */
    void demarrerApplication();

    /**
     * @brief Destructeur du contrôleur principal.
     * Libère la mémoire allouée pour les fenêtres.
     */
    ~MainControlleur();


private:
    Database base;

    // contrôleurs
    InscriptionControlleur inscriptionControlleur;
    ConnexionControlleur connexionControlleur;
    ModifierProfilControlleur modifierProfilControlleur;
    TrajetControlleur trajetControlleur;
    RechercheControlleur rechercheControlleur;

    // fenêtres
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

    /**
     * @brief Connecte tous les signaux et slots entre les fenêtres et les contrôleurs.
     */
    void connecterSignauxSlots();

    /**
     * @brief Met à jour l'utilisateur connecté en mémoire après une modification.
     *
     * Cette méthode est appelée après la modification en base de données pour
     * synchroniser les champs de l'objet utilisateur en mémoire avec les nouvelles valeurs saisies.
     *
     * @param champ Le champ modifié ("nom", "prenom", "email", "motPasse", "adressePostal", "fumeur").
     * @param valeur La nouvelle valeur à affecter au champ.
     */
    void mettreAJourUtilisateur(const QString &champ, const QString &valeur);



};




#endif 
