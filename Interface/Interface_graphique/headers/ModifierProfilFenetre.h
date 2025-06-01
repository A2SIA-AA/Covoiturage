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


class ModifierProfilFenetre : public QWidget {
    Q_OBJECT

public:
    explicit ModifierProfilFenetre(QWidget *parent = nullptr);
    void reinitialiserChamps();
    void afficherUtilisateur(const Utilisateur& utilisateur);


signals:
    // Signal envoyé au contrôleur avec :
    // - le champ à modifier ("nom", "prenom", "email", etc.)
    // - la valeur modifiée, toujours en QString
    void modificationDemandee(const QString &champ, const QString &valeur);
    void retourAccueil();


private slots:
    void onValiderClicked();
    void onChampChanged(const QString &champ);
    void onAccueilClicked();


private:
    //Pour l'affichhage
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *motDePasseLineEdit;
    QLineEdit *adresseLineEdit;
    QCheckBox *fumeurCheckBox;



    //pour les modifications
    QComboBox *champCombo;     // Pour choisir le champ à modifier
    QLineEdit *valeurEdit;     // Champ pour saisir la nouvelle valeur
    QCheckBox *fumeurCheck;    // Case à cocher pour "fumeur"
    QPushButton *validerBtn;   // Bouton de validation
    QPushButton *accueilBtn;

};

#endif // MODIFIERPROFILFENETRE_H
