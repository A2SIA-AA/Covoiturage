/**
 * @file InscriptionFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe InscriptionFenetre, interface utilisateur pour l’inscription.
 * @version 0.1
 * 
 * Cette classe représente la fenêtre d’inscription d’un nouvel utilisateur. Elle permet de
 * renseigner les informations personnelles nécessaires à la création d’un compte.
 */
#ifndef INSCRIPTIONFENETRE_H
#define INSCRIPTIONFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>

/**
 * @class InscriptionFenetre
 * @brief Interface graphique pour l’inscription d’un utilisateur.
 */
class InscriptionFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe InscriptionFenetre.
     * @param parent Le widget parent (nullptr par défaut).
     */
    InscriptionFenetre(QWidget *parent = nullptr);

    /**
     * @brief Récupère le nom saisi par l’utilisateur.
     * @return Nom de l’utilisateur.
     */
    QString getNom() const;

    /**
     * @brief Récupère le prénom saisi par l’utilisateur.
     * @return Prénom de l’utilisateur.
     */
    QString getPrenom() const;

    /**
     * @brief Récupère l’adresse email saisie par l’utilisateur.
     * @return Email de l’utilisateur.
     */
    QString getEmail() const;

    /**
     * @brief Récupère le mot de passe saisi.
     * @return Mot de passe.
     */
    QString getMotDePasse() const;

    /**
     * @brief Récupère l’adresse postale saisie.
     * @return Adresse postale.
     */
    QString getAdressePostale() const;

    /**
     * @brief Indique si l’utilisateur est fumeur ou non.
     * @return true si fumeur, false sinon.
     */
    bool estFumeur() const;

    /**
     * @brief Affiche un message de succès à l’utilisateur.
     * @param message Message à afficher.
     */
    void afficherMessageSucces(const QString &message);

    /**
     * @brief Affiche un message d’erreur à l’utilisateur.
     * @param message Message à afficher.
     */
    void afficherErreur(const QString &message);

    /**
     * @brief Réinitialise tous les champs du formulaire.
     */
    void reinitialiserChamps();

signals:
    /**
     * @brief Signal émis lorsqu’une inscription est demandée.
     * @param nom Nom de l’utilisateur.
     * @param prenom Prénom de l’utilisateur.
     * @param email Email de l’utilisateur.
     * @param motDePasse Mot de passe.
     * @param adressePostale Adresse postale.
     * @param fumeur true si fumeur, false sinon.
     */
    void inscriptionDemandee(QString nom, QString prenom, QString email, QString motDePasse, QString adressePostale, bool fumeur);

    /**
     * @brief Signal émis lorsque l’utilisateur souhaite retourner à la fenêtre de connexion.
     */
    void retourConnexion();

private slots:
    /**
     * @brief Slot déclenché lors du clic sur le bouton d’inscription.
     */
    void onInscriptionClicked();

    /**
     * @brief Slot déclenché lors du clic sur le bouton de retour à la connexion.
     */
    void onRetourConnexionClique();

private:
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *motDePasseLineEdit;
    QLineEdit *adressePostaleLineEdit;
    QCheckBox *fumeurCheckBox;
    QPushButton *inscriptionButton;
};


#endif 
