//#include "headers/AccueilFenetre.h"
//#include "headers/ConnexionFenetre.h"
//#include "headers/InscriptionFenetre.h"
//#include "headers/MesAnnoncesFenetre.h"
//#include "headers/DetailTrajetFenetre.h"
//#include "headers/AjoutTrajetFenetre.h"
//#include "headers/Trajet.hpp"
//#include "headers/RechercherTrajetFenetre.h"
//#include "headers/DetailTrajetReservationFenetre.h"
//#include "headers/PublierTrajetFenetre.h"
//#include "headers/ModifierProfilFenetre.h"
//#include "headers/MesReservationsFenetre.h"
//#include "headers/Reservation.hpp"
#include "Controlleur/Controlleur_hpp/MainControlleur.h"
#include <QApplication>
#include <QDebug>
//#include <string>
//#include <map>

int main(int argc, char *argv[])
{
    // Initialisation de l'application Qt
    /**QApplication app(argc, argv);

    // Création de la fenêtre principale
    AccueilFenetre fenetre;

    // Affichage de la fenêtre
    fenetre.show();

    // Exécution de la boucle d'événements de l'application
    return app.exec();**/

   /**QApplication app(argc, argv);

    ConnexionFenetre fenetre;
    fenetre.setWindowTitle("Page de Connexion");
    fenetre.show();

    return app.exec();**/

   /**QApplication app(argc, argv);

   InscriptionFenetre fenetre;
   fenetre.setWindowTitle("Inscription - Covoiturage");
   fenetre.show();

   // Connexion des signaux pour test console
   QObject::connect(&fenetre, &InscriptionFenetre::inscriptionDemandee,
                    [](QString nom, QString prenom, QString email, QString motDePasse, bool fumeur) {
                        qDebug() << "Inscription reçue :";
                        qDebug() << "Nom:" << nom;
                        qDebug() << "Prénom:" << prenom;
                        qDebug() << "Email:" << email;
                        qDebug() << "Mot de passe:" << motDePasse;
                        qDebug() << "Fumeur ?" << (fumeur ? "Oui" : "Non");
                    });

   QObject::connect(&fenetre, &InscriptionFenetre::retourConnexion, []() {
       qDebug() << "Redirection vers la page de connexion demandée.";
   });

   return app.exec();**/

   /**QApplication app(argc, argv);

   // Création de la fenêtre principale
   MesAnnoncesFenetre window;

   // Connexion du signal pour tester
   QObject::connect(&window, &MesAnnoncesFenetre::annonceSelectionnee,
                    [](const Trajet &trajet) {
                        qDebug() << "Signal reçu pour le trajet :"
                                 << QString::fromStdString(trajet.getLieuDepart())
                                 << "→"
                                 << QString::fromStdString(trajet.getLieuArrive());
                    });

   std::vector<Trajet> trajets;

   trajets.emplace_back(
       std::string("25/05"),
       std::string("08:00"),
       std::string("10:00"),
       std::string("Paris"),
       std::string("Lyon"),
       std::vector<std::pair<std::string, float>>{},
       std::vector<std::string>{"Melun"},
       true, false, false,
       std::string("Peugeot"),
       3, false, 150.0f,
       std::string("Test trajet 1")
       );

   trajets.emplace_back(
       std::string("26/05"),
       std::string("14:00"),
       std::string("15:30"),
       std::string("Rouen"),
       std::string("Le Havre"),
       std::vector<std::pair<std::string, float>>{},
       std::vector<std::string>{},
       true, false, false,
       std::string("Renault"),
       2, true, 120.0f,
       std::string("Test trajet 2")
       );

   window.afficherAnnonces(trajets);
   window.show();

   return app.exec();**/

  /** QApplication app(argc, argv);

   // Création d'un exemple de trajet
   Trajet t(
       std::string("25/05"),
       std::string("08:00"),
       std::string("10:30"),
       std::string("Paris"),
       std::string("Lyon"),
       std::vector<std::pair<std::string, float>>{
           {"Paris-Rouen", 10.5}, {"Rouen-Lyon", 20.0}
       },
       std::vector<std::string>{"Rouen"},
       true, true, false,
       std::string("Peugeot 208"),
       2, false, 143.2f,
       std::string("Confortable, climatisée.")
       );

   // Création et affichage de la fenêtre
   DetailTrajetFenetre *fenetre = new DetailTrajetFenetre(t);
   QObject::connect(fenetre, &DetailTrajetFenetre::fermetureFenetre, [](){
       qDebug() << "Fermeture de la fenêtre de détails déclenchée.";
   });

   fenetre->show();

   return app.exec();**/



    /**QApplication app(argc, argv);

       // Création de trajets de test avec ta syntaxe
       Trajet t1(
           std::string("25/05"),
           std::string("08:00"),
           std::string("10:30"),
           std::string("Paris"),
           std::string("Lyon"),
           std::vector<std::pair<std::string, float>>{
               {"Paris-Rouen", 10.5f}, {"Rouen-Lyon", 20.0f}
           },
           std::vector<std::string>{"Rouen"},
           true, true, false,
           std::string("Peugeot 208"),
           2, false, 143.2f,
           std::string("Confortable, climatisée.")
           );

       Trajet t2(
           std::string("10/05"),
           std::string("17:00"),
           std::string("20:00"),
           std::string("Lyon"),
           std::string("Marseille"),
           std::vector<std::pair<std::string, float>>{
               {"Lyon-Valence", 8.0f}, {"Valence-Marseille", 12.0f}
           },
           std::vector<std::string>{"Valence"},
           true, false, true,
           std::string("Clio"),
           3, true, 158.0f,
           std::string("Trajet retour week-end")
           );

       std::vector<Trajet> trajets = {t1, t2};

       // Fenêtre des annonces
       MesAnnoncesFenetre *fenetreAnnonces = new MesAnnoncesFenetre;
       fenetreAnnonces->afficherAnnonces(trajets);
       fenetreAnnonces->show();

       // Connexion à la fenêtre de détail
       QObject::connect(fenetreAnnonces, &MesAnnoncesFenetre::annonceSelectionnee,
                        [=](const Trajet& trajet) {
                            DetailTrajetFenetre *fenetreDetail = new DetailTrajetFenetre(trajet);
                            fenetreDetail->show();
                            fenetreAnnonces->hide();

                            QObject::connect(fenetreDetail, &DetailTrajetFenetre::fermetureFenetre, [=]() {
                                fenetreAnnonces->show();
                            });
                        });

       return app.exec();**/

    /**QApplication app(argc, argv);

    AjoutTrajetFenetre *fenetre = new AjoutTrajetFenetre;
    fenetre->show();

    QObject::connect(fenetre, &AjoutTrajetFenetre::trajetSoumis,
                     [](QString date, QString heureDepart, QString heureArrivee,
                        QString lieuDepart, QString lieuArrivee, QString voiture,
                        int nbPlaces, double conso, int anciennete,
                        QString carburant, QString description) {
                         qDebug() << "Trajet soumis avec les infos suivantes :";
                         qDebug() << "Date:" << date;
                         qDebug() << "Heure départ:" << heureDepart;
                         qDebug() << "Heure arrivée:" << heureArrivee;
                         qDebug() << "Départ:" << lieuDepart;
                         qDebug() << "Arrivée:" << lieuArrivee;
                         qDebug() << "Voiture:" << voiture;
                         qDebug() << "Places:" << nbPlaces;
                         qDebug() << "Consommation (L/100km):" << conso;
                         qDebug() << "Ancienneté (années):" << anciennete;
                         qDebug() << "Carburant:" << carburant;
                         qDebug() << "Description:" << description;
                     });

    return app.exec();**/

    /**QApplication app(argc, argv);

    RechercherTrajetFenetre *rechercheFenetre = new RechercherTrajetFenetre;
    rechercheFenetre->show();

    // Création de trajets de test avec ta syntaxe
    Trajet t1(
        std::string("25/05"),
        std::string("08:00"),
        std::string("10:30"),
        std::string("Paris"),
        std::string("Lyon"),
        std::vector<std::pair<std::string, float>>{
            {"Paris-Rouen", 10.5f}, {"Rouen-Lyon", 20.0f}
        },
        std::vector<std::string>{"Rouen"},
        true, true, false,
        std::string("Peugeot 208"),
        2, false, 143.2f,
        std::string("Confortable, climatisée.")
        );

    Trajet t2(
        std::string("10/05"),
        std::string("17:00"),
        std::string("20:00"),
        std::string("Lyon"),
        std::string("Marseille"),
        std::vector<std::pair<std::string, float>>{
            {"Lyon-Valence", 8.0f}, {"Valence-Marseille", 12.0f}
        },
        std::vector<std::string>{"Valence"},
        true, false, true,
        std::string("Clio"),
        3, true, 158.0f,
        std::string("Trajet retour week-end")
        );

    std::vector<Trajet> trajets = {t1, t2};

    // Connecte la recherche de trajets
    QObject::connect(rechercheFenetre, &RechercherTrajetFenetre::rechercheLancee,
                     [=](QString depart, QString arrivee, QString date) {
                         qDebug() << "Recherche reçue pour :" << depart << "→" << arrivee << "le" << date;
                         rechercheFenetre->afficherResultats(trajets);
                     });

    // Connecte le filtrage
    QObject::connect(rechercheFenetre, &RechercherTrajetFenetre::filtrageDemande,
                     [=](QString critere) {
                         qDebug() << "Filtrage demandé par :" << critere;
                         rechercheFenetre->afficherResultats(trajets); // (pas encore filtré pour l'instant)
                     });

    // Quand on clique sur un trajet
    QObject::connect(rechercheFenetre, &RechercherTrajetFenetre::trajetClique,
                     [](const Trajet &t) {
                         qDebug() << "Trajet sélectionné :"
                                  << QString::fromStdString(t.getLieuDepart())
                                  << "→" << QString::fromStdString(t.getLieuArrive())
                                  << "| Départ à" << QString::fromStdString(t.getHeureDepart());
                     });

    return app.exec(); **/

    /**QApplication app(argc, argv);

    RechercherTrajetFenetre *recherche = new RechercherTrajetFenetre;
    recherche->show();

    // Création des trajets de test avec setIdTrajet()
    Trajet t1(
        std::string("2025-06-01"),
        std::string("08:00"),
        std::string("10:30"),
        std::string("Paris"),
        std::string("Lyon"),
        std::vector<std::pair<std::string, float>>{
            {"Paris-Rouen", 10.5f},
            {"Rouen-Lyon", 20.0f}
        },
        std::vector<std::string>{"Rouen"},
        true, true, false,
        std::string("Peugeot 208"),
        2, false, 143.2f,
        std::string("Confortable, climatisée.")
        );
    t1.setIdTrajet(1);

    Trajet t2(
        std::string("2025-06-02"),
        std::string("14:00"),
        std::string("17:00"),
        std::string("Lyon"),
        std::string("Marseille"),
        std::vector<std::pair<std::string, float>>{
            {"Lyon-Valence", 8.0f},
            {"Valence-Marseille", 12.0f}
        },
        std::vector<std::string>{"Valence"},
        true, false, true,
        std::string("Renault Clio"),
        3, false, 158.0f,
        std::string("Trajet retour week-end")
        );
    t2.setIdTrajet(2);

    std::vector<Trajet> tousLesTrajets = {t1, t2};

    // Connexion : quand on clique sur "Rechercher"
    QObject::connect(recherche, &RechercherTrajetFenetre::rechercheLancee,
                     [=](QString depart, QString arrivee, QString date) {
                         qDebug() << "Recherche lancée pour :" << depart << "->" << arrivee << "le" << date;
                         // Pour l’instant on affiche tous les trajets (simule un retour du contrôleur)
                         recherche->afficherResultats(tousLesTrajets);
                     });

    // Connexion : quand on clique sur "Filtrer" (même résultats pour test)
    QObject::connect(recherche, &RechercherTrajetFenetre::filtrageDemande,
                     [=](QString critere) {
                         qDebug() << "Filtrage demandé sur :" << critere;
                         recherche->afficherResultats(tousLesTrajets);
                     });

    // Connexion : quand on clique sur un trajet
    QObject::connect(recherche, &RechercherTrajetFenetre::trajetClique,
                     [=](const Trajet& t) {
                         DetailTrajetReservationFenetre *detail = new DetailTrajetReservationFenetre(t);
                         detail->show();

                         // Si l’utilisateur clique sur "Réserver"
                         QObject::connect(detail, &DetailTrajetReservationFenetre::trajetReserve,
                                          [](const Trajet& reserve) {
                                              qDebug() << "🚗 Trajet réservé :"
                                                       << QString::fromStdString(reserve.getLieuDepart())
                                                       << "→" << QString::fromStdString(reserve.getLieuArrive())
                                                       << "| ID:" << reserve.getIdTrajet();
                                              // Ici, tu pourrais appeler ton contrôleur pour enregistrer la réservation
                                          });

                         // Si l’utilisateur clique sur "Retour"
                         QObject::connect(detail, &DetailTrajetReservationFenetre::fermetureFenetre,
                                          detail, &QWidget::deleteLater);
                     });

    return app.exec();**/

    /**QApplication app(argc, argv);

    PublierTrajetFenetre *fenetre = new PublierTrajetFenetre;
    fenetre->show();

    QObject::connect(fenetre, &PublierTrajetFenetre::trajetSoumis,
                     [](const QString& date,
                        const QString& heureDepart,
                        const QString& heureArrivee,
                        const QString& lieuDepart,
                        const QString& lieuArrivee,
                        float prix,
                        float distance,
                        const QString& voiture,
                        int nombrePlaces,
                        float consommation,
                        int anciennete,
                        const QString& carburant,
                        const QString& description) {

                         qDebug() << "🚗 Trajet soumis :";
                         qDebug() << "📅 Date :" << date;
                         qDebug() << "🕒 Départ :" << heureDepart << "| Arrivée :" << heureArrivee;
                         qDebug() << "📍 De" << lieuDepart << "à" << lieuArrivee;
                         qDebug() << "💰 Prix :" << prix << "€";
                         qDebug() << "🛣 Distance :" << distance << "km";
                         qDebug() << "🚘 Voiture :" << voiture;
                         qDebug() << "👥 Places :" << nombrePlaces;
                         qDebug() << "⛽ Conso :" << consommation << "L/100km";
                         qDebug() << "📆 Ancienneté :" << anciennete << "an(s)";
                         qDebug() << "⚡ Carburant :" << carburant;
                         qDebug() << "📝 Description :" << description;
                     });

    return app.exec();**/

   /** QApplication app(argc, argv);

    ModifierProfilFenetre *fenetre = new ModifierProfilFenetre;
    fenetre->show();

    QObject::connect(fenetre, &ModifierProfilFenetre::modificationDemandee,
                     [](const QString &champ, const QString &valeur) {
                         qDebug() << "🔧 Modification demandée :";
                         qDebug() << "Champ :" << champ;
                         qDebug() << "Nouvelle valeur :" << valeur;
                     });

    return app.exec();**/

    /**QApplication app(argc, argv);

    // ✅ Création des trajets exactement comme demandé
    Trajet t1(
        std::string("25/05"),
        std::string("08:00"),
        std::string("10:30"),
        std::string("Paris"),
        std::string("Lyon"),
        std::vector<std::pair<std::string, float>>{
            {"Paris-Rouen", 10.5f}, {"Rouen-Lyon", 20.0f}
        },
        std::vector<std::string>{"Rouen"},
        true, true, false,
        std::string("Peugeot 208"),
        2, false, 143.2f,
        std::string("Confortable, climatisée.")
        );
    t1.setIdTrajet(101);

    Trajet t2(
        std::string("10/05"),
        std::string("17:00"),
        std::string("20:00"),
        std::string("Lyon"),
        std::string("Marseille"),
        std::vector<std::pair<std::string, float>>{
            {"Lyon-Valence", 8.0f}, {"Valence-Marseille", 12.0f}
        },
        std::vector<std::string>{"Valence"},
        true, false, true,
        std::string("Renault Clio"),
        3, true, 158.0f,
        std::string("Trajet retour week-end")
        );
    t2.setIdTrajet(102);

    // ✅ Réservations associées
    Reservation r1(25.0f, false);  // à venir
    r1.setIdReservation(1);
    r1.setIdPassager(1001);
    r1.setIdTrajet(101);

    Reservation r2(42.5f, true);   // passée
    r2.setIdReservation(2);
    r2.setIdPassager(1001);
    r2.setIdTrajet(102);

    // ✅ Dictionnaire simulé du contrôleur
    std::map<Reservation, Trajet> dictionnaire;
    dictionnaire.insert({r1, t1});
    dictionnaire.insert({r2, t2});

    // ✅ Création de la fenêtre
    MesReservationsFenetre *fenetre = new MesReservationsFenetre;
    fenetre->afficherReservations(dictionnaire);
    qDebug() << "Nombre d'éléments dans le dictionnaire : " << dictionnaire.size();

    fenetre->show();

    // Connexions test
    QObject::connect(fenetre, &MesReservationsFenetre::retourAccueil, []() {
        qDebug("➡️ Retour à l'accueil demandé !");
    });

    QObject::connect(fenetre, &MesReservationsFenetre::demandeSuppression, [](int idTrajet) {
        qDebug("🗑️ Suppression demandée pour le trajet ID: %d", idTrajet);
    });

    return app.exec();**/

    QApplication app(argc, argv);

    MainControlleur controlleur;
    controlleur.demarrerApplication();

    return app.exec();

}

