/**
 * @file MesAnnoncesFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe MesAnnoncesFenetre, interface utilisateur pour afficher les annonces publiées.
 * @version 0.1
 * 
 * Cette classe représente une fenêtre permettant à un utilisateur de visualiser ses trajets publiés,
 * classés entre trajets à venir et trajets passés. L'utilisateur peut sélectionner un trajet pour en voir les détails
 * ou demander sa suppression.
 */
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

/**
 * @class MesAnnoncesFenetre
 * @brief Fenêtre pour afficher et gérer les annonces (trajets) publiées par l'utilisateur. 
 * 
 */
class MesAnnoncesFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe MesAnnoncesFenetre.
     * @param parent Le widget parent, nullptr par défaut.
     */
    MesAnnoncesFenetre(QWidget *parent = nullptr);

    /**
     * @brief Affiche les trajets fournis dans l'interface graphique.
     * @param trajets La liste des trajets publiés par l'utilisateur.
     */
    void afficherAnnonces(const std::vector<Trajet>& trajets);

signals:
    /**
     * @brief Signal émis lorsqu'un utilisateur sélectionne une annonce.
     * @param trajet Le trajet sélectionné.
     */
    void annonceSelectionnee(const Trajet& trajet);

    /**
     * @brief Signal émis lorsque l'utilisateur souhaite retourner à l'accueil.
     */
    void retourAccueil();

    /**
     * @brief Signal émis pour demander la suppression d'une annonce.
     * @param idTrajet L'identifiant du trajet à supprimer.
     */
    void demandeSuppression(int idTrajet);



private slots:
     /**
     * @brief Slot appelé lorsqu'un utilisateur clique sur une annonce.
     * @param item L'élément de la liste sélectionné.
     */
    void onAnnonceCliquee(QListWidgetItem *item);

    /**
     * @brief Slot appelé lorsqu'on clique sur le bouton pour retourner à l'accueil.
     */
    void onAccueilClicked();


private:
    QTabWidget *onglets;
    QListWidget *listeAVenir;
    QListWidget *listePassees;
    std::vector<Trajet> trajetsAffiches;
    QPushButton *accueilButton;

};

#endif


