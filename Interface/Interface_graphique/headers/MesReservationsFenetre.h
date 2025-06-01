/**
 * @file MesReservationsFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe MesReservationsFenetre, interface d’affichage des réservations de l’utilisateur.
 * @version 0.1
 * 
 * Cette classe fournit une interface graphique permettant à l’utilisateur de consulter ses réservations,
 * en les classant entre trajets à venir et trajets passés. L'utilisateur peut aussi retourner à l'accueil
 * ou demander l'annulation d'une réservation.
 */
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

/**
 * @class MesReservationsFenetre
 * @brief Fenêtre d’affichage des réservations de l’utilisateur.
 */
class MesReservationsFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe MesReservationsFenetre.
     * @param parent Le widget parent (nullptr par défaut).
     */
    explicit MesReservationsFenetre(QWidget *parent = nullptr);

    /**
     * @brief Affiche les réservations de l'utilisateur.
     * @param dictionnaire Un dictionnaire associant une réservation à son trajet correspondant.
     */
    void afficherReservations(const std::map<Reservation, Trajet>& dictionnaire);

signals:
    /**
     * @brief Signal émis pour retourner à l’accueil.
     */
    void retourAccueil();

    /**
     * @brief Signal émis pour demander la suppression d’une réservation.
     * @param idReservation L'identifiant de la réservation à supprimer.
     */
    void demandeSuppression(int idReservation);

private slots:
    /**
     * @brief Slot appelé lorsque l’utilisateur clique sur le bouton d’accueil.
     */
    void onAccueilClicked();

private:
    QTabWidget *onglets;
    QListWidget *listeAVenir;
    QListWidget *listePassees;
    QPushButton *accueilBtn;
    std::map<Reservation, Trajet> mappingItemToTrajet;

};

#endif 
