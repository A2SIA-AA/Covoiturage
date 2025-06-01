/**
 * @file ConnexionFenetre.h
 * @author Ilheme YAYA
 * @brief Déclaration de la classe ConnexionFenetre, interface de connexion utilisateur.
 * @version 0.1
 * 
 * Cette classe représente la fenêtre permettant à un utilisateur de se connecter à l'application
 * en saisissant son email et son mot de passe. Elle offre également un accès à l'inscription
 * pour les nouveaux utilisateurs.
 */


#ifndef CONNEXIONFENETRE_H
#define CONNEXIONFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>


/**
 * @class ConnexionFenetre
 * @brief Fenêtre d'interface utilisateur pour la connexion.
 */
class ConnexionFenetre : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe ConnexionFenetre.
     * @param parent Le widget parent, nullptr par défaut.
     */
    ConnexionFenetre(QWidget *parent = nullptr); 

    /**
     * @brief Récupère le contenu du champ email.
     * @return Email saisi par l'utilisateur.
     */
    QString getEmail() const; 

    /**
     * @brief Récupère le contenu du champ mot de passe.
     * @return Mot de passe saisi par l'utilisateur.
     */
    QString getMotDePasse() const;

    /**
     * @brief Affiche un message de succès dans une boîte de dialogue.
     * @param message Le message à afficher.
     */
    void afficherMessageSucces(const QString &message);

    /**
     * @brief Affiche un message d'erreur dans une boîte de dialogue.
     * @param message Le message à afficher.
     */
    void afficherErreur(const QString &message);

    /**
     * @brief Réinitialise les champs du formulaire (email et mot de passe).
     */
    void reinitialiserChamps();

signals:
    /**
     * @brief Signal envoyé au contrôleur lors d'une tentative de connexion.
     * @param email L'adresse email saisie.
     * @param motDePasse Le mot de passe saisi.
     */
    void connexionDemandee(QString email, QString motDePasse);

    /**
     * @brief Signal envoyé lorsqu'un utilisateur souhaite s'inscrire.
     */
    void demandeInscription();

private slots:
    /**
     * @brief Slot déclenché lors du clic sur le bouton de connexion.
     */
    void onConnexionClicked();

    /**
     * @brief Slot déclenché lors du clic sur le lien d'inscription.
     */
    void onInscriptionCliquee();

private:
    QLineEdit *emailLineEdit;
    QLineEdit *motDePasseLineEdit;
    QPushButton *loginButton;
    QLabel *iconLabel;
};



#endif 
