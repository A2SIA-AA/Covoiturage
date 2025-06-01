/**
 * @file DetailTrajetReservationFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe DetailTrajetReservationFenetre, affichage et réservation d’un trajet.
 * @version 0.1
 * 
 * Cette classe représente une fenêtre permettant à l’utilisateur de consulter les détails
 * d’un trajet sélectionné et de procéder à une réservation.
 */
#ifndef DETAILTRAJETRESERVATIONFENETRE_H
#define DETAILTRAJETRESERVATIONFENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "../../../Modele/Modele_hpp/Trajet.hpp"

/**
 * @class DetailTrajetReservationFenetre
 * @brief Fenêtre affichant les détails d’un trajet avec possibilité de réservation.
 */
class DetailTrajetReservationFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe DetailTrajetReservationFenetre.
     * @param trajet Le trajet à afficher et potentiellement réserver.
     * @param parent Le widget parent, nullptr par défaut.
     */
    DetailTrajetReservationFenetre(const Trajet& trajet, QWidget *parent = nullptr);

signals:
    /**
     * @brief Signal émis lorsqu’un trajet est réservé.
     * @param trajet Le trajet qui a été réservé.
     */
    void trajetReserve(const Trajet&); 
    
    /**
     * @brief Signal émis pour fermer la fenêtre.
     */
    void fermetureFenetre();

private slots:
    /**
     * @brief Slot appelé lorsque l’utilisateur clique sur le bouton retour.
     */
    void onRetourClicked();

    /**
     * @brief Slot appelé lorsque l’utilisateur clique sur le bouton réserver.
     */
    void onReserverClicked();

private:
    /**
     * @brief Méthode privée pour afficher les détails du trajet dans l'interface.
     * @param t Le trajet à afficher.
     */
    void afficherDetail(const Trajet& t);

    QPushButton *retourButton;
    QPushButton *reserverButton;
    Trajet trajetCourant; 
};
#endif 
