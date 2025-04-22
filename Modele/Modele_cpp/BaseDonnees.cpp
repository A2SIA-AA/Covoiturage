#include <iostream>
#include <stdexcept>
#include <utility>
#include "Utilisateur.cpp"
#include "Trajet.cpp"
#include "Reservation.cpp"
#include "Conducteur.cpp"
#include "Passager.cpp"
#include "Modele_hpp/BaseDonnees.hpp"

/**
 *
 * @param filename
 */
Database::Database(const std::string& filename) {
    1;\
    if (sqlite3_open(filename.c_str(), &db)) {
        std::cerr << "Erreur ouverture BDD : " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        std::cout << "Connexion à la base de données réussie.\n";
        initTables();
    }
}

bool Database::isConnected() const {
    return db != nullptr;
}

Database::~Database() {
    if (db) sqlite3_close(db);
}
/**
 *
 * @param query
 * @return
 */

bool Database::execute(const std::string query) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur SQLite : " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}


void Database::initTables(){
	std::string createUtilisateurTable = R"(
        CREATE TABLE IF NOT EXISTS utilisateurs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nom TEXT,
            prenom TEXT,
            email TEXT,
            mdp TEXT,
            adressePostale TEXT
        );
    )";

    std::string createConducteurTable = R"(
        CREATE TABLE IF NOT EXISTS conducteurs (
            id INTEGER PRIMARY KEY,
            FOREIGN KEY(id) REFERENCES utilisateur(id) ON DELETE CASCADE
        );
    )";

    std::string createPassagerTable = R"(
        CREATE TABLE IF NOT EXISTS passagers (
            id INTEGER PRIMARY KEY,
            FOREIGN KEY(id) REFERENCES utilisateur(id) ON DELETE CASCADE
        );
    )";
        std::string createTrajetTable = R"(
        CREATE TABLE IF NOT EXISTS trajets (
            idTrajet INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT,
            heureDepart TEXT,
            heureArrivee TEXT,
            lieuDepart TEXT,
            lieuArrivee TEXT,
            disponible INTEGER, -- BOOLEAN sous forme d'entier (0 ou 1)
            allerRetour INTEGER, -- BOOLEAN sous forme d'entier (0 ou 1)
            animaux INTEGER, -- BOOLEAN sous forme d'entier (0 ou 1)
            voiture TEXT,
            nombrePlaceDispo INTEGER,
            etat INTEGER, -- BOOLEAN sous forme d'entier (0 ou 1)
            emissionCO2 REAL,
            description TEXT,
            FOREIGN KEY(idConducteur) REFERENCES conducteurs(id)
        );
    )";

    // Création de la table 'SegmentPrix'
    std::string createSegmentsTable = R"(
        CREATE TABLE IF NOT EXISTS segment_prix (
            idSegment INTEGER PRIMARY KEY AUTOINCREMENT,
            idTrajet INTEGER,
            segment TEXT,  -- Le nom du segment (par exemple, "Paris-Lyon")
            prix REAL,     -- Le prix du segment
            FOREIGN KEY(idTrajet) REFERENCES trajet(idTrajet)
        );
    )";

    // Création de la table 'VilleEtape'
    std::string createVillesEtapesTable = R"(
        CREATE TABLE IF NOT EXISTS ville_etape (
            idEtape INTEGER PRIMARY KEY AUTOINCREMENT,
            idTrajet INTEGER,
            ville TEXT,  -- Nom de la ville de l'étape
            FOREIGN KEY(idTrajet) REFERENCES trajet(idTrajet)
        );
    )";
    std::string createReservationTable = R"(
    CREATE TABLE IF NOT EXISTS reservations (
        idReservation INTEGER PRIMARY KEY AUTOINCREMENT,
        prix REAL,
        statut BOOLEAN,
        FOREIGN KEY(idTrajet) REFERENCES trajet(idTrajet),
        FOREIGN KEY(idPassager) REFERENCES Passager(id)

    );
)";

    this->execute(createUtilisateurTable);
    this->execute(createConducteurTable);
    this->execute(createPassagerTable);
    this->execute(createTrajetTable);
    this->execute(createSegmentsTable);
    this->execute(createVillesEtapesTable);
    this->execute(createReservationTable);

    std::cout << "Tables de la base de données initialisées." << std::endl;
}

    bool Database::ajouterUtilisateur(Utilisateur u){
        std::string sql = "INSERT INTO utilisateurs (idUtilisateur, nom, prenom, email, mdp, adressePostale) VALUES (?, ?, ?, ?, ?, ?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
            return false;
        }
        sqlite3_bind_int(stmt, 1, u.getIdUtilisateur());
        sqlite3_bind_text(stmt, 2, u.getNom().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, u.getPrenom().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, u.getEmail().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, u.getMotPasse().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 6, u.getAdressePostale().c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Erreur exécution insertion : " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            return false;
        }

        sqlite3_finalize(stmt);
        return true;
    }

    Utilisateur getUtilisateurByEmailAndMDP(std::string email, std::string mdp){

    }
    bool Database::ajouterTrajet(Trajet t, int idConducteur){
            std::string sql = R"(
        INSERT INTO trajets (
            date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
            disponible, allerRetour, animaux, voiture,
            nombrePlaceDispo, etat, emissionCO2, description, idConducteur
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )";

            sqlite3_stmt* stmt;
            if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
                std::cerr << "Erreur préparation insertion trajet : " << sqlite3_errmsg(db) << std::endl;
                return false;
            }

            sqlite3_bind_text(stmt, 1, t.getDate().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, t.getHeureDepart().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 3, t.getHeureArrive().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 4, t.getLieuDepart().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 5, t.getLieuArrive().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 6, t.getDisponible());
            sqlite3_bind_int(stmt, 7, t.getAllerRetour());
            sqlite3_bind_int(stmt, 8, t.getAnimaux());
            sqlite3_bind_text(stmt, 9, t.getVoiture().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 10, t.getNombrePlaceDispo());
            sqlite3_bind_int(stmt, 11, t.getEtat());
            sqlite3_bind_double(stmt, 12, t.getEmissionCO2());
            sqlite3_bind_text(stmt, 13, t.getDescription().c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 14, idConducteur);

            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Erreur insertion trajet : " << sqlite3_errmsg(db) << std::endl;
                sqlite3_finalize(stmt);
                return false;
            }

            int idTrajet = sqlite3_last_insert_rowid(db); // Récupération de l’id du trajet
            sqlite3_finalize(stmt);

            // Ajouter les segments liés
            for (const auto& seg : t.getSegmentsPrix()) {
                ajouterSegmentsPrix(idTrajet, seg.first, seg.second);
            }

            // Ajouter les étapes
            for (const auto& ville : t.getVillesEtapes()) {
                ajouterPointIntermediaire(idTrajet, ville);
            }

            return true;
        }

    bool Database::ajouterPointIntermediaire(int idTrajet, std::string NomVille ) {
        std::string sql = "INSERT INTO ville_etape (idTrajet, ville) VALUES (?, ?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur préparation étape : " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        sqlite3_bind_int(stmt, 1, idTrajet);
        sqlite3_bind_text(stmt, 2, NomVille.c_str(), -1, SQLITE_TRANSIENT);

        bool success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
        return success;
    }

    bool Database::ajouterSegmentsPrix(int idTrajet, const std::string& segment, float prix){
        std::string sql = "INSERT INTO segment_prix (idTrajet, segment, prix) VALUES (?, ?, ?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur préparation segment : " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        sqlite3_bind_int(stmt, 1, idTrajet);
        sqlite3_bind_text(stmt, 2, segment.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 3, prix);

        bool success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
        return success;
    }

    bool Database::ajouterReservation(Reservation r){
        std::string sql = "INSERT INTO reservations (prix, statut, idTrajet, idPassager) VALUES (?, ?, ?, ?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur préparation ajout réservation : " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        sqlite3_bind_double(stmt, 1, r.getPrix());
        sqlite3_bind_int(stmt, 2, r.getStatut() ? 1 : 0);
        sqlite3_bind_int(stmt, 3, r.getIdTrajet());
        sqlite3_bind_int(stmt, 4, r.getIdUtilisateur());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Erreur insertion réservation : " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            return false;
        }

        sqlite3_finalize(stmt);
        return true;

    }

    Trajet getTrajetByIdTrajet(int idTrajet){

}

    Trajet getTrajetByVilleDepartEtArriveeEtDateDepart(std::string villeDepart, std::string villeArrivee,std::string date){
    }

    Trajet getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(std::string villeDepart, std::string villeArrivee,std::string date, int prix){

    }

    Trajet getTrajetByVilleDepartEtArriveeEtEmissionCO2(std::string villeDepart, std::string villeArrivee,std::string date, float emissionCO2) {
    }

    Reservation getReservationByID(int ID){

    }
    float getEmissionCO2ByIdTraget(int IDTrajet){

    }

    std::vector<std::pair<std::string, float>> getPrixByIdTrajet(int idTrajet){
    }

    std::vector<std::string> getPointIntermediaireByIdTrajet(int IDTrajet){

    }

    std::string getDateDepatByIdTrajet(int IDTrajet){

    }
    std::string getDateArriveeByIdTrajet(int IDTrajet){

    }
    std::string getHeureArriveeByIdTrajet(int IDTrajet){

    }
    std::string getHeureDepartByIdTrajet(int IDTrajet){

    }
    std::string getVilleArriveeByIdTrajet(int IDTrajet){

    }
    std::string getVilleDepartByIdTrajet(int IDTrajet){

    }

    Conducteur getConducteurByID(int idUtilisateur){

    }
    Passager getPassagerByID(int idUtilisateur){

    }


    void supprimerTrajetByIDTrajet(int idTrajet){

}
    void supprimerReservationByIDReservation(int idReservation){

}

