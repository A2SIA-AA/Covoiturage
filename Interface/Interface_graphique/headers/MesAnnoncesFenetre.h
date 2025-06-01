#ifndef MESANNONCESFENETRE_H
#define MESANNONCESFENETRE_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <vector>
#include <string>
#include <sstream>
#include "../../../Modele/Modele_hpp/Trajet.hpp"

    class MesAnnoncesFenetre : public QWidget {
    Q_OBJECT

public:
    MesAnnoncesFenetre(QWidget *parent = nullptr);
    void afficherAnnonces(const std::vector<Trajet>& trajets);

signals:
    void annonceSelectionnee(const Trajet& trajet);
    void retourAccueil();
    void demandeSuppression(int idTrajet);



private slots:
    void onAnnonceCliquee(QListWidgetItem *item);
    void onAccueilClicked();


private:
    QTabWidget *onglets;
    QListWidget *listeAVenir;
    QListWidget *listePassees;
    std::vector<Trajet> trajetsAffiches;
    QPushButton *accueilButton;

};

#endif


