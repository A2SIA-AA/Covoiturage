#include "BaseDonnees.hpp"
#include <iostream>
/**
 *
 * @param filename
 */
Database::Database(const std::string& filename) {
    if (sqlite3_open(filename.c_str(), &db)) {
        std::cerr << "Erreur ouverture BDD : " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
}
/**
 *
 */
Database::~Database() {
    if (db) sqlite3_close(db);
}

/**
 *
 * @param query
 * @return
 */
bool Database::execute(const std::string& query) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur SQLite : " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
/**
 *
 */
void initTables(){
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
            FOREIGN KEY(id) REFERENCES utilisateur(id)
        );
    )";

    std::string createPassagerTable = R"(
        CREATE TABLE IF NOT EXISTS passagers (
            id INTEGER PRIMARY KEY,
            FOREIGN KEY(id) REFERENCES utilisateur(id)
        );
    )";
        std::string createTrajetTable = R"(
        CREATE TABLE IF NOT EXISTS trajet (
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
            description TEXT
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
    CREATE TABLE IF NOT EXISTS reservation (
        idReservation INTEGER PRIMARY KEY AUTOINCREMENT,
        prix REAL,
        statut BOOLEAN
    );
)";

    std::string createAvisTable = R"(
    CREATE TABLE IF NOT EXISTS avis (
        idTrajet INTEGER PRIMARY,
        note INTEGER,
        commentaire TEXT,
        typeAvis TEXT,
        FOREIGN KEY(idTrajet) REFERENCES trajet(idTrajet)
    );
)";

    void ajouterUtilisateur(std::string nom, std::string prenom, std::string email, std::string mdp, std::string adressePostale, bool fumer){

    };

    Utilisateur getUtilisateurByEmailAndMDP(std::string email, std::string mdp){

    }
    void ajouterTrajet(int idTrajet, std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description){

    }
    void ajouterReservation(float prix, int ID, bool statut){

    }
    void ajouterAvis(int note, std::string commentaire, std::string typeAvis){

    }
    Trajet getTrajetByVilleDepartEtArrivee(std::string villeDepart, std::string villeArrivee){

    }
    Reservation getReservationByID(int ID){

    }
    float getEmissionCO2ByIdTraget(int IDTrajet){

    }
    vector<pair<string, float>> getPrixByIdTrajet(int IDTrajet){

    }
    vector<std::string> getPointIntermediaireByIdTrajet(int IDTrajet){

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
    Avis getAvisByIdTrajet(int IDTrajet){

    }
    Conducteur getConducteurByID(int idUtilisateur){

    }
    Passager getPassagerByID(int idUtilisateur){

    }
    
};


