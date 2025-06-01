#ifndef MESRESERVATIONSFENETRE_H
#define MESRESERVATIONSFENETRE_H


#include <QWidget>
#include <QTabWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <map>
#include "../../../Modele/Modele_hpp/Reservation.hpp"
#include "../../../Modele/Modele_hpp/Trajet.hpp"

class MesReservationsFenetre : public QWidget {
    Q_OBJECT

public:
    explicit MesReservationsFenetre(QWidget *parent = nullptr);

    // Affiche les réservations de l'utilisateur
    void afficherReservations(const std::map<Reservation, Trajet>& dictionnaire);

signals:
    // Signal pour retourner à l'accueil
    void retourAccueil();

    // Signal pour demander la suppression d'un trajet (par son id)
    void demandeSuppression(int idReservation);

private slots:
    void onAccueilClicked();

private:
    QTabWidget *onglets;
    QListWidget *listeAVenir;
    QListWidget *listePassees;
    QPushButton *accueilBtn;
    std::map<Reservation, Trajet> mappingItemToTrajet;

};

#endif // MESRESERVATIONSFENETRE_H
