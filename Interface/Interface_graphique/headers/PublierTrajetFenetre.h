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

class PublierTrajetFenetre : public QWidget {
    Q_OBJECT

public:
    explicit PublierTrajetFenetre(QWidget *parent = nullptr);
    void reinitialiserChamps();

signals:
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

    void retourAccueil();


private slots:
    void onPublierClicked();
    void onAccueilClicked();


private:
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

#endif // PUBLIERTRAJETFENETRE_H
