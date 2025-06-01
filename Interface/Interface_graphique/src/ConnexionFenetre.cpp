#include "../headers/ConnexionFenetre.h"
#include <QRegularExpression>
#include <QHBoxLayout>
#include <QPixmap>

ConnexionFenetre::ConnexionFenetre(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(350, 500);

    iconLabel = new QLabel;
    iconLabel->setPixmap(QPixmap("../images/user.jpeg").scaled(80, 80));
    iconLabel->setAlignment(Qt::AlignCenter);

    emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("UserEmail");
    emailLineEdit->setStyleSheet("padding: 10px; border-radius: 10px; background-color: #444; color: white;");

    motDePasseLineEdit = new QLineEdit();
    motDePasseLineEdit->setPlaceholderText("PASSWORD");
    motDePasseLineEdit->setEchoMode(QLineEdit::Password);// masquer le  mot de passe
    motDePasseLineEdit->setStyleSheet("padding: 10px; border-radius: 10px; background-color: #444; color: white;");

    loginButton = new QPushButton("LOGIN");
    loginButton->setStyleSheet("background-color: #B183A7; color: white; padding: 10px; border-radius: 10px;");
    connect(loginButton, &QPushButton::clicked, this, &ConnexionFenetre::onConnexionClicked);

    QLabel *inscriptionLabel = new QLabel("<a href='#'>Je n’ai pas encore de compte ? Cliquez ici</a>");
    inscriptionLabel->setStyleSheet("color: #AAAAAA;");
    inscriptionLabel->setAlignment(Qt::AlignCenter);
    inscriptionLabel->setTextFormat(Qt::RichText);
    inscriptionLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    inscriptionLabel->setOpenExternalLinks(false);
    connect(inscriptionLabel, &QLabel::linkActivated, this, &ConnexionFenetre::onInscriptionCliquee);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addStretch();
    layout->addWidget(iconLabel);
    layout->addSpacing(30);
    layout->addWidget(emailLineEdit);
    layout->addSpacing(15);
    layout->addWidget(motDePasseLineEdit);
    layout->addSpacing(30);
    layout->addWidget(loginButton);
    layout->addSpacing(15);
    layout->addWidget(inscriptionLabel);
    layout->addStretch();

    setLayout(layout);
}

QString ConnexionFenetre::getEmail() const {
    return emailLineEdit->text();
}

QString ConnexionFenetre::getMotDePasse() const {
    return motDePasseLineEdit->text();
}

void ConnexionFenetre::onConnexionClicked() {
    static const QRegularExpression regex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    QString email = getEmail();
    QString motDePasse = getMotDePasse();

    if (!regex.match(email).hasMatch()) {
        afficherErreur("Format de l'email invalide.");
        return;
    }
    if (motDePasse.length() < 4) {
        afficherErreur("Le mot de passe doit contenir au moins 4 caractères.");
        return;
    }

    emit connexionDemandee(email, motDePasse);
}

void ConnexionFenetre::afficherErreur(const QString &message) {
    QMessageBox::warning(this, "Erreur", message);
}

void ConnexionFenetre::afficherMessageSucces(const QString &message) {
    QMessageBox *msg = new QMessageBox(this);
    msg->setWindowTitle("Connexion réussie");
    msg->setText(message);
    msg->setIcon(QMessageBox::Information);
    msg->show();

    QTimer::singleShot(10000, msg, &QMessageBox::close);
}

void ConnexionFenetre::onInscriptionCliquee() {
    emit demandeInscription();
}

void ConnexionFenetre::reinitialiserChamps() {
    emailLineEdit->clear();
    motDePasseLineEdit->clear();
}

