#include "../Controlleur_hpp/MainControlleur.h"
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <vector>
#include <map>
#include <optional>


MainControlleur::MainControlleur()
    : base("database.sqlite"),
    inscriptionControlleur(base),
    connexionControlleur(base),
    modifierProfilControlleur(base),
    trajetControlleur(base),
    rechercheControlleur(base),
    fenetreInscription(new InscriptionFenetre),
    fenetreConnexion(new ConnexionFenetre),
    fenetreAccueil(new AccueilFenetre),
    fenetreModifierProfil(new ModifierProfilFenetre),
    fenetrePublierTrajet(new PublierTrajetFenetre),
    fenetreRechercherTrajet(new RechercherTrajetFenetre),
    fenetreMesAnnonces(new MesAnnoncesFenetre),
    fenetreMesReservations(new MesReservationsFenetre),
    fenetreDetailTrajet(nullptr),
    fenetreDetailReservation(nullptr),
    utilisateurConnecte(std::nullopt)
{
    connecterSignauxSlots();
}

void MainControlleur::demarrerApplication() {
    fenetreInscription->show();
}

void MainControlleur::connecterSignauxSlots() {

    // 🔁 Passage de l'inscription vers la connexion
    QObject::connect(fenetreInscription, &InscriptionFenetre::retourConnexion, [=]() {
        fenetreInscription->hide();
        fenetreConnexion->reinitialiserChamps();
        fenetreConnexion->show();
    });

    // 🔁 Connexion → Inscription
    QObject::connect(fenetreConnexion, &ConnexionFenetre::demandeInscription, [=]() {
        fenetreConnexion->hide();
        fenetreInscription->reinitialiserChamps();
        fenetreInscription->show();
    });

    // Connecte le signal du bouton d'inscription à la méthode traiterInscription
    QObject::connect(fenetreInscription, &InscriptionFenetre::inscriptionDemandee,
                     [=](QString nom, QString prenom, QString email, QString motDePasse, QString adressePostale, bool fumeur) {
                         try {
                             inscriptionControlleur.traiterInscription(
                                 nom.toStdString(),
                                 prenom.toStdString(),
                                 email.toStdString(),
                                 motDePasse.toStdString(),
                                 adressePostale.toStdString(),
                                 fumeur
                                 );

                             QMessageBox::information(
                                 fenetreInscription,
                                 "Inscription réussie",
                                 "Votre inscription a bien été enregistrée.\nVous pouvez dès à présent vous connecter."
                                 );

                             fenetreInscription->hide();
                             fenetreConnexion->reinitialiserChamps();
                             fenetreConnexion->show();

                         } catch (const std::exception &e) {
                             qDebug() << "Erreur inscription attrapée : " << e.what();
                             QMessageBox::critical(
                                 fenetreInscription,
                                 "Erreur d'inscription",
                                 QString("Échec de l'inscription :\n") + e.what()
                                 );
                             // la fenêtre reste affichée pour corriger
                         }
                     });


    // ✅ Traitement de la connexion
    QObject::connect(fenetreConnexion, &ConnexionFenetre::connexionDemandee,
                     [=](QString email, QString motDePasse) {
                         try {
                             std::optional<Utilisateur> utilisateur = connexionControlleur.verifierUtilisateur(
                                 email.toStdString(), motDePasse.toStdString()
                                 );

                             if (utilisateur.has_value()) {
                                 utilisateurConnecte = utilisateur;
                                 qDebug() << "Connexion réussie : " << QString::fromStdString(utilisateur->getNom());
                                 fenetreConnexion->hide();
                                 fenetreAccueil->show();
                             }
                         } catch (const std::exception &e) {
                             qDebug() << "Erreur attrapée : " << e.what();
                             QMessageBox::critical(
                                 fenetreConnexion,
                                 "Échec de connexion",
                                 "Utilisateur non trouvé.\nVérifiez votre email ou mot de passe.\nOu créez un compte."
                                 );
                         }
                     });




    // 🔁 Accueil → autre page
    QObject::connect(fenetreAccueil, &AccueilFenetre::demandeNavigation,
                     [=](const QString &nomPage) {
                         fenetreAccueil->hide();

                        if (nomPage == "modifierProfil") {
                            if (utilisateurConnecte.has_value()) {
                                fenetreModifierProfil->reinitialiserChamps();
                                fenetreModifierProfil->afficherUtilisateur(utilisateurConnecte.value()); // ✅ Ajout
                                fenetreModifierProfil->show();
                            } else {
                                QMessageBox::warning(fenetreAccueil, "Erreur", "Aucun utilisateur connecté.");
                                fenetreInscription->show();
                            }
                        }
                          else if (nomPage == "publierTrajet") {
                             fenetrePublierTrajet->reinitialiserChamps();
                             fenetrePublierTrajet->show();
                         } else if (nomPage == "rechercherTrajet") {
                             fenetreRechercherTrajet->reinitialiserChamps();
                             fenetreRechercherTrajet->show();
                         } else if (nomPage == "mesAnnonces") {
                             if (utilisateurConnecte.has_value()) {
                                 std::vector<Trajet> annonces = trajetControlleur.obtenirTrajetsUtilisateur(
                                     utilisateurConnecte->getIdUtilisateur()
                                     );
                                 fenetreMesAnnonces->afficherAnnonces(annonces);
                                 fenetreMesAnnonces->show();
                             } else {
                                 QMessageBox::warning(fenetreAccueil, "Erreur", "Aucun utilisateur connecté.");
                                 fenetreInscription->show();
                             }
                         } else if (nomPage == "deconnecter") {
                             utilisateurConnecte = std::nullopt;
                             QMessageBox::information(fenetreAccueil, "Déconnexion", "Vous avez été déconnecté.");
                             fenetreConnexion->reinitialiserChamps();
                             fenetreInscription->reinitialiserChamps();
                             fenetreInscription->show();
                         }else if (nomPage == "mesReservations") {
                             if (utilisateurConnecte.has_value()) {
                                 std::map<Reservation, Trajet> reservations = trajetControlleur.obtenirResvervationEtTrajetUtilisateur(
                                     utilisateurConnecte->getIdUtilisateur()
                                     );

                                 for (const auto& pair : reservations) {
                                     const Reservation& r = pair.first;
                                     const Trajet& t = pair.second;
                                 }

                                 fenetreMesReservations->afficherReservations(reservations);
                                 fenetreMesReservations->show();
                             } else {
                                 QMessageBox::warning(fenetreAccueil, "Erreur", "Aucun utilisateur connecté.");
                                 fenetreInscription->show();
                             }
                         }


                     });



    // ✅ Modifier Profil → ModifierProfilControlleur
    QObject::connect(fenetreModifierProfil, &ModifierProfilFenetre::modificationDemandee,
                     [=](const QString &champ, const QString &valeur) {
                         if (utilisateurConnecte.has_value()) {
                             modifierProfilControlleur.ModifierProfil(
                                 utilisateurConnecte->getIdUtilisateur(),
                                 champ.toStdString(),
                                 valeur.toStdString()
                                 );
                             qDebug() << "Modification demandée pour" << champ << "=>" << valeur;
                         } else {
                             qDebug() << "Aucun utilisateur connecté. Modification ignorée.";
                         }
                     });

    // 🔁 Retour vers l'accueil depuis ModifierProfil
    QObject::connect(fenetreModifierProfil, &ModifierProfilFenetre::retourAccueil, [=]() {
        fenetreModifierProfil->hide();
        fenetreAccueil->show();
    });

    // ✅ Publier Trajet → appeler creerTrajet() via trajetSoumis
    QObject::connect(fenetrePublierTrajet, &PublierTrajetFenetre::trajetSoumis,
                     [=](const QString &date,
                         const QString &heureDepart,
                         const QString &heureArrivee,
                         const QString &lieuDepart,
                         const QString &lieuArrivee,
                         float prix,
                         float distance,
                         const QString &voiture,
                         int nombrePlaces,
                         float consommation,
                         int anciennete,
                         const QString &carburant,
                         const QString &description,
                         bool animaux) {

                         if (utilisateurConnecte.has_value()) {
                             std::vector<std::pair<std::string, float>> segmentsPrix = {
                                 {lieuArrivee.toStdString(), prix}
                             };
                             std::vector<std::string> villesEtapes = {};  // vide
                             bool disponible = true;
                             bool allerRetour = false;
                             bool etat = true;

                             trajetControlleur.creerTrajet(
                                 utilisateurConnecte->getIdUtilisateur(),
                                 date.toStdString(),
                                 heureDepart.toStdString(),
                                 heureArrivee.toStdString(),
                                 lieuDepart.toStdString(),
                                 lieuArrivee.toStdString(),
                                 segmentsPrix,
                                 villesEtapes,
                                 disponible,
                                 allerRetour,
                                 animaux,
                                 voiture.toStdString(),
                                 nombrePlaces,
                                 etat,
                                 consommation,  // utilisé ici pour emissionCO2
                                 description.toStdString()
                                 );

                             qDebug() << "✅ Trajet publié avec succès.";
                             QMessageBox::information(fenetrePublierTrajet, "Trajet publié", "Votre trajet a bien été publié.");
                             fenetrePublierTrajet->hide();
                             fenetreAccueil->show();
                         } else {
                             qDebug() << "❌ Aucun utilisateur connecté. Publication échouée.";
                             QMessageBox::warning(fenetrePublierTrajet, "Erreur", "Aucun utilisateur connecté.");
                         }
                     });


    // 🔁 Retour vers l'accueil depuis PublierTrajet
    QObject::connect(fenetrePublierTrajet, &PublierTrajetFenetre::retourAccueil, [=]() {
        fenetrePublierTrajet->hide();
        fenetreAccueil->show();
    });


    // 🔁 Retour vers l'accueil depuis RechercherTrajet
    QObject::connect(fenetreRechercherTrajet, &RechercherTrajetFenetre::retourAccueil, [=]() {
        fenetreRechercherTrajet->hide();
        fenetreAccueil->show();
    });

    //Rechercher un Trajet
    QObject::connect(fenetreRechercherTrajet, &RechercherTrajetFenetre::rechercheLancee,
                     [=](QString lieuDepart, QString lieuArrivee, QString date) {
                         std::vector<Trajet> trajetsTrouves = rechercheControlleur.rechercherTrajet(
                             lieuDepart.toStdString(),
                             lieuArrivee.toStdString(),
                             date.toStdString()
                             );
                            qDebug() << "Trajets reçus: " << trajetsTrouves.size();
                            for (const Trajet& t : trajetsTrouves) {
                                qDebug() << "Trajet id:" << t.getIdTrajet()
                                << " | Lieu départ:" << QString::fromStdString(t.getLieuDepart())
                                << " | Heure départ:" << QString::fromStdString(t.getHeureDepart())
                                << " | Segments prix:" << t.getSegmentsPrix().size();  // ⚠️ à surveiller ici !
                            }

                         trajetsCourants = rechercheControlleur.comparer(trajetsTrouves);

                         fenetreRechercherTrajet->afficherResultats(trajetsCourants);
                     });


    // 🔁 RechercherTrajet → application d’un filtre
    QObject::connect(fenetreRechercherTrajet, &RechercherTrajetFenetre::filtrageDemande,
                     [=](const QString &critere) {
                         if (trajetsCourants.empty()) {
                             QMessageBox::information(fenetreRechercherTrajet, "Aucun trajet", "Aucun trajet à filtrer. Lancez une recherche d'abord.");
                             return;
                         }

                         std::vector<Trajet> tries;

                         if (critere == "Prix") {
                             tries = rechercheControlleur.comparerPrix(trajetsCourants);
                         } else if (critere == "CO2") {
                             tries = rechercheControlleur.comparerEmission(trajetsCourants);
                         } else if (critere == "Heure") {
                             tries = rechercheControlleur.comparerHeureDepart(trajetsCourants);
                         } else if (critere == "Duree") {
                             tries = rechercheControlleur.comparerDuree(trajetsCourants);
                         } else {
                             QMessageBox::warning(fenetreRechercherTrajet, "Filtrage", "Critère de filtrage non reconnu.");
                             return;
                         }

                         fenetreRechercherTrajet->afficherResultats(tries);
                     });


    // 🔁 Retour vers l'accueil depuis MesAnnonces
    QObject::connect(fenetreMesAnnonces, &MesAnnoncesFenetre::retourAccueil, [=]() {
        fenetreMesAnnonces->hide();
        fenetreAccueil->show();
    });

    //suppresion d'une annonces
    QObject::connect(fenetreMesAnnonces, &MesAnnoncesFenetre::demandeSuppression,
                     [=](int idTrajet) {
                         try {
                             trajetControlleur.supprimerTrajet(idTrajet);
                             QMessageBox::information(fenetreMesAnnonces, "Suppression", "Trajet supprimé avec succès.");

                             // 🔁 Recharger les annonces après suppression
                             if (utilisateurConnecte.has_value()) {
                                 std::vector<Trajet> annonces = trajetControlleur.obtenirTrajetsUtilisateur(
                                     utilisateurConnecte->getIdUtilisateur()
                                     );
                                 fenetreMesAnnonces->afficherAnnonces(annonces);
                             }
                         } catch (const std::exception &e) {
                             qDebug() << "Erreur lors de la suppression : " << e.what();
                             QMessageBox::critical(fenetreMesAnnonces, "Erreur", QString("Impossible de supprimer le trajet :\n") + e.what());
                         }
                     });


    // 🔁 Trajet sélectionné dans mes annonces → ouvrir détail trajet
    QObject::connect(fenetreMesAnnonces, &MesAnnoncesFenetre::annonceSelectionnee,
                     [=](const Trajet& trajet) {
                         if (fenetreDetailTrajet) delete fenetreDetailTrajet;
                         fenetreDetailTrajet = new DetailTrajetFenetre(trajet);
                         QObject::connect(fenetreDetailTrajet, &DetailTrajetFenetre::fermetureFenetre, [=]() {
                             fenetreDetailTrajet->hide();
                             fenetreMesAnnonces->show();
                         });
                         fenetreMesAnnonces->hide();
                         fenetreDetailTrajet->show();
                     });

    // 🔁 Trajet sélectionné dans la recherche → ouvrir fenêtre de réservation
    QObject::connect(fenetreRechercherTrajet, &RechercherTrajetFenetre::trajetClique,
                     [=](const Trajet &trajet) {
                         if (fenetreDetailReservation) delete fenetreDetailReservation;
                         fenetreDetailReservation = new DetailTrajetReservationFenetre(trajet);
                         QObject::connect(fenetreDetailReservation, &DetailTrajetReservationFenetre::fermetureFenetre, [=]() {
                             fenetreDetailReservation->hide();
                             fenetreRechercherTrajet->show();
                         });
                         QObject::connect(fenetreDetailReservation, &DetailTrajetReservationFenetre::trajetReserve,
                                          [=](const Trajet& t) {
                                              if (utilisateurConnecte.has_value()) {
                                                  trajetControlleur.reservation(t.getIdTrajet(), t. getSegmentsPrix().front().second, utilisateurConnecte->getIdUtilisateur(), true);
                                                  QMessageBox::information(fenetreDetailReservation, "Réservation", "Votre réservation a bien été enregistrée.");
                                              }
                                          });
                         fenetreRechercherTrajet->hide();
                         fenetreDetailReservation->show();
                     });

    // 🔁 Retour vers l'accueil depuis MesReservations
    QObject::connect(fenetreMesReservations, &MesReservationsFenetre::retourAccueil, [=]() {
        fenetreMesReservations->hide();
        fenetreAccueil->show();
    });

    //Supppresion d'une reservation
    QObject::connect(fenetreMesReservations, &MesReservationsFenetre::demandeSuppression,
                     [=](int idReservation) {
                         try {
                             trajetControlleur.supprimerReservation(idReservation);
                             QMessageBox::information(fenetreMesReservations, "Suppression", "Réservation supprimée avec succès.");

                             // 🔁 Recharge les réservations
                             if (utilisateurConnecte.has_value()) {
                                 std::map<Reservation, Trajet> reservations = trajetControlleur.obtenirResvervationEtTrajetUtilisateur(
                                     utilisateurConnecte->getIdUtilisateur()
                                     );
                                 fenetreMesReservations->afficherReservations(reservations);
                             }
                         } catch (const std::exception &e) {
                             qDebug() << "Erreur suppression réservation : " << e.what();
                             QMessageBox::critical(fenetreMesReservations, "Erreur", QString("Erreur lors de la suppression :\n") + e.what());
                         }
                     });



    // Connecte le signal messageInscription au slot afficherMessage
   // QObject::connect(&inscriptionControlleur, &InscriptionControlleur::messageInscription,
                     //fenetreInscription, &InscriptionFenetre::afficherMessage);
}


MainControlleur::~MainControlleur() {
    delete fenetreInscription;
    delete fenetreConnexion;
    delete fenetreAccueil;
    delete fenetreModifierProfil;
    delete fenetrePublierTrajet;
    delete fenetreRechercherTrajet;
    delete fenetreMesAnnonces;
    delete fenetreDetailTrajet;
    delete fenetreDetailReservation;
    delete fenetreMesReservations;
}
