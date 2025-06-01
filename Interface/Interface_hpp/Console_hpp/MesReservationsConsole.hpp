// MesReservationsConsole.hpp

#ifndef MESRESERVATIONSCONSOLE_HPP
#define MESRESERVATIONSCONSOLE_HPP

#include "../../Modele/Modele_hpp/Passager.hpp"
#include "../MesReservationsInterface.hpp"
#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include "../../Controlleur/Controlleur_hpp/TrajetControlleur.hpp"

class MesReservationsConsole : public MesReservationsInterface {
public:
    // Constructeur
    explicit MesReservationsConsole(Database& db);

    // Destructeur
    ~MesReservationsConsole() override;

    // Affiche, à partir d’un objet Passager, la liste de ses réservations
    void afficherReservations(const Passager& passager) override;

    // Version interactive : l’utilisateur saisit son ID, liste ses réservations,
    // puis peut en supprimer une ou retourner au menu
    void afficherReservations();

private:
    Database& db;
    TrajetControlleur controller;

    // Supprime la réservation dont on passe l’ID
    void supprimerReservation(int idReservation);
};

#endif // MESRESERVATIONSCONSOLE_HPP
