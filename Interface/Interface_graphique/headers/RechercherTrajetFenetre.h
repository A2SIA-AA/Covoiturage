#ifndef RECHERCHERTRAJETFENETRE_H
#define RECHERCHERTRAJETFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QCheckBox>
#include <vector>
#include "../../../Modele/Modele_hpp/Trajet.hpp"

class RechercherTrajetFenetre : public QWidget {
    Q_OBJECT

public:
    RechercherTrajetFenetre(QWidget *parent = nullptr);
    void reinitialiserChamps();




signals:
    void rechercheLancee(QString depart, QString arrivee, QString date);
    void filtrageDemande(QString critere);
    void trajetClique(const Trajet&);
    void retourAccueil();

public slots:
    void afficherResultats(const std::vector<Trajet>& resultats);    

private slots:
    void onRechercheClicked();
    void onFiltrerClicked();
    void onTrajetSelectionne(QListWidgetItem *item);
    void onAccueilClicked();

private:
    QLineEdit *departEdit;
    QLineEdit *arriveeEdit;
    QLineEdit *dateEdit;
    QListWidget *listeResultats;
    QCheckBox *filtrePrix;
    QCheckBox *filtreCO2;
    QCheckBox *filtreHeure;
    QCheckBox *filtreDuree;
    std::vector<Trajet> trajetsActuels;
    QPushButton *accueilBtn;
};


#endif // RECHERCHERTRAJETFENETRE_H
