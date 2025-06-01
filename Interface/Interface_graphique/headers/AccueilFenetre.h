#ifndef ACCUEILFENETRE_H
#define ACCUEILFENETRE_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>

class AccueilFenetre : public QMainWindow {
    Q_OBJECT

public:
    explicit AccueilFenetre(QWidget *parent = nullptr);
    ~AccueilFenetre();

signals:
    /**
     * @brief Signal envoyé au contrôleur pour naviguer vers une autre page.
     * @param nomPage "modifierProfil", "rechercherTrajet", "publierTrajet", "mesReservations", "mesAnnonces", "deconnecter"
     */
    void demandeNavigation(const QString &nomPage);

private slots:
    void onModifierProfil();
    void onRechercherTrajet();
    void onPublierTrajet();
    void onMesReservations();
    void onMesAnnonces();
    void onDeconnecter();

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QMenuBar *menuBar;

    QPushButton *btnModifierProfil;
    QPushButton *btnRechercherTrajet;
    QPushButton *btnPublierTrajet;
    QPushButton *btnMesReservations;
    QPushButton *btnMesAnnonces;
    QPushButton *btnDeconnecter;
};

#endif
