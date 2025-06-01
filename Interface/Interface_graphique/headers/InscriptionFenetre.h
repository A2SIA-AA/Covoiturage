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

class InscriptionFenetre : public QWidget {
    Q_OBJECT

public:
    InscriptionFenetre(QWidget *parent = nullptr);
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getMotDePasse() const;
    QString getAdressePostale() const;
    bool estFumeur() const;

    void afficherMessageSucces(const QString &message);
    void afficherErreur(const QString &message);
    void reinitialiserChamps();

signals:
    void inscriptionDemandee(QString nom, QString prenom, QString email, QString motDePasse, QString adressePostale, bool fumeur);
    void retourConnexion();

private slots:
    void onInscriptionClicked();
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


#endif // INSCRIPTIONFENETRE_H
