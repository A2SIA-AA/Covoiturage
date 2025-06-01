/**
 * @file DetailTrajetFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe DetailTrajetFenetre, affichage détaillé d’un trajet.
 * @version 0.1
 * 
 * Cette classe représente une fenêtre d'affichage des détails d’un trajet sélectionné.
 * Elle est utilisée pour consulter toutes les informations associées à un objet `Trajet`.
 */
#ifndef DETAILTRAJETFENETRE_H
#define DETAILTRAJETFENETRE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include "../../../Modele/Modele_hpp/Trajet.hpp"


/**
 * @class DetailTrajetFenetre
 * @brief Fenêtre permettant d’afficher les détails d’un trajet.
 */
class DetailTrajetFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe DetailTrajetFenetre.
     * @param trajet L'objet Trajet à afficher.
     * @param parent Le widget parent, nullptr par défaut.
     */
    DetailTrajetFenetre(const Trajet& trajet, QWidget *parent = nullptr);

signals:
    /**
     * @brief Signal émis pour demander la fermeture de la fenêtre.
     */
    void fermetureFenetre();

private slots:
    /**
     * @brief Slot appelé lorsqu'on clique sur le bouton retour.
     */
    void onRetourClicked();

private:
    /**
     * @brief Affiche les détails du trajet dans l'interface.
     * @param t Le trajet à afficher.
     */
    void afficherDetail(const Trajet& t);
    QPushButton *retourButton;
};


#endif 
