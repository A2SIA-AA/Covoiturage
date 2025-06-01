#include "../headers/RechercherTrajetFenetre.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QDate>

RechercherTrajetFenetre::RechercherTrajetFenetre(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(700, 700);

    QLabel *titre = new QLabel("<h2>Rechercher un trajet</h2>");
    titre->setAlignment(Qt::AlignCenter);

    departEdit = new QLineEdit();
    arriveeEdit = new QLineEdit();
    dateEdit = new QLineEdit();

    QPushButton *rechercherBtn = new QPushButton("Rechercher");
    rechercherBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(rechercherBtn, &QPushButton::clicked, this, &RechercherTrajetFenetre::onRechercheClicked);

    QFormLayout *form = new QFormLayout;
    form->addRow("Lieu de départ", departEdit);
    form->addRow("Lieu d'arrivée", arriveeEdit);
    form->addRow("Date (AAAA-MM-JJ)", dateEdit);
    form->addRow(rechercherBtn);

    filtrePrix = new QCheckBox("Prix");
    filtreCO2 = new QCheckBox("Émission CO2");
    filtreHeure = new QCheckBox("Heure de départ");
    filtreDuree = new QCheckBox("Durée");

    QPushButton *filtrerBtn = new QPushButton("Filtrer");
    filtrerBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(filtrerBtn, &QPushButton::clicked, this, &RechercherTrajetFenetre::onFiltrerClicked);

    accueilBtn = new QPushButton("Accueil");
    accueilBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(accueilBtn, &QPushButton::clicked, this, &RechercherTrajetFenetre::onAccueilClicked);


    QVBoxLayout *filtreLayout = new QVBoxLayout;
    filtreLayout->addWidget(filtrePrix);
    filtreLayout->addWidget(filtreCO2);
    filtreLayout->addWidget(filtreHeure);
    filtreLayout->addWidget(filtreDuree);
    filtreLayout->addWidget(filtrerBtn);

    listeResultats = new QListWidget();
    connect(listeResultats, &QListWidget::itemClicked, this, &RechercherTrajetFenetre::onTrajetSelectionne);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(titre);
    mainLayout->addLayout(form);
    mainLayout->addLayout(filtreLayout);
    mainLayout->addWidget(listeResultats);
    mainLayout->addWidget(accueilBtn);

    setLayout(mainLayout);
}

void RechercherTrajetFenetre::onRechercheClicked() {
    QString date = dateEdit->text();
    static const QRegularExpression regex("^\\d{4}-\\d{2}-\\d{2}$");

    if (departEdit->text().isEmpty() || arriveeEdit->text().isEmpty() || date.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    if (!regex.match(date).hasMatch()) {
        QMessageBox::warning(this, "Format incorrect", "La date doit être au format AAAA-MM-JJ et doit contenir que des chiffres");
        return;
    }


    QDate dateEntree = QDate::fromString(date, "yyyy-MM-dd");
    QDate aujourdHui = QDate::currentDate();

    if (!dateEntree.isValid()) {
        QMessageBox::warning(this, "Date invalide", "La date saisie n'est pas valide.");
        return;
    }

    if (dateEntree < aujourdHui) {
        QMessageBox::warning(this, "Date passée", "La date saisie est déjà passée.");
        return;
    }

    emit rechercheLancee(departEdit->text(), arriveeEdit->text(), date);
}

void RechercherTrajetFenetre::afficherResultats(const std::vector<Trajet>& resultats) {
    listeResultats->clear();
    trajetsActuels = resultats;

    if (resultats.empty()) {
        QMessageBox::information(this, "Aucun trajet", "Aucun trajet ne correspond à votre recherche. Revenez plus tard.");
        return;
    }

    for (const Trajet& t : resultats) {
        QString resume = QString::fromStdString(t.getLieuDepart() + " → " + t.getLieuArrive()) +
                         " | " + QString::fromStdString(t.getHeureDepart()) + " - " + QString::fromStdString(t.getHeureArrive()) +
                         " | Places: " + QString::number(t.getNombrePlaceDispo());


        if (!t.getSegmentsPrix().empty()) {
            resume += " | Prix: " + QString::number(t.getSegmentsPrix().front().second) + "€";
        }

        resume += " | CO2: " + QString::number(t.getEmissionCO2()) + "g";


        QListWidgetItem *item = new QListWidgetItem(resume);
        item->setData(Qt::UserRole, t.getIdTrajet());
        listeResultats->addItem(item);
    }
}

void RechercherTrajetFenetre::onFiltrerClicked() {
    int count = filtrePrix->isChecked() + filtreCO2->isChecked() + filtreHeure->isChecked() + filtreDuree->isChecked();
    if (count != 1) {
        QMessageBox::warning(this, "Filtrage", "Veuillez cocher un seul critère de filtrage.");
        return;
    }

    if (filtrePrix->isChecked()) emit filtrageDemande("Prix");
    else if (filtreCO2->isChecked()) emit filtrageDemande("CO2");
    else if (filtreHeure->isChecked()) emit filtrageDemande("Heure");
    else if (filtreDuree->isChecked()) emit filtrageDemande("Duree");
}

void RechercherTrajetFenetre::onTrajetSelectionne(QListWidgetItem *item) {
    int id = item->data(Qt::UserRole).toInt();
    for (const Trajet& t : trajetsActuels) {
        if (t.getIdTrajet() == id) {
            emit trajetClique(t);
            break;
        }
    }
}


void RechercherTrajetFenetre::onAccueilClicked() {
    emit retourAccueil();
    this->close();
}

void RechercherTrajetFenetre::reinitialiserChamps() {
    departEdit->clear();
    arriveeEdit->clear();
    dateEdit->clear();

    filtrePrix->setChecked(false);
    filtreCO2->setChecked(false);
    filtreHeure->setChecked(false);
    filtreDuree->setChecked(false);
    listeResultats->clear();
    trajetsActuels.clear(); 
}


