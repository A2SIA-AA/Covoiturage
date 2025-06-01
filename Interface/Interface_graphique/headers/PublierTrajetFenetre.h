/**
 * @file PublierTrajetFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe PublierTrajetFenetre, interface de publication d’un nouveau trajet.
 * @version 0.1
 * 
 * Cette classe représente une fenêtre permettant à un conducteur de saisir les détails d’un trajet
 * pour le publier. Elle comprend des champs obligatoires, des options (carburant, animaux) et des
 * vérifications de saisie.
 */
#ifndef PUBLIERTRAJETFENETRE_H
#define PUBLIERTRAJETFENETRE_H


#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>


/**
 * @class PublierTrajetFenetre
 * @brief Interface utilisateur permettant à un conducteur de publier un trajet.
 */
class PublierTrajetFenetre : public QWidget {
    Q_OBJECT

public:
     /**
     * @brief Constructeur de la classe PublierTrajetFenetre.
     * @param parent Le widget parent (nullptr par défaut).
     */
    explicit PublierTrajetFenetre(QWidget *parent = nullptr);

    /**
     * @brief Réinitialise tous les champs du formulaire.
     */
    void reinitialiserChamps();

signals:

    /**
     * @brief Signal émis lorsque l’utilisateur soumet un trajet.
     * @param date Date du trajet.
     * @param heureDepart Heure de départ.
     * @param heureArrivee Heure d’arrivée.
     * @param lieuDepart Lieu de départ.
     * @param lieuArrivee Lieu d’arrivée.
     * @param prix Prix par place.
     * @param distance Distance totale du trajet.
     * @param voiture Modèle ou description du véhicule.
     * @param nombrePlaces Nombre de places disponibles.
     * @param consommation Consommation moyenne (L/100km).
     * @param anciennete Ancienneté de la voiture.
     * @param carburant Type de carburant (essence, diesel, électrique).
     * @param description Description libre du trajet.
     * @param animaux Indique s'il a un animal avec lui pour le trajet .
     */
    void trajetSoumis(
        const QString& date,
        const QString& heureDepart,
        const QString& heureArrivee,
        const QString& lieuDepart,
        const QString& lieuArrivee,
        float prix,
        float distance,
        const QString& voiture,
        int nombrePlaces,
        float consommation,
        int anciennete,
        const QString& carburant,
        const QString& description,
        bool animaux
    );

    /**
     * @brief Signal émis pour retourner à l’accueil.
     */
    void retourAccueil();


private slots:
    /**
     * @brief Slot appelé lors du clic sur le bouton "Publier".
     */
    void onPublierClicked();

    /**
     * @brief Slot appelé lors du clic sur le bouton "Accueil".
     */
    void onAccueilClicked();


private:
    //Champs de saisie
    QLineEdit *dateEdit;
    QLineEdit *heureDepartEdit;
    QLineEdit *heureArriveeEdit;
    QLineEdit *lieuDepartEdit;
    QLineEdit *lieuArriveeEdit;
    QLineEdit *prixEdit;
    QLineEdit *distanceEdit;
    QLineEdit *voitureEdit;
    QLineEdit *placesEdit;
    QLineEdit *consommationEdit;
    QLineEdit *ancienneteEdit;
    QTextEdit *descriptionEdit;

    QCheckBox *animauxCheck;

    QRadioButton *essenceRadio;
    QRadioButton *dieselRadio;
    QRadioButton *electriqueRadio;
    QButtonGroup *carburantGroup;
    QPushButton *accueilBtn;
    QPushButton *publierBtn;
};

#endif 
