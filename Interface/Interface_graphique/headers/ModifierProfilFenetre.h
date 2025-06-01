/**
 * @file ModifierProfilFenetre.h
 * @author Ilheme YAYA
 * @brief  Déclaration de la classe ModifierProfilFenetre, interface de modification du profil utilisateur.
 * @version 0.1
 * 
 * Cette classe permet à l’utilisateur d’afficher et modifier les informations de son profil :
 * nom, prénom, email, mot de passe, adresse postale et statut de fumeur. Elle propose une interface
 * avec des champs pré-remplis et un système de validation ciblée.
 * 
 */
#ifndef MODIFIERPROFILFENETRE_H
#define MODIFIERPROFILFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QLabel>

#include "../../../Modele/Modele_hpp/Utilisateur.hpp"

/**
 * @class ModifierProfilFenetre
 * @brief Fenêtre permettant à l’utilisateur de modifier les informations de son profil.
 */
class ModifierProfilFenetre : public QWidget {
    Q_OBJECT

public:
     /**
     * @brief Constructeur de la classe ModifierProfilFenetre.
     * @param parent Le widget parent (nullptr par défaut).
     */
    explicit ModifierProfilFenetre(QWidget *parent = nullptr);

    /**
     * @brief Réinitialise les champs de saisie et de sélection.
     */
    void reinitialiserChamps();

    /**
     * @brief Affiche les informations actuelles d’un utilisateur dans les champs.
     * @param utilisateur L’utilisateur dont les données doivent être affichées.
     */
    void afficherUtilisateur(const Utilisateur& utilisateur);


signals:
   /**
     * @brief Signal émis pour demander la modification d’un champ.
     * @param champ Le champ à modifier (ex. "email", "motPasse").
     * @param valeur La nouvelle valeur saisie.
     */
    void modificationDemandee(const QString &champ, const QString &valeur);

    /**
     * @brief Signal émis pour retourner à la fenêtre d’accueil.
     */
    void retourAccueil();


private slots:
     /**
     * @brief Slot appelé lors du clic sur le bouton "Valider".
     */
    void onValiderClicked();

    /**
     * @brief Slot appelé lors du changement de champ sélectionné.
     * @param champ Le champ actuellement sélectionné dans la liste déroulante.
     */
    void onChampChanged(const QString &champ);

    /**
     * @brief Slot appelé lors du clic sur le bouton "Accueil".
     */
    void onAccueilClicked();


private:
    // Champs d’affichage d’informations
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *motDePasseLineEdit;
    QLineEdit *adresseLineEdit;
    QCheckBox *fumeurCheckBox;

    // Éléments pour la modification
    QComboBox *champCombo;     
    QLineEdit *valeurEdit;     
    QCheckBox *fumeurCheck;   
    QPushButton *validerBtn; 
    QPushButton *accueilBtn;

};

#endif 
