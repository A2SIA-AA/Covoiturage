#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <iostream>
#include "Utilisateur.hpp"
#include "Trajet.hpp"
#include "Avis.hpp"
#include "Paiement.hpp"
#include "Reservation.hpp"

class Database {
	
	private: sqlite3* db;
	public:
    		Database(const std::string& filename);
    		~Database();

    	bool execute(const std::string& query);
    	void initTables();  // Déclaration de la fonction d'initialisation
};

#endif
