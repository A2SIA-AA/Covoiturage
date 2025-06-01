#include "../headers/MesReservationsFenetre.h"
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>


MesReservationsFenetre::MesReservationsFenetre(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(600, 650);

    QLabel *titre = new QLabel("<h2>Mes réservations</h2>");
    titre->setAlignment(Qt::AlignCenter);

    onglets = new QTabWidget(this);
    listeAVenir = new QListWidget();
    listePassees = new QListWidget();

    onglets->setStyleSheet("QTabWidget::pane { border: none; } QTabBar::tab { background: #444; color: white; padding: 10px; } QTabBar::tab:selected { background: #B183A7; }");

    onglets->addTab(listeAVenir, "À venir");
    onglets->addTab(listePassees, "Passées");

    accueilBtn = new QPushButton("Accueil");
    accueilBtn->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(accueilBtn, &QPushButton::clicked, this, &MesReservationsFenetre::onAccueilClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(titre);
    mainLayout->addWidget(onglets);
    mainLayout->addWidget(accueilBtn);
    setLayout(mainLayout);
}

void MesReservationsFenetre::afficherReservations(const std::map<Reservation, Trajet>& dictionnaire) {
    listeAVenir->clear();
    listePassees->clear();
    mappingItemToTrajet.clear();

    for (const auto& pair : dictionnaire) {
        const Reservation& r = pair.first;
        const Trajet& t = pair.second;

        mappingItemToTrajet.insert(std::make_pair(r, t));

        QString lieuDepart = QString::fromStdString(t.getLieuDepart());
        QString lieuArrivee = QString::fromStdString(t.getLieuArrive());
        QString heureDepart = QString::fromStdString(t.getHeureDepart());
        QString heureArrivee = QString::fromStdString(t.getHeureArrive());
        QString voiture = QString::fromStdString(t.getVoiture());
        QString description = QString::fromStdString(t.getDescription());
        QString co2 = QString::number(t.getEmissionCO2());
        QString prix = QString::number(r.getPrix());

        QString texte = lieuDepart + " → " + lieuArrivee +
                        " | " + heureDepart + " - " + heureArrivee +
                        " | " + voiture +
                        " | CO2: " + co2 +
                        " | Prix: " + prix +
                        "\n" + description;

        QWidget *widget = new QWidget;
        QVBoxLayout *layout = new QVBoxLayout(widget);
        QLabel *label = new QLabel(texte);
        label->setWordWrap(true);
        label->setStyleSheet("color: white; font-size: 13px;");
        layout->addWidget(label);

        // Si la réservation est à venir
        if (r.getStatut()) {
            QPushButton *btnSupprimer = new QPushButton("Supprimer");
            btnSupprimer->setStyleSheet("background-color: #800000; color: white; padding: 4px; border-radius: 4px;");
            layout->addWidget(btnSupprimer);

            int idReservation = r.getIdReservation();
            connect(btnSupprimer, &QPushButton::clicked, this, [=]() {
                QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setWindowTitle("Confirmation");
                msgBox->setText("Voulez-vous vraiment supprimer cette réservation ?");
                msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox->setStyleSheet("background-color: #2E2B2C; color: white;");
                msgBox->resize(400, 500); 


                connect(msgBox, &QMessageBox::buttonClicked, this, [=](QAbstractButton *button) {
                    if (msgBox->standardButton(button) == QMessageBox::Yes) {
                        emit demandeSuppression(idReservation);
                    }
                    msgBox->close();
                });

                msgBox->show();
            });

            
            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(widget->sizeHint());
            listeAVenir->addItem(item);
            listeAVenir->setItemWidget(item, widget);
        }
        else {
            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(widget->sizeHint());
            listePassees->addItem(item);
            listePassees->setItemWidget(item, widget);
        }
    }
}

void MesReservationsFenetre::onAccueilClicked() {
    emit retourAccueil();
    this->close();
}
