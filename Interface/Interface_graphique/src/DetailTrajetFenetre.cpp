#include "../headers/DetailTrajetFenetre.h"
#include <QScrollArea>
#include <QFont>

DetailTrajetFenetre::DetailTrajetFenetre(const Trajet& trajet, QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setWindowTitle("Détail du trajet");
    this->setMinimumSize(500, 600);

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *titre = new QLabel("<h2>Détail du trajet</h2>");
    titre->setAlignment(Qt::AlignCenter);
    layout->addWidget(titre);

    setLayout(layout);
    afficherDetail(trajet);

    retourButton = new QPushButton("Retour");
    retourButton->setStyleSheet("padding: 8px; background-color: #B183A7; color: white; border-radius: 8px;");
    connect(retourButton, &QPushButton::clicked, this, &DetailTrajetFenetre::onRetourClicked);
    layout->addWidget(retourButton);
}

void DetailTrajetFenetre::afficherDetail(const Trajet& t) {
    QVBoxLayout *layout = static_cast<QVBoxLayout*>(this->layout());

    auto addLine = [&](const QString &label, const QString &value) {
        QLabel *line = new QLabel(label + ": <b>" + value + "</b>");
        line->setStyleSheet("margin-bottom: 8px;");
        layout->addWidget(line);
    };

    addLine("Date", QString::fromStdString(t.getDate()));
    addLine("Heure de départ", QString::fromStdString(t.getHeureDepart()));
    addLine("Heure d'arrivée", QString::fromStdString(t.getHeureArrive()));
    addLine("Lieu de départ", QString::fromStdString(t.getLieuDepart()));
    addLine("Lieu d'arrivée", QString::fromStdString(t.getLieuArrive()));
    addLine("Voiture", QString::fromStdString(t.getVoiture()));
    addLine("Nombre de places disponibles", QString::number(t.getNombrePlaceDispo()));
    addLine("Disponible", t.getDisponible() ? "Oui" : "Non");
    addLine("Aller-retour", t.getAllerRetour() ? "Oui" : "Non");
    addLine("Animaux acceptés", t.getAnimaux() ? "Oui" : "Non");
    addLine("Émission CO2", QString::number(t.getEmissionCO2()) + " g/km");
    addLine("Description", QString::fromStdString(t.getDescription()));

    // Affichage des étapes intermédiaires
    std::vector<std::string> etapes = t.getVillesEtapes();
    QStringList etapesList;
    for (const std::string& e : etapes) {
        etapesList << QString::fromStdString(e);
    }
    addLine("Étapes intermédiaires", etapesList.isEmpty() ? "Aucune" : etapesList.join(" → "));

    // Affichage du prix par segment
    std::vector<std::pair<std::string, float>> segments = t.getSegmentsPrix();
    QStringList segmentsAffichage;
    QStringList villes;
    villes << QString::fromStdString(t.getLieuDepart());
    for (const std::string& v : t.getVillesEtapes()) villes << QString::fromStdString(v);
    villes << QString::fromStdString(t.getLieuArrive());

    for (size_t i = 0; i < segments.size() && i+1 < villes.size(); ++i) {
        QString trajet = villes[i] + " → " + villes[i+1];
        QString prix = QString::number(segments[i].second) + " €";
        segmentsAffichage << (trajet + ": " + prix);
    }
    addLine("Tarif par segment", segmentsAffichage.isEmpty() ? "Aucun" : segmentsAffichage.join("<br>"));
}

void DetailTrajetFenetre::onRetourClicked() {
    emit fermetureFenetre();
    this->close();
}
