#ifndef CONNEXIONFENETRE_H
#define CONNEXIONFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>

class ConnexionFenetre : public QWidget {
    Q_OBJECT

public:
    ConnexionFenetre(QWidget *parent = nullptr); //. constructeur
    QString getEmail() const; // recupère ce qui est saisie par l'utilisateur
    QString getMotDePasse() const;
    void afficherMessageSucces(const QString &message);
    void afficherErreur(const QString &message);
    void reinitialiserChamps();

signals:
    void connexionDemandee(QString email, QString motDePasse);
    void demandeInscription();

private slots:
    void onConnexionClicked();
    void onInscriptionCliquee();

private:
    QLineEdit *emailLineEdit;
    QLineEdit *motDePasseLineEdit;
    QPushButton *loginButton;
    QLabel *iconLabel;
};



#endif // CONNEXIONFENETRE_H
