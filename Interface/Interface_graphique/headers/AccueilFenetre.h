/**
 * @file AccueilFenetre.h
 * @author Ilheme YAYA
 * @brief  Déclaration de la classe AccueilFenetre, interface principale de navigation de l'application.
 * @version 0.1
 * 
 * Cette classe représente la fenêtre d'accueil après la connexion de l'utilisateur.
 * Elle propose plusieurs boutons permettant de naviguer vers les différentes fonctionnalités
 * de l'application de covoiturage : modification de profil, recherche et publication de trajets,
 * consultation des réservations et des annonces, ainsi que la déconnexion.
 */

#ifndef ACCUEILFENETRE_H
#define ACCUEILFENETRE_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>


/**
 * @class AccueilFenetre
 * @brief Fenêtre principale de navigation de l'application.
 */
class AccueilFenetre : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe AccueilFenetre.
     * 
     * @param parent Le widget parent, nullptr par défaut.
     */
    explicit AccueilFenetre(QWidget *parent = nullptr);

    /**
     * @brief  Destructeur de la classe AccueilFenetre.
     * 
     */
    ~AccueilFenetre();

signals:
    /**
     * @brief Signal envoyé au contrôleur pour naviguer vers une autre page.
     * @param nomPage Le nom de la page cible "modifierProfil", "rechercherTrajet", "publierTrajet", "mesReservations", "mesAnnonces", "deconnecter"
     */
    void demandeNavigation(const QString &nomPage);

private slots:
    /**
     * @brief Slot appelé lors du clic sur le bouton "Modifier Profil".
     */
    void onModifierProfil();

    /**
     * @brief Slot appelé lors du clic sur le bouton "Rechercher Trajet".
     */
    void onRechercherTrajet();

    /**
     * @brief Slot appelé lors du clic sur le bouton "Publier Trajet".
     */
    void onPublierTrajet();

    /**
     * @brief Slot appelé lors du clic sur le bouton "Mes Réservations".
     */
    void onMesReservations();

    /**
     * @brief Slot appelé lors du clic sur le bouton "Mes Annonces".
     */
    void onMesAnnonces();

    /**
     * @brief Slot appelé lors du clic sur le bouton "Déconnexion".
     */
    void onDeconnecter();

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QMenuBar *menuBar;

    //les boutons de la fenetre
    QPushButton *btnModifierProfil;
    QPushButton *btnRechercherTrajet;
    QPushButton *btnPublierTrajet;
    QPushButton *btnMesReservations;
    QPushButton *btnMesAnnonces;
    QPushButton *btnDeconnecter;
};

#endif
