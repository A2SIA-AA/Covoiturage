#include "../headers/InscriptionFenetre.h"
#include <QRegularExpression>

InscriptionFenetre::InscriptionFenetre(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(400, 600);

    QLabel *titre = new QLabel("<h2>Bienvenue sur INSA'VOLANT !</h2>");
    titre->setAlignment(Qt::AlignCenter);

    nomLineEdit = new QLineEdit();
    nomLineEdit->setPlaceholderText("Nom");

    prenomLineEdit = new QLineEdit();
    prenomLineEdit->setPlaceholderText("Prénom");

    emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("Adresse e-mail");

    motDePasseLineEdit = new QLineEdit();
    motDePasseLineEdit->setPlaceholderText("Mot de passe");
    motDePasseLineEdit->setEchoMode(QLineEdit::Password);

    adressePostaleLineEdit = new QLineEdit();
    adressePostaleLineEdit->setPlaceholderText("Adresse postale");

    fumeurCheckBox = new QCheckBox("Je suis fumeur");

    inscriptionButton = new QPushButton("S'inscrire");
    inscriptionButton->setStyleSheet("background-color: #B183A7; color: white; padding: 10px; border-radius: 10px;");
    connect(inscriptionButton, &QPushButton::clicked, this, &InscriptionFenetre::onInscriptionClicked);

    QLabel *connexionLabel = new QLabel("<a href='#'>J'ai déjà un compte ? Cliquez ici</a>");
    connexionLabel->setStyleSheet("color: #AAAAAA;");
    connexionLabel->setAlignment(Qt::AlignCenter);
    connexionLabel->setTextFormat(Qt::RichText);
    connexionLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    connexionLabel->setOpenExternalLinks(false);
    connect(connexionLabel, &QLabel::linkActivated, this, &InscriptionFenetre::onRetourConnexionClique);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addStretch();
    layout->addWidget(titre);
    layout->addSpacing(20);
    layout->addWidget(nomLineEdit);
    layout->addWidget(prenomLineEdit);
    layout->addWidget(emailLineEdit);
    layout->addWidget(adressePostaleLineEdit);
    layout->addWidget(motDePasseLineEdit);
    layout->addWidget(fumeurCheckBox);
    layout->addSpacing(20);
    layout->addWidget(inscriptionButton);
    layout->addSpacing(10);
    layout->addWidget(connexionLabel);
    layout->addStretch();

    setLayout(layout);
}

QString InscriptionFenetre::getNom() const {
    return nomLineEdit->text();
}

QString InscriptionFenetre::getPrenom() const {
    return prenomLineEdit->text();
}

QString InscriptionFenetre::getEmail() const {
    return emailLineEdit->text();
}

QString InscriptionFenetre::getAdressePostale() const {
    return adressePostaleLineEdit->text();
}


QString InscriptionFenetre::getMotDePasse() const {
    return motDePasseLineEdit->text();
}

bool InscriptionFenetre::estFumeur() const {
    return fumeurCheckBox->isChecked();
}

void InscriptionFenetre::onInscriptionClicked() {
    static const QRegularExpression regex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");

    if (getNom().isEmpty() || getPrenom().isEmpty()) {
        afficherErreur("Veuillez remplir votre nom et prénom.");
        return;
    }

    if (!regex.match(getEmail()).hasMatch()) {
        afficherErreur("Adresse e-mail invalide.");
        return;
    }

    if (getAdressePostale().isEmpty()) {
        afficherErreur("Veuillez renseigner votre adresse postale.");
        return;
    }


    if (getMotDePasse().length() < 6) {
        afficherErreur("Le mot de passe doit contenir au moins 6 caractères.");
        return;
    }

    emit inscriptionDemandee(getNom(), getPrenom(), getEmail(), getMotDePasse(),getAdressePostale(), estFumeur());
}

void InscriptionFenetre::onRetourConnexionClique() {
    emit retourConnexion();
}

void InscriptionFenetre::afficherErreur(const QString &message) {
    QMessageBox::warning(this, "Erreur", message);
}

void InscriptionFenetre::afficherMessageSucces(const QString &message) {
    QMessageBox *msg = new QMessageBox(this);
    msg->setWindowTitle("Inscription réussie");
    msg->setText(message);
    msg->setIcon(QMessageBox::Information);
    msg->show();

    QTimer::singleShot(10000, msg, &QMessageBox::close);
}

void InscriptionFenetre::reinitialiserChamps() {
    nomLineEdit->clear();
    prenomLineEdit->clear();
    emailLineEdit->clear();
    motDePasseLineEdit->clear();
    adressePostaleLineEdit->clear();
    fumeurCheckBox->setChecked(false);
}

