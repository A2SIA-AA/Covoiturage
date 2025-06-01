#include "../headers/ModifierProfilFenetre.h"
#include "../../../Modele/Modele_hpp/Utilisateur.hpp"

#include <QMessageBox>
#include <QRegularExpression>

ModifierProfilFenetre::ModifierProfilFenetre(QWidget *parent) : QWidget(parent) {
    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(500, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    
    nomLineEdit = new QLineEdit();
    prenomLineEdit = new QLineEdit();
    emailLineEdit = new QLineEdit();
    motDePasseLineEdit = new QLineEdit();
    adresseLineEdit = new QLineEdit();
    fumeurCheckBox = new QCheckBox("Fumeur");

    nomLineEdit->setReadOnly(true);
    prenomLineEdit->setReadOnly(true);
    emailLineEdit->setReadOnly(true);
    motDePasseLineEdit->setReadOnly(true);
    adresseLineEdit->setReadOnly(true);
    fumeurCheckBox->setEnabled(false);

    
    champCombo = new QComboBox();
    champCombo->addItems({"nom", "prenom", "email", "motPasse", "adressePostal", "fumeur"});
    connect(champCombo, &QComboBox::currentTextChanged, this, &ModifierProfilFenetre::onChampChanged);

    valeurEdit = new QLineEdit();
    valeurEdit->setPlaceholderText("Nouvelle valeur");

    fumeurCheck = new QCheckBox("Êtes-vous fumeur ?");
    fumeurCheck->hide();

    validerBtn = new QPushButton("Valider la modification");
    validerBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(validerBtn, &QPushButton::clicked, this, &ModifierProfilFenetre::onValiderClicked);

    accueilBtn = new QPushButton("Accueil");
    accueilBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(accueilBtn, &QPushButton::clicked, this, &ModifierProfilFenetre::onAccueilClicked);

    
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Nom", nomLineEdit);
    formLayout->addRow("Prénom", prenomLineEdit);
    formLayout->addRow("Email", emailLineEdit);
    formLayout->addRow("Mot de passe", motDePasseLineEdit);
    formLayout->addRow("Adresse", adresseLineEdit);
    formLayout->addRow("Fumeur", fumeurCheckBox);
    formLayout->addRow("Choix de la modification", champCombo);
    formLayout->addRow("Valeur à modifier", valeurEdit);
    formLayout->addRow("", fumeurCheck);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(validerBtn);
    mainLayout->addWidget(accueilBtn);
    setLayout(mainLayout);
}

void ModifierProfilFenetre::onChampChanged(const QString &champ) {
    if (champ == "fumeur") {
        valeurEdit->hide();
        fumeurCheck->show();
    } else {
        fumeurCheck->hide();
        valeurEdit->show();
        valeurEdit->clear();
    }
}

void ModifierProfilFenetre::onValiderClicked() {
    QString champ = champCombo->currentText();
    QString valeur;

    if (champ == "fumeur") {
        valeur = fumeurCheck->isChecked() ? "1" : "0";
    } else {
        valeur = valeurEdit->text();
        if (valeur.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez entrer une valeur.");
            return;
        }
        if (champ == "motPasse" && valeur.length() < 4) {
            QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins 4 caractères.");
            return;
        }
        if (champ == "email") {
            static const QRegularExpression regex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
            if (!regex.match(valeur).hasMatch()) {
                QMessageBox::warning(this, "Erreur", "Format d'adresse e-mail invalide.");
                return;
            }
        }
    }

    emit modificationDemandee(champ, valeur);
    QMessageBox::information(this, "Succès", "Modification envoyée au contrôleur.");
}

void ModifierProfilFenetre::onAccueilClicked() {
    emit retourAccueil();
    this->close();
}

void ModifierProfilFenetre::reinitialiserChamps() {
    champCombo->setCurrentIndex(0);     
    valeurEdit->clear();                
    valeurEdit->show();               
    fumeurCheck->setChecked(false);     
    fumeurCheck->hide();                
}

void ModifierProfilFenetre::afficherUtilisateur(const Utilisateur& utilisateur) {
    
    nomLineEdit->setText(QString::fromStdString(utilisateur.getNom()));
    prenomLineEdit->setText(QString::fromStdString(utilisateur.getPrenom()));
    emailLineEdit->setText(QString::fromStdString(utilisateur.getEmail()));
    adresseLineEdit->setText(QString::fromStdString(utilisateur.getAdressePostale()));
    motDePasseLineEdit->setText(QString::fromStdString(utilisateur.getMotPasse()));
    fumeurCheckBox->setChecked(utilisateur.getFumeur());
}

