#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <iostream>
#include <stdexcept>
#include "Utilisateur.hpp"
#include "Trajet.hpp"
#include "Avis.hpp"
#include "Paiement.hpp"
#include "Reservation.hpp"
#include "Conducteur.hpp"
#include "Passager.hpp"

class Database {
	
	private: sqlite3* db;
	public:
    		Database(const std::string& filename);
    		~Database();

    	bool execute(const std::string& query);
    	void initTables();  // Déclaration de la fonction d'initialisation
        void ajouterUtilisateur(std::string nom, std::string prenom, std::string email, std::string mdp, std::string adressePostale, bool fumer);
        Utilisateur getUtilisateurByEmailAndMDP(std::string email, std::string mdp);
        void ajouterTrajet(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);
        void ajouterReservation(float prix, int ID, bool statut);
        void ajouterAvis(int note, std::string commentaire, std::string typeAvis);
        Trajet getTrajetByVilleDepartEtArrivee(std::string villeDepart, std::string villeArrivee);
        Reservation getReservationByID(int ID);
        float getEmissionCO2ByIdTraget(int IDTrajet);
        vector<pair<string, float>> getPrixByIdTrajet(int IDTrajet);
        vector<std::string> getPointIntermediaireByIdTrajet(int IDTrajet);
        std::string getDateDepatByIdTrajet(int IDTrajet);
        std::string getDateArriveeByIdTrajet(int IDTrajet);
        std::string getHeureArriveeByIdTrajet(int IDTrajet);
        std::string getHeureDepartByIdTrajet(int IDTrajet);
        std::string getVilleArriveeByIdTrajet(int IDTrajet);
        std::string getVilleDepartByIdTrajet(int IDTrajet);
        Avis getAvisByIdTrajet(int IDTrajet);
        Conducteur getConducteurByID(int idUtilisateur);
        Passager getPassagerByID(int idUtilisateur);





};

#endif
