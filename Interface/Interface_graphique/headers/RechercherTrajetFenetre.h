/**
 * @file RechercherTrajetFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe RechercherTrajetFenetre, interface de recherche de trajets.
 * @version 0.1
 * 
 * Cette classe permet à l’utilisateur de rechercher des trajets disponibles en fonction d’un lieu
 * de départ, d’un lieu d’arrivée et d’une date. Des filtres peuvent être appliqués sur les résultats.
 */
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


/**
 * @class RechercherTrajetFenetre
 * @brief Fenêtre de recherche de trajets avec filtres.
 *
 */
class RechercherTrajetFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe RechercherTrajetFenetre.
     * @param parent Le widget parent (nullptr par défaut).
     */
    RechercherTrajetFenetre(QWidget *parent = nullptr);

    /**
     * @brief Réinitialise les champs de recherche et les filtres.
     */
    void reinitialiserChamps();


signals:
    /**
     * @brief Signal émis lorsqu’une recherche est lancée.
     * @param depart Lieu de départ.
     * @param arrivee Lieu d’arrivée.
     * @param date Date du trajet.
     */
    void rechercheLancee(QString depart, QString arrivee, QString date);

    /**
     * @brief Signal émis lorsqu’un critère de filtrage est sélectionné.
     * @param critere Le nom du critère ("prix", "co2", "heure", "duree").
     */
    void filtrageDemande(QString critere);

    /**
     * @brief Signal émis lorsqu’un trajet est sélectionné dans la liste.
     * @param trajet Le trajet sélectionné.
     */
    void trajetClique(const Trajet&);

    /**
     * @brief Signal émis pour retourner à l’accueil.
     */
    void retourAccueil();

public slots:
    /**
     * @brief Affiche les résultats de la recherche dans la liste.
     * @param resultats Vecteur de trajets correspondant aux critères de recherche.
     */
    void afficherResultats(const std::vector<Trajet>& resultats);    

private slots:
    /**
     * @brief Slot déclenché lors du clic sur le bouton "Rechercher".
     */
    void onRechercheClicked();

    /**
     * @brief Slot déclenché lors du clic sur un filtre.
     */
    void onFiltrerClicked();

    /**
     * @brief Slot déclenché lorsqu’un trajet est sélectionné dans la liste.
     * @param item Élément sélectionné.
     */
    void onTrajetSelectionne(QListWidgetItem *item);

    /**
     * @brief Slot déclenché lors du clic sur le bouton "Accueil".
     */
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


#endif 
