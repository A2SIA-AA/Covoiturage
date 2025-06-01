#include "../headers/AccueilFenetre.h"
#include <QMessageBox>
#include <QMenu>
#include <QPalette>
#include <QBrush>

AccueilFenetre::AccueilFenetre(QWidget *parent)
    : QMainWindow(parent) {

    setWindowTitle("Page d'Accueil");
    setFixedSize(900, 900);

    // Couleur unifiée comme les autres fenêtres
    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");

    // Création du menu
    menuBar = new QMenuBar(this);
    QMenu *menu = new QMenu("Menu", this);
    menuBar->addMenu(menu);

    QAction *actionModifierProfil = new QAction("Modifier mon profil", this);
    QAction *actionRechercherTrajet = new QAction("Rechercher un trajet", this);
    QAction *actionPublierTrajet = new QAction("Publier un trajet", this);
    QAction *actionMesReservations = new QAction("Mes réservations", this);
    QAction *actionMesAnnonces = new QAction("Mes annonces", this);
    QAction *actionDeconnecter = new QAction("Se déconnecter", this);

    menu->addAction(actionModifierProfil);
    menu->addAction(actionRechercherTrajet);
    menu->addAction(actionPublierTrajet);
    menu->addAction(actionMesReservations);
    menu->addAction(actionMesAnnonces);
    menu->addAction(actionDeconnecter);

    setMenuBar(menuBar);

    // Connexion des actions du menu aux slots
    connect(actionModifierProfil, &QAction::triggered, this, &AccueilFenetre::onModifierProfil);
    connect(actionRechercherTrajet, &QAction::triggered, this, &AccueilFenetre::onRechercherTrajet);
    connect(actionPublierTrajet, &QAction::triggered, this, &AccueilFenetre::onPublierTrajet);
    connect(actionMesReservations, &QAction::triggered, this, &AccueilFenetre::onMesReservations);
    connect(actionMesAnnonces, &QAction::triggered, this, &AccueilFenetre::onMesAnnonces);
    connect(actionDeconnecter, &QAction::triggered, this, &AccueilFenetre::onDeconnecter);

    // Création du widget central
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);

    btnModifierProfil = new QPushButton("Modifier mon profil", this);
    btnRechercherTrajet = new QPushButton("Rechercher un trajet", this);
    btnPublierTrajet = new QPushButton("Publier un trajet", this);
    btnMesReservations = new QPushButton("Mes réservations", this);
    btnMesAnnonces = new QPushButton("Mes annonces", this);
    btnDeconnecter = new QPushButton("Se déconnecter", this);

    layout->addWidget(btnModifierProfil);
    layout->addWidget(btnRechercherTrajet);
    layout->addWidget(btnPublierTrajet);
    layout->addWidget(btnMesReservations);
    layout->addWidget(btnMesAnnonces);
    layout->addWidget(btnDeconnecter);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connexion des boutons aux slots
    connect(btnModifierProfil, &QPushButton::clicked, this, &AccueilFenetre::onModifierProfil);
    connect(btnRechercherTrajet, &QPushButton::clicked, this, &AccueilFenetre::onRechercherTrajet);
    connect(btnPublierTrajet, &QPushButton::clicked, this, &AccueilFenetre::onPublierTrajet);
    connect(btnMesReservations, &QPushButton::clicked, this, &AccueilFenetre::onMesReservations);
    connect(btnMesAnnonces, &QPushButton::clicked, this, &AccueilFenetre::onMesAnnonces);
    connect(btnDeconnecter, &QPushButton::clicked, this, &AccueilFenetre::onDeconnecter);
}

AccueilFenetre::~AccueilFenetre() {}

void AccueilFenetre::onModifierProfil() {
    emit demandeNavigation("modifierProfil");
    this->close();
}

void AccueilFenetre::onRechercherTrajet() {
    emit demandeNavigation("rechercherTrajet");
    this->close();
}

void AccueilFenetre::onPublierTrajet() {
    emit demandeNavigation("publierTrajet");
    this->close();
}

void AccueilFenetre::onMesReservations() {
    emit demandeNavigation("mesReservations");
    this->close();
}

void AccueilFenetre::onMesAnnonces() {
    emit demandeNavigation("mesAnnonces");
    this->close();
}

void AccueilFenetre::onDeconnecter() {
    emit demandeNavigation("deconnecter");
    this->close();
}
