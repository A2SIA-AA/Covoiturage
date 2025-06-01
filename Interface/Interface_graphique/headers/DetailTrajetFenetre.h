#ifndef DETAILTRAJETFENETRE_H
#define DETAILTRAJETFENETRE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include "../../../Modele/Modele_hpp/Trajet.hpp"

class DetailTrajetFenetre : public QWidget {
    Q_OBJECT

public:
    DetailTrajetFenetre(const Trajet& trajet, QWidget *parent = nullptr);

signals:
    void fermetureFenetre();

private slots:
    void onRetourClicked();

private:
    void afficherDetail(const Trajet& t);
    QPushButton *retourButton;
};


#endif // DETAILTRAJETFENETRE_H
