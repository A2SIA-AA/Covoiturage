#include "../headers/DetailTrajetReservationFenetre.h"
#include <QMessageBox>
#include <QLabel>
#include <QTimer>

DetailTrajetReservationFenetre::DetailTrajetReservationFenetre(const Trajet& trajet, QWidget *parent)
    : QWidget(parent), trajetCourant(trajet) {

    this->setStyleSheet("background-color: #2E2B2C; color: white;");
    this->setMinimumSize(600, 650);
    this->setWindowTitle("Détail du trajet");

    QVBoxLayout *layout = new QVBoxLayout(this);

    afficherDetail(trajet);

    retourButton = new QPushButton("Retour");
    retourButton->setStyleSheet("background-color: #B183A7; color: white; padding: 8px;");

    reserverButton = new QPushButton("Réserver");
    reserverButton->setStyleSheet("background-color: #6495ED; color: white; padding: 8px;");

    connect(retourButton, &QPushButton::clicked, this, &DetailTrajetReservationFenetre::onRetourClicked);
    connect(reserverButton, &QPushButton::clicked, this, &DetailTrajetReservationFenetre::onReserverClicked);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(retourButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(reserverButton);

    layout->addLayout(buttonLayout);
}

void DetailTrajetReservationFenetre::afficherDetail(const Trajet& t) {
    QVBoxLayout *layout = static_cast<QVBoxLayout*>(this->layout());

    auto addLine = [&](const QString &label, const QString &value) {
        QLabel *line = new QLabel(label + ": <b>" + value + "</b>");
        line->setStyleSheet("margin-bottom: 6px;");
        layout->addWidget(line);
    };

    addLine("Date", QString::fromStdString(t.getDate()));
    addLine("Heure de départ", QString::fromStdString(t.getHeureDepart()));
    addLine("Heure d'arrivée", QString::fromStdString(t.getHeureArrive()));
    addLine("Lieu de départ", QString::fromStdString(t.getLieuDepart()));
    addLine("Lieu d'arrivée", QString::fromStdString(t.getLieuArrive()));
    addLine("Voiture", QString::fromStdString(t.getVoiture()));
    addLine("Places disponibles", QString::number(t.getNombrePlaceDispo()));
    addLine("Disponible", t.getDisponible() ? "Oui" : "Non");
    addLine("Aller-retour", t.getAllerRetour() ? "Oui" : "Non");
    addLine("Animaux", t.getAnimaux() ? "Oui" : "Non");
    addLine("CO2", QString::number(t.getEmissionCO2()) + " g/km");
    addLine("Description", QString::fromStdString(t.getDescription()));

    QStringList segments;
    QStringList villes;
    villes << QString::fromStdString(t.getLieuDepart());
    for (const std::string& v : t.getVillesEtapes()) villes << QString::fromStdString(v);
    villes << QString::fromStdString(t.getLieuArrive());

    auto prixList = t.getSegmentsPrix();
    for (int i = 0; i < prixList.size() && i+1 < villes.size(); ++i) {
        segments << villes[i] + " → " + villes[i+1] + ": " + QString::number(prixList[i].second) + " €";
    }

    if (!segments.isEmpty())
        addLine("Tarif par segment", segments.join("<br>"));
}

void DetailTrajetReservationFenetre::onRetourClicked() {
    emit fermetureFenetre();
    this->close();
}

void DetailTrajetReservationFenetre::onReserverClicked() {
    emit trajetReserve(trajetCourant);
}
