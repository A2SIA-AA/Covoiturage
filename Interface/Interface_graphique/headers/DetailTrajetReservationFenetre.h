#ifndef DETAILTRAJETRESERVATIONFENETRE_H
#define DETAILTRAJETRESERVATIONFENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "../../../Modele/Modele_hpp/Trajet.hpp"

class DetailTrajetReservationFenetre : public QWidget {
    Q_OBJECT

public:
    DetailTrajetReservationFenetre(const Trajet& trajet, QWidget *parent = nullptr);

signals:
    void trajetReserve(const Trajet&);   // signal pour le contrôleur
    void fermetureFenetre();

private slots:
    void onRetourClicked();
    void onReserverClicked();

private:
    void afficherDetail(const Trajet& t);
    QPushButton *retourButton;
    QPushButton *reserverButton;
    Trajet trajetCourant;
};
#endif // DETAILTRAJETRESERVATIONFENETRE_H
