#include "../headers/PublierTrajetFenetre.h"
#include <QTimer>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDate>        // ✅ Ajout pour la vérification de la date
#include <QTime>


PublierTrajetFenetre::PublierTrajetFenetre(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(600, 800);

    QVBoxLayout *layout = new QVBoxLayout;
    QFormLayout *form = new QFormLayout;

    dateEdit = new QLineEdit();
    heureDepartEdit = new QLineEdit();
    heureArriveeEdit = new QLineEdit();
    lieuDepartEdit = new QLineEdit();
    lieuArriveeEdit = new QLineEdit();
    prixEdit = new QLineEdit();
    distanceEdit = new QLineEdit();
    voitureEdit = new QLineEdit();
    placesEdit = new QLineEdit();
    consommationEdit = new QLineEdit();
    ancienneteEdit = new QLineEdit();
    descriptionEdit = new QTextEdit();

    animauxCheck = new QCheckBox("Avez-vous un animal avec vous pour ce trajet ?");


    essenceRadio = new QRadioButton("Essence");
    dieselRadio = new QRadioButton("Diesel");
    electriqueRadio = new QRadioButton("Électrique");
    carburantGroup = new QButtonGroup(this);
    carburantGroup->addButton(essenceRadio);
    carburantGroup->addButton(dieselRadio);
    carburantGroup->addButton(electriqueRadio);

    form->addRow("Date (AAAA-MM-JJ)", dateEdit);
    form->addRow("Heure de départ (HH:MM)", heureDepartEdit);
    form->addRow("Heure d'arrivée (HH:MM)", heureArriveeEdit);
    form->addRow("Lieu de départ", lieuDepartEdit);
    form->addRow("Lieu d'arrivée", lieuArriveeEdit);
    form->addRow("Prix (€)", prixEdit);
    form->addRow("Distance (km)", distanceEdit);
    form->addRow("Voiture", voitureEdit);
    form->addRow("Nombre de places", placesEdit);
    form->addRow("Consommation (L/100km)", consommationEdit);
    form->addRow("Ancienneté de la voiture (années)", ancienneteEdit);
    form->addRow("Description", descriptionEdit);
    form->addRow("Animaux", animauxCheck);


    QHBoxLayout *carburantLayout = new QHBoxLayout;
    carburantLayout->addWidget(essenceRadio);
    carburantLayout->addWidget(dieselRadio);
    carburantLayout->addWidget(electriqueRadio);
    form->addRow("Type de carburant", carburantLayout);

    publierBtn = new QPushButton("Publier le trajet");
    publierBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 10px;");
    connect(publierBtn, &QPushButton::clicked, this, &PublierTrajetFenetre::onPublierClicked);

    accueilBtn = new QPushButton("Accueil");
    accueilBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 10px;");
    connect(accueilBtn, &QPushButton::clicked, this, &PublierTrajetFenetre::onAccueilClicked);

    layout->addLayout(form);
    layout->addWidget(publierBtn);
    layout->addWidget(accueilBtn);
    setLayout(layout);
}

void PublierTrajetFenetre::onPublierClicked() {
    if (dateEdit->text().isEmpty() || heureDepartEdit->text().isEmpty() ||
        heureArriveeEdit->text().isEmpty() || lieuDepartEdit->text().isEmpty() ||
        lieuArriveeEdit->text().isEmpty() || prixEdit->text().isEmpty() ||
        distanceEdit->text().isEmpty() || voitureEdit->text().isEmpty() ||
        placesEdit->text().isEmpty() || consommationEdit->text().isEmpty() ||
        ancienneteEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }



    // Expressions régulières (déclarées en static pour éviter les warnings)
    static const QRegularExpression dateRegex("^\\d{4}-\\d{2}-\\d{2}$");     // AAAA-MM-JJ
    static const QRegularExpression heureRegex("^\\d{2}:\\d{2}$");           // HH:MM
    static const QRegularExpression nombreRegex("^\\d+(\\.\\d+)?$");         // Float (ex: 12 ou 12.5)
    static const QRegularExpression entierRegex("^\\d+$");                   // Entier positif

    // Vérifications de format
    if (!dateRegex.match(dateEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La date doit être au format AAAA-MM-JJ et contenir que des nombres.");
        return;
    }

    // ✅ ✅ Nouvelle vérification de la date du jour
    QDate dateTrajet = QDate::fromString(dateEdit->text(), "yyyy-MM-dd");
    QDate dateActuelle = QDate::currentDate();

    if (!dateTrajet.isValid()) {
        QMessageBox::warning(this, "Erreur", "La date est invalide.");
        return;
    }

    if (dateTrajet < dateActuelle) {
        QMessageBox::warning(this, "Erreur", "La date du trajet ne peut pas être antérieure à aujourd'hui.");
        return;
    }
    // ✅ ✅ Fin de la modification


    if (!heureRegex.match(heureDepartEdit->text()).hasMatch() ||
        !heureRegex.match(heureArriveeEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Les heures doivent être au format HH:MM. et contenir que des nombres");
        return;
    }

    // ✅ Nouvelle vérification heure de départ si date == aujourd'hui
    if (dateTrajet == dateActuelle) {
        QTime heureDepart = QTime::fromString(heureDepartEdit->text(), "HH:mm");
        QTime heureActuelle = QTime::currentTime();
        QTime minimumHeure = heureActuelle.addSecs(30 * 60); // +30 min

        if (heureDepart < minimumHeure) {
            QMessageBox::warning(this, "Erreur", "L'heure de départ doit être au moins 30 minutes après l'heure actuelle.");
            return;
        }
    }

    // ✅ Vérification que l'heure d'arrivée est après celle de départ
    QTime heureDepart = QTime::fromString(heureDepartEdit->text(), "HH:mm");
    QTime heureArrivee = QTime::fromString(heureArriveeEdit->text(), "HH:mm");

    if (!heureDepart.isValid() || !heureArrivee.isValid()) {
        QMessageBox::warning(this, "Erreur", "Heures invalides.");
        return;
    }

    if (heureArrivee <= heureDepart) {
        QMessageBox::warning(this, "Erreur", "L'heure d'arrivée doit être après l'heure de départ.");
        return;
    }

    if (!nombreRegex.match(prixEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le prix doit contenir uniquement des chiffres.");
        return;
    }

    if (!nombreRegex.match(distanceEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La distance doit contenir uniquement des chiffres.");
        return;
    }

    if (!nombreRegex.match(consommationEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La consommation doit contenir uniquement des chiffres.");
        return;
    }

    if (!entierRegex.match(ancienneteEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ancienneté doit être un entier.");
        return;
    }


    bool ok1, ok2, ok3, ok4;
    float prix = prixEdit->text().toFloat(&ok1);
    float distance = distanceEdit->text().toFloat(&ok2);
    int nbPlaces = placesEdit->text().toInt(&ok3);
    float conso = consommationEdit->text().toFloat(&ok4);
    int age = ancienneteEdit->text().toInt();

    if (!ok1 || prix <= 0) {
        QMessageBox::warning(this, "Erreur", "Prix invalide.");
        return;
    }
    if (!ok2 || distance <= 0) {
        QMessageBox::warning(this, "Erreur", "Distance invalide.");
        return;
    }
    if (!ok3 || nbPlaces <= 0 || nbPlaces > 6) {
        QMessageBox::warning(this, "Erreur", "Nombre de places invalide. Doit être compris entre 1 et 6");
        return;
    }
    if (!ok4 || conso <= 0) {
        QMessageBox::warning(this, "Erreur", "Consommation invalide.");
        return;
    }

    QString carburant;
    if (essenceRadio->isChecked()) carburant = "Essence";
    else if (dieselRadio->isChecked()) carburant = "Diesel";
    else if (electriqueRadio->isChecked()) carburant = "Électrique";
    else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type de carburant.");
        return;
    }

    bool animaux = animauxCheck->isChecked();

    emit trajetSoumis(
        dateEdit->text(),
        heureDepartEdit->text(),
        heureArriveeEdit->text(),
        lieuDepartEdit->text(),
        lieuArriveeEdit->text(),
        prix,
        distance,
        voitureEdit->text(),
        nbPlaces,
        conso,
        age,
        carburant,
        descriptionEdit->toPlainText(),
        animaux
        );

}


void PublierTrajetFenetre::onAccueilClicked() {
    emit retourAccueil();
    this->close();
}


void PublierTrajetFenetre::reinitialiserChamps() {
    dateEdit->clear();
    heureDepartEdit->clear();
    heureArriveeEdit->clear();
    lieuDepartEdit->clear();
    lieuArriveeEdit->clear();
    prixEdit->clear();
    distanceEdit->clear();
    voitureEdit->clear();
    placesEdit->clear();
    consommationEdit->clear();
    ancienneteEdit->clear();
    descriptionEdit->clear();
    animauxCheck->setChecked(false);

    carburantGroup->setExclusive(false);
    essenceRadio->setChecked(false);
    dieselRadio->setChecked(false);
    electriqueRadio->setChecked(false);
    carburantGroup->setExclusive(true);
}
