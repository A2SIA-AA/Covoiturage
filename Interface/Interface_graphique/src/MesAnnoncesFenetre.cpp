#include "../headers/MesAnnoncesFenetre.h"
#include <QListWidgetItem>
#include <QMessageBox>

MesAnnoncesFenetre::MesAnnoncesFenetre(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #2E2B2C; color: white; font-family: Arial;");
    this->setFixedSize(500, 600);

    QLabel *titre = new QLabel("<h2>Mes annonces</h2>");
    titre->setAlignment(Qt::AlignCenter);

    onglets = new QTabWidget(this);
    listeAVenir = new QListWidget();
    listePassees = new QListWidget();

    
    onglets->setStyleSheet("QTabWidget::pane { border: none; } QTabBar::tab { background: #444; color: white; padding: 10px; } QTabBar::tab:selected { background: #B183A7; }");

    connect(listeAVenir, &QListWidget::itemClicked, this, &MesAnnoncesFenetre::onAnnonceCliquee);
    connect(listePassees, &QListWidget::itemClicked, this, &MesAnnoncesFenetre::onAnnonceCliquee);

    onglets->addTab(listeAVenir, "À venir");
    onglets->addTab(listePassees, "Passées");

    accueilButton = new QPushButton("Accueil");
    accueilButton->setStyleSheet("background-color: #B183A7; color: white; padding: 8px; border-radius: 8px;");
    connect(accueilButton, &QPushButton::clicked, this, &MesAnnoncesFenetre::onAccueilClicked);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titre);
    layout->addWidget(onglets);
    layout->addWidget(accueilButton);
    setLayout(layout);
}

void MesAnnoncesFenetre::afficherAnnonces(const std::vector<Trajet>& trajets) {
    listeAVenir->clear();
    listePassees->clear();
    trajetsAffiches = trajets;

    for (const Trajet& t : trajets) {
        std::ostringstream oss;
        oss << t.getLieuDepart() << " → " << t.getLieuArrive()
            << " | " << t.getHeureDepart() << " - " << t.getHeureArrive()
            << " | Étapes : " << t.getVillesEtapes().size()
            << " | Places : " << t.getNombrePlaceDispo();

        QString resume = QString::fromStdString(oss.str());

        
        QWidget *widget = new QWidget;
        QVBoxLayout *layout = new QVBoxLayout(widget);
        QLabel *label = new QLabel(resume);
        label->setStyleSheet("color: white;");
        label->setWordWrap(true);
        layout->addWidget(label);

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint());
        item->setData(Qt::UserRole, t.getIdTrajet());

        if (t.getEtat()) {
            
            QPushButton *btnSupprimer = new QPushButton("Supprimer");
            btnSupprimer->setStyleSheet("background-color: #800000; color: white; padding: 4px; border-radius: 4px;");
            layout->addWidget(btnSupprimer);

            connect(btnSupprimer, &QPushButton::clicked, this, [=]() {
                QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setWindowTitle("Confirmation");
                msgBox->setText("Voulez-vous vraiment supprimer cette annonce ?");
                msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox->setStyleSheet("background-color: #2E2B2C; color: white;");

                connect(msgBox, &QMessageBox::buttonClicked, this, [=](QAbstractButton *button) {
                    if (msgBox->standardButton(button) == QMessageBox::Yes) {
                        emit demandeSuppression(t.getIdTrajet()); 
                    }
                    msgBox->close();
                });

                msgBox->show();
            });

            listeAVenir->addItem(item);
            listeAVenir->setItemWidget(item, widget);
        } else {
            
            listePassees->addItem(item);
            listePassees->setItemWidget(item, widget);
        }
    }
}


void MesAnnoncesFenetre::onAnnonceCliquee(QListWidgetItem *item) {
    int id = item->data(Qt::UserRole).toInt();
    std::for_each( trajetsAffiches.begin(),  trajetsAffiches.end(), [&](const Trajet& t) {
        if (t.getIdTrajet() == id) {
            emit annonceSelectionnee(t);
        }
    });
}


void MesAnnoncesFenetre::onAccueilClicked() {
    emit retourAccueil();
    this->close();
}
