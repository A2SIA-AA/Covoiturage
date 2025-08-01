#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include "../Modele_hpp/BaseDonnees.hpp"

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
            idUtilisateur INTEGER PRIMARY KEY AUTOINCREMENT,
            nom TEXT,
            prenom TEXT,
            email TEXT,
            mdp TEXT,
            adressePostale TEXT,
            fumeur BOOLEAN DEFAULT 0
        );
    )";

    std::string createConducteurTable = R"(
        CREATE TABLE IF NOT EXISTS conducteurs (
            id INTEGER PRIMARY KEY,
            FOREIGN KEY(id) REFERENCES utilisateurs(idUtilisateur) ON DELETE CASCADE
        );
    )";

    std::string createPassagerTable = R"(
        CREATE TABLE IF NOT EXISTS passagers (
            id INTEGER PRIMARY KEY,
            FOREIGN KEY(id) REFERENCES utilisateurs(idUtilisateur) ON DELETE CASCADE
        );
    )";
        std::string createTrajetTable = R"(
        CREATE TABLE IF NOT EXISTS trajets (
            idTrajet INTEGER PRIMARY KEY AUTOINCREMENT,
            idConducteur INTEGER,
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
            segment TEXT,
            prix REAL,
            FOREIGN KEY(idTrajet) REFERENCES trajets(idTrajet)
        );
    )";

    // Création de la table 'VilleEtape'
    std::string createVillesEtapesTable = R"(
        CREATE TABLE IF NOT EXISTS ville_etape (
            idEtape INTEGER PRIMARY KEY AUTOINCREMENT,
            idTrajet INTEGER,
            ville TEXT,  -- Nom de la ville de l'étape
            FOREIGN KEY(idTrajet) REFERENCES trajets(idTrajet)
        );
    )";
    std::string createReservationTable = R"(
    CREATE TABLE IF NOT EXISTS reservations (
        idReservation INTEGER PRIMARY KEY AUTOINCREMENT,
        prix REAL,
        statut BOOLEAN,
        idPassager INTEGER,
        idTrajet INTEGER,
        FOREIGN KEY(idTrajet) REFERENCES trajets(idTrajet),
        FOREIGN KEY(idPassager) REFERENCES passagers(id)

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
        sqlite3_bind_null(stmt,1);
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

Utilisateur Database::getUtilisateurByEmailAndMDP(std::string email, std::string mdp) {
    std::string sql = R"(
        SELECT idUtilisateur, nom, prenom, email, mdp, adressePostale, fumeur
        FROM utilisateurs
        WHERE email = ? AND mdp = ?
    )";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, mdp.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int idUtilisateur = sqlite3_column_int(stmt, 0);
        std::string nom = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string prenom = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string emailDB = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string mdpDB = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string adressePostale = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        bool fumeur = sqlite3_column_int(stmt, 6);

        Utilisateur user(nom, prenom, emailDB, mdpDB, adressePostale, fumeur);
        user.setIdUtilisateur(idUtilisateur);
        sqlite3_finalize(stmt);
        return user;
    }

    sqlite3_finalize(stmt);
    throw std::runtime_error("Utilisateur non trouvé");
}



bool Database::modifierUtilisateur(Utilisateur u) {
    std::string sql = R"(
        UPDATE utilisateurs
        SET nom = ?, prenom = ?, email = ?, mdp = ?, adressePostale = ?, fumeur = ?
        WHERE idUtilisateur = ?)";

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation modification utilisateur : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, u.getNom().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, u.getPrenom().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, u.getEmail().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, u.getMotPasse().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, u.getAdressePostale().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, u.getFumeur() ? 1 : 0);
    sqlite3_bind_int(stmt, 7, u.getIdUtilisateur());
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur mise à jour utilisateur : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}



bool Database::ajouterTrajet(Trajet t, int idConducteur) {
    std::string sql = R"(
        INSERT INTO trajets (
            idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
            disponible, allerRetour, animaux, voiture,
            nombrePlaceDispo, etat, emissionCO2, description, idConducteur
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation insertion trajet : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_null(stmt, 1);

    sqlite3_bind_text(stmt, 2, t.getDate().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, t.getHeureDepart().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, t.getHeureArrive().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, t.getLieuDepart().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, t.getLieuArrive().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 7, t.getDisponible());
    sqlite3_bind_int(stmt, 8, t.getAllerRetour());
    sqlite3_bind_int(stmt, 9, t.getAnimaux());
    sqlite3_bind_text(stmt, 10, t.getVoiture().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 11, t.getNombrePlaceDispo());
    sqlite3_bind_int(stmt, 12, t.getEtat());
    sqlite3_bind_double(stmt, 13, t.getEmissionCO2());
    sqlite3_bind_text(stmt, 14, t.getDescription().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 15, idConducteur);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur insertion trajet : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    int idTrajet = sqlite3_last_insert_rowid(db);
    sqlite3_finalize(stmt);

    for (const auto& seg : t.getSegmentsPrix()) {
        ajouterSegmentsPrix(idTrajet, seg.first, seg.second);
    }

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

bool Database::ajouterReservation(Reservation r) {
    std::string sql = "INSERT INTO reservations (idReservation , idTrajet, statut, prix, idPassager) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation ajout réservation : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    sqlite3_bind_null(stmt, 1);
    sqlite3_bind_int(stmt, 2, r.getIdTrajet());
    sqlite3_bind_int(stmt, 3, r.getStatut() ? 1 : 0);
    sqlite3_bind_double(stmt, 4, r.getPrix());
    sqlite3_bind_int(stmt, 5, r.getIdPassager());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur insertion réservation : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }
    sqlite3_finalize(stmt);

    int idTrajet = r.getIdTrajet();
    int nbPlaceDispo = 0;
    int dispo = 1;

    // Récupérer le nombre de places disponibles actuel
    std::string sqlSelect = "SELECT nombrePlaceDispo FROM trajets WHERE idTrajet = ?;";
    sqlite3_stmt* stmtSelect;
    if (sqlite3_prepare_v2(db, sqlSelect.c_str(), -1, &stmtSelect, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmtSelect, 1, idTrajet);
        if (sqlite3_step(stmtSelect) == SQLITE_ROW) {
            nbPlaceDispo = sqlite3_column_int(stmtSelect, 0);
        }
        sqlite3_finalize(stmtSelect);
    } else {
        std::cerr << "Erreur récupération nombre de places : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    nbPlaceDispo = std::max(0, nbPlaceDispo - 1);

    // Si le nombre de places passe à zéro, mettre la disponibilite à faux
    if (nbPlaceDispo == 0) {
        dispo = 0;
    }

    // Mettre à jour le trajet
    std::string sqlUpdate = "UPDATE trajets SET nombrePlaceDispo = ?, disponible = ? WHERE idTrajet = ?;";
    sqlite3_stmt* stmtUpdate;
    if (sqlite3_prepare_v2(db, sqlUpdate.c_str(), -1, &stmtUpdate, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmtUpdate, 1, nbPlaceDispo);
        sqlite3_bind_int(stmtUpdate, 2, dispo);
        sqlite3_bind_int(stmtUpdate, 3, idTrajet);
        if (sqlite3_step(stmtUpdate) != SQLITE_DONE) {
            std::cerr << "Erreur mise à jour trajet : " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmtUpdate);
            return false;
        }
        sqlite3_finalize(stmtUpdate);
    } else {
        std::cerr << "Erreur préparation mise à jour trajet : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    return true;
}


Trajet Database::getTrajetByIdTrajet(int idTrajet) {
    std::string sql = R"(
        SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, disponible, allerRetour, animaux, voiture, nombrePlaceDispo, etat, emissionCO2, description
        FROM trajets WHERE idTrajet = ?)";

    sqlite3_stmt* stmt;



    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_int(stmt, 1, idTrajet);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int idTrajet = sqlite3_column_int(stmt, 0);
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string heureDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string heureArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string lieuDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string lieuArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        bool disponible = sqlite3_column_int(stmt, 6);
        bool allerRetour = sqlite3_column_int(stmt, 7);
        bool animaux = sqlite3_column_int(stmt, 8);
        std::string voiture = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        int nombrePlaceDispo = sqlite3_column_int(stmt, 10);
        bool etat = sqlite3_column_int(stmt, 11);
        float emissionCO2 = static_cast<float>(sqlite3_column_double(stmt, 12));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 13));

        // Récupérer les segmentsPrix associés à ce trajet
        std::vector<std::pair<std::string, float>> segmentsPrix;
        {
            std::string sqlSeg = "SELECT segment, prix FROM segment_prix WHERE idTrajet = ?";
            sqlite3_stmt* stmtSeg;
            if (sqlite3_prepare_v2(db, sqlSeg.c_str(), -1, &stmtSeg, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtSeg, 1, idTrajet);
                while (sqlite3_step(stmtSeg) == SQLITE_ROW) {
                    std::string segment = reinterpret_cast<const char*>(sqlite3_column_text(stmtSeg, 0));
                    float prix = static_cast<float>(sqlite3_column_double(stmtSeg, 1));
                    segmentsPrix.emplace_back(segment, prix);
                }
            }
            sqlite3_finalize(stmtSeg);
        }

        /*Récupérer les villesEtapes associées à ce trajet
        std::vector<std::string> villesEtapes;
        {
            std::string sqlEtape = "SELECT ville FROM ville_etape WHERE idTrajet = ?";
            sqlite3_stmt* stmtEtape;
            if (sqlite3_prepare_v2(db, sqlEtape.c_str(), -1, &stmtEtape, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtEtape, 1, idTrajet);
                while (sqlite3_step(stmtEtape) == SQLITE_ROW) {
                    std::string ville = reinterpret_cast<const char*>(sqlite3_column_text(stmtEtape, 0));
                    villesEtapes.push_back(ville);
                }
            }
            sqlite3_finalize(stmtEtape);
        }*/

        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, {}, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);

        sqlite3_finalize(stmt);
        return trajet;
    }

    sqlite3_finalize(stmt);
    throw std::runtime_error("Trajet non trouvé");
}


std::vector<Trajet> Database::getTrajetByVilleDepartEtArriveeEtDateDepart(const std::string& villeDepart, const std::string& villeArrivee, const std::string& date) {
    std::vector<Trajet> resultats;
    std::string sql = R"(
        SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
               disponible, allerRetour, animaux, voiture, nombrePlaceDispo,
               etat, emissionCO2, description
        FROM trajets WHERE lieuDepart = ? AND lieuArrivee = ? AND date = ? AND nombrePlaceDispo > 0)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_text(stmt, 1, villeDepart.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, villeArrivee.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, date.c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idTrajet = sqlite3_column_int(stmt, 0);
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string heureDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string heureArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string lieuDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string lieuArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        bool disponible = sqlite3_column_int(stmt, 6);
        bool allerRetour = sqlite3_column_int(stmt, 7);
        bool animaux = sqlite3_column_int(stmt, 8);
        std::string voiture = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        int nombrePlaceDispo = sqlite3_column_int(stmt, 10);
        bool etat = sqlite3_column_int(stmt, 11);
        float emissionCO2 = static_cast<float>(sqlite3_column_double(stmt, 12));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 13));

        // SegmentsPrix
        std::vector<std::pair<std::string, float>> segmentsPrix;
        {
            std::string sqlSeg = "SELECT segment, prix FROM segment_prix WHERE idTrajet = ?";
            sqlite3_stmt* stmtSeg;
            if (sqlite3_prepare_v2(db, sqlSeg.c_str(), -1, &stmtSeg, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtSeg, 1, idTrajet);
                while (sqlite3_step(stmtSeg) == SQLITE_ROW) {
                    std::string segment = reinterpret_cast<const char*>(sqlite3_column_text(stmtSeg, 0));
                    float prix = static_cast<float>(sqlite3_column_double(stmtSeg, 1));
                    segmentsPrix.emplace_back(segment, prix);
                }
            }
            sqlite3_finalize(stmtSeg);
        }
        /*VillesEtapes
        std::vector<std::string> villesEtapes;
        {
            std::string sqlEtape = "SELECT ville FROM ville_etape WHERE idTrajet = ?";
            sqlite3_stmt* stmtEtape;
            if (sqlite3_prepare_v2(db, sqlEtape.c_str(), -1, &stmtEtape, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtEtape, 1, idTrajet);
                while (sqlite3_step(stmtEtape) == SQLITE_ROW) {
                    std::string ville = reinterpret_cast<const char*>(sqlite3_column_text(stmtEtape, 0));
                    villesEtapes.push_back(ville);
                }
            }
            sqlite3_finalize(stmtEtape);
        }*/
        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, {}, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);
        resultats.push_back(trajet);
    }
    sqlite3_finalize(stmt);
    return resultats;
}




std::vector<Trajet> Database::getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(const std::string& villeDepart, const std::string& villeArrivee, const std::string& date, int prix) {
    std::vector<Trajet> resultats;
    std::string sql = R"(
        SELECT t.idTrajet, t.date, t.heureDepart, t.heureArrivee, t.lieuDepart, t.lieuArrivee,
               t.disponible, t.allerRetour, t.animaux, t.voiture, t.nombrePlaceDispo,
               t.etat, t.emissionCO2, t.description
        FROM trajets t
        JOIN segment_prix s ON t.idTrajet = s.idTrajet
        WHERE t.lieuDepart = ? AND t.lieuArrivee = ? AND t.date = ? AND s.prix = ? AND t.nombrePlaceDispo > 0)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_text(stmt, 1, villeDepart.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, villeArrivee.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, date.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 4, prix);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idTrajet = sqlite3_column_int(stmt, 0);
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string heureDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string heureArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string lieuDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string lieuArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        bool disponible = sqlite3_column_int(stmt, 6);
        bool allerRetour = sqlite3_column_int(stmt, 7);
        bool animaux = sqlite3_column_int(stmt, 8);
        std::string voiture = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        int nombrePlaceDispo = sqlite3_column_int(stmt, 10);
        bool etat = sqlite3_column_int(stmt, 11);
        float emissionCO2 = static_cast<float>(sqlite3_column_double(stmt, 12));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 13));

        // SegmentsPrix
        std::vector<std::pair<std::string, float>> segmentsPrix;
        {
            std::string sqlSeg = "SELECT segment, prix FROM segment_prix WHERE idTrajet = ?";
            sqlite3_stmt* stmtSeg;
            if (sqlite3_prepare_v2(db, sqlSeg.c_str(), -1, &stmtSeg, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtSeg, 1, idTrajet);
                while (sqlite3_step(stmtSeg) == SQLITE_ROW) {
                    std::string segment = reinterpret_cast<const char*>(sqlite3_column_text(stmtSeg, 0));
                    float prix = static_cast<float>(sqlite3_column_double(stmtSeg, 1));
                    segmentsPrix.emplace_back(segment, prix);
                }
            }
            sqlite3_finalize(stmtSeg);
        }
        /*VillesEtapes
        std::vector<std::string> villesEtapes;
        {
            std::string sqlEtape = "SELECT ville FROM ville_etape WHERE idTrajet = ?";
            sqlite3_stmt* stmtEtape;
            if (sqlite3_prepare_v2(db, sqlEtape.c_str(), -1, &stmtEtape, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtEtape, 1, idTrajet);
                while (sqlite3_step(stmtEtape) == SQLITE_ROW) {
                    std::string ville = reinterpret_cast<const char*>(sqlite3_column_text(stmtEtape, 0));
                    villesEtapes.push_back(ville);
                }
            }
            sqlite3_finalize(stmtEtape);
        }*/
        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, {}, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);
        resultats.push_back(trajet);
    }
    sqlite3_finalize(stmt);
    return resultats;
}



std::vector<Trajet> Database::getTrajetByVilleDepartEtArriveeEtEmissionCO2(const std::string& villeDepart, const std::string& villeArrivee, const std::string& date, float emissionCO2) {
    std::vector<Trajet> resultats;
    std::string sql = R"(
        SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
               disponible, allerRetour, animaux, voiture, nombrePlaceDispo,
               etat, emissionCO2, description
        FROM trajets
        WHERE lieuDepart = ? AND lieuArrivee = ? AND date = ? AND emissionCO2 = ? AND nombrePlaceDispo > 0)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_text(stmt, 1, villeDepart.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, villeArrivee.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, date.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 4, emissionCO2);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idTrajet = sqlite3_column_int(stmt, 0);
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string heureDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string heureArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string lieuDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string lieuArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        bool disponible = sqlite3_column_int(stmt, 6);
        bool allerRetour = sqlite3_column_int(stmt, 7);
        bool animaux = sqlite3_column_int(stmt, 8);
        std::string voiture = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        int nombrePlaceDispo = sqlite3_column_int(stmt, 10);
        bool etat = sqlite3_column_int(stmt, 11);
        float emissionCO2 = static_cast<float>(sqlite3_column_double(stmt, 12));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 13));

        // SegmentsPrix
        std::vector<std::pair<std::string, float>> segmentsPrix;
        {
            std::string sqlSeg = "SELECT segment, prix FROM segment_prix WHERE idTrajet = ?";
            sqlite3_stmt* stmtSeg;
            if (sqlite3_prepare_v2(db, sqlSeg.c_str(), -1, &stmtSeg, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtSeg, 1, idTrajet);
                while (sqlite3_step(stmtSeg) == SQLITE_ROW) {
                    std::string segment = reinterpret_cast<const char*>(sqlite3_column_text(stmtSeg, 0));
                    float prix = static_cast<float>(sqlite3_column_double(stmtSeg, 1));
                    segmentsPrix.emplace_back(segment, prix);
                }
            }
            sqlite3_finalize(stmtSeg);
        }
        /* VillesEtapes
        std::vector<std::string> villesEtapes;
        {
            std::string sqlEtape = "SELECT ville FROM ville_etape WHERE idTrajet = ?";
            sqlite3_stmt* stmtEtape;
            if (sqlite3_prepare_v2(db, sqlEtape.c_str(), -1, &stmtEtape, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtEtape, 1, idTrajet);
                while (sqlite3_step(stmtEtape) == SQLITE_ROW) {
                    std::string ville = reinterpret_cast<const char*>(sqlite3_column_text(stmtEtape, 0));
                    villesEtapes.push_back(ville);
                }
            }
            sqlite3_finalize(stmtEtape);
        }*/
        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, {}, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);
        resultats.push_back(trajet);
    }
    sqlite3_finalize(stmt);
    return resultats;
}


/*bool Database::verifierPrix(int idTrajet, float prix, const std::string& villeDepart, const std::string& villeArrivee) {
    std::string sql = R"(
        SELECT sp.prix
        FROM trajets t
        LEFT JOIN ville_etape ve_dep
            ON t.idTrajet = ve_dep.idTrajet
            AND (ve_dep.ville = ? OR t.lieuDepart = ?)
        LEFT JOIN ville_etape ve_arr
            ON t.idTrajet = ve_arr.idTrajet
            AND (ve_arr.ville = ? OR t.lieuArrivee = ?)
        INNER JOIN segment_prix sp
            ON t.idTrajet = sp.idTrajet
            AND sp.segment = ve_dep.ville || '-' || ve_arr.ville
        WHERE t.idTrajet = ?
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erreur de préparation de la requête");
    }

    sqlite3_bind_text(stmt, 1, villeDepart.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, villeDepart.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, villeArrivee.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, villeArrivee.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, idTrajet);

    bool prixCorrect = false;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        float prixBase = static_cast<float>(sqlite3_column_double(stmt, 0));
        prixCorrect = (std::fabs(prix - prixBase) < 0.01); // Tolérance pour les erreurs d'arrondi
    }

    sqlite3_finalize(stmt);

    if (!prixCorrect) {
        throw std::invalid_argument("Prix incorrect ou segment invalide pour le trajet " + std::to_string(idTrajet));
    }

    return prixCorrect;
}*/

Reservation Database::getReservationByID(int ID) {
    std::string sql = R"(
        SELECT idReservation, prix, statut, idPassager, idTrajet
        FROM reservations
        WHERE idReservation = ?
    )";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_int(stmt, 1, ID);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int idReservation = sqlite3_column_int(stmt, 0);
        int idTrajet = sqlite3_column_int(stmt, 1);
        bool statut = sqlite3_column_int(stmt, 2);
        float prix = static_cast<float>(sqlite3_column_double(stmt, 3));

        int idPassager = sqlite3_column_int(stmt, 4);


        Reservation res(idTrajet, statut, prix, idPassager);
        res.setIdReservation(idReservation);
        res.setIdPassager(idPassager);
        res.setIdTrajet(idTrajet);

        sqlite3_finalize(stmt);
        return res;
    }

    sqlite3_finalize(stmt);
    throw std::runtime_error("Réservation non trouvée");
}


float Database::getEmissionCO2ByIdTrajet(int IDTrajet) {
    std::string sql = "SELECT emissionCO2 FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;
    float emissionCO2 = 0.0f;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_int(stmt, 1, IDTrajet);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        emissionCO2 = static_cast<float>(sqlite3_column_double(stmt, 0));
    } else {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Trajet non trouvé");
    }

    sqlite3_finalize(stmt);
    return emissionCO2;
}


std::vector<std::pair<std::string, float>> Database::getPrixByIdTrajet(int idTrajet) {
    std::vector<std::pair<std::string, float>> segmentsPrix;
    std::string sql = "SELECT segment, prix FROM segment_prix WHERE idTrajet = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_int(stmt, 1, idTrajet);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string segment = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        float prix = static_cast<float>(sqlite3_column_double(stmt, 1));
        segmentsPrix.emplace_back(segment, prix);
    }

    sqlite3_finalize(stmt);
    return segmentsPrix;
}


std::vector<std::string> Database::getPointIntermediaireByIdTrajet(int IDTrajet) {
    std::vector<std::string> villesEtapes;
    std::string sql = R"(
        SELECT ville
        FROM ville_etape
        WHERE idTrajet = ?
    )";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_int(stmt, 1, IDTrajet);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string ville = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        villesEtapes.push_back(ville);
    }

    sqlite3_finalize(stmt);
    return villesEtapes;
}



std::string Database::getDateDepatByIdTrajet(int IDTrajet) {
    std::string date;
    std::string sql = "SELECT date FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw std::runtime_error("Erreur préparation requête");

    sqlite3_bind_int(stmt, 1, IDTrajet);

    if (sqlite3_step(stmt) == SQLITE_ROW)
        date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    else
        throw std::runtime_error("Trajet non trouvé");
    sqlite3_finalize(stmt);
    return date;
}

std::string Database::getDateArriveeByIdTrajet(int IDTrajet) {
    std::string dateArrivee;
    std::string sql = "SELECT date FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw std::runtime_error("Erreur préparation requête");

    sqlite3_bind_int(stmt, 1, IDTrajet);

    if (sqlite3_step(stmt) == SQLITE_ROW)
        dateArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    else
        throw std::runtime_error("Trajet non trouvé");
    sqlite3_finalize(stmt);
    return dateArrivee;
}

std::string Database::getHeureArriveeByIdTrajet(int IDTrajet) {
    std::string heureArrivee;
    std::string sql = "SELECT heureArrivee FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw std::runtime_error("Erreur préparation requête");

    sqlite3_bind_int(stmt, 1, IDTrajet);

    if (sqlite3_step(stmt) == SQLITE_ROW)
        heureArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    else
        throw std::runtime_error("Trajet non trouvé");
    sqlite3_finalize(stmt);
    return heureArrivee;
}

std::string Database::getHeureDepartByIdTrajet(int IDTrajet) {
    std::string heureDepart;
    std::string sql = "SELECT heureDepart FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw std::runtime_error("Erreur préparation requête");

    sqlite3_bind_int(stmt, 1, IDTrajet);

    if (sqlite3_step(stmt) == SQLITE_ROW)
        heureDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    else
        throw std::runtime_error("Trajet non trouvé");
    sqlite3_finalize(stmt);
    return heureDepart;
}

std::string Database::getVilleArriveeByIdTrajet(int IDTrajet) {
    std::string villeArrivee;
    std::string sql = "SELECT lieuArrivee FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw std::runtime_error("Erreur préparation requête");

    sqlite3_bind_int(stmt, 1, IDTrajet);
    if (sqlite3_step(stmt) == SQLITE_ROW)
        villeArrivee = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    else
        throw std::runtime_error("Trajet non trouvé");
    sqlite3_finalize(stmt);
    return villeArrivee;
}

std::string Database::getVilleDepartByIdTrajet(int IDTrajet) {
    std::string villeDepart;
    std::string sql = R"(SELECT lieuDepart FROM trajets WHERE idTrajet = ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        throw std::runtime_error("Erreur préparation requête");
    sqlite3_bind_int(stmt, 1, IDTrajet);
    if (sqlite3_step(stmt) == SQLITE_ROW)
        villeDepart = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    else
        throw std::runtime_error("Trajet non trouvé");
    sqlite3_finalize(stmt);
    return villeDepart;
}

Utilisateur Database::getUtilisateurByID(int idUtilisateur) {
    std::string sql = R"(SELECT idUtilisateur, nom, prenom, email, mdp, adressePostale, fumeur FROM utilisateurs WHERE idUtilisateur = ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

    sqlite3_bind_int(stmt, 1, idUtilisateur);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string nom = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string prenom = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string mdp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string adresse = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        bool fumeur = sqlite3_column_int(stmt, 6);

        sqlite3_finalize(stmt);
        Utilisateur u = Utilisateur(nom, prenom, email, mdp, adresse, fumeur);
        u.setIdUtilisateur(id);
        return u;
    } else {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Utilisateur non trouvé");
    }
}


Conducteur Database::getConducteurByID(int idConducteur) {
    std::string sql = R"(SELECT 1 FROM conducteurs WHERE id = ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erreur base de données (conducteurs)");
    }
    sqlite3_bind_int(stmt, 1, idConducteur);

    if (sqlite3_step(stmt) != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("L'utilisateur n'est pas un conducteur");
    }
    sqlite3_finalize(stmt);

    Utilisateur user = getUtilisateurByID(idConducteur);

    std::vector<Trajet> listeTrajet;
    {
        std::string sqlTrajets = R"(SELECT idTrajet FROM trajets WHERE idConducteur = ?)";
        sqlite3_stmt* stmtTrajet;
        if (sqlite3_prepare_v2(db, sqlTrajets.c_str(), -1, &stmtTrajet, nullptr) == SQLITE_OK) {
            sqlite3_bind_int(stmtTrajet, 1, idConducteur);
            while (sqlite3_step(stmtTrajet) == SQLITE_ROW) {
                int idTrajet = sqlite3_column_int(stmtTrajet, 0);
                listeTrajet.push_back(getTrajetByIdTrajet(idTrajet));
            }
        }
        sqlite3_finalize(stmtTrajet);
    }

    return Conducteur(
            user.getNom(),
            user.getPrenom(),
            user.getEmail(),
            user.getMotPasse(),
            user.getAdressePostale(),
            user.getFumeur(),
            listeTrajet
    );
}

    Passager Database::getPassagerByID(int idPassager){
        std::string sql = R"(SELECT 1 FROM passagers WHERE id = ?)";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erreur base de données (conducteurs)");
        }
        sqlite3_bind_int(stmt, 1, idPassager);

        if (sqlite3_step(stmt) != SQLITE_ROW) {
            sqlite3_finalize(stmt);
            throw std::runtime_error("L'utilisateur n'est pas un passager");
        }
        sqlite3_finalize(stmt);

        Utilisateur user = getUtilisateurByID(idPassager);

        std::vector<Reservation> listeReservation;
        {
            std::string sqlReservations = R"(SELECT idReservation FROM reservations WHERE idPassager = ?)";
            sqlite3_stmt* stmtReservation;
            if (sqlite3_prepare_v2(db, sqlReservations.c_str(), -1, &stmtReservation, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtReservation, 1, idPassager);
                while (sqlite3_step(stmtReservation) == SQLITE_ROW) {
                    int idReservation = sqlite3_column_int(stmtReservation, 0);
                    listeReservation.push_back(getReservationByID(idReservation));
                }
            }
            sqlite3_finalize(stmtReservation);
        }

        return Passager(
                user.getNom(),
                user.getPrenom(),
                user.getEmail(),
                user.getMotPasse(),
                user.getAdressePostale(),
                user.getFumeur(),
                listeReservation
        );
    }


void Database::supprimerTrajetByIDTrajet(int idTrajet) {
    std::string sql = "DELETE FROM trajets WHERE idTrajet = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête DELETE trajet : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_int(stmt, 1, idTrajet);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur lors de la suppression du trajet : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Suppression trajet échouée");
    }
    sqlite3_finalize(stmt);
}

/*void Database::supprimerReservationByIDReservation(int idReservation) {
    std::string sql = "DELETE FROM reservations WHERE idReservation = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête DELETE réservation : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_int(stmt, 1, idReservation);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur lors de la suppression de la réservation : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        throw std::runtime_error("Suppression réservation échouée");
    }
    sqlite3_finalize(stmt);
}*/

void Database::supprimerReservationByIDReservation(int idReservation) {
    int idTrajet = -1;
    sqlite3_stmt* stmtSelect;
    std::string sqlSelect = "SELECT idTrajet FROM reservations WHERE idReservation = ?;";
    if (sqlite3_prepare_v2(db, sqlSelect.c_str(), -1, &stmtSelect, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation SELECT trajet : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_int(stmtSelect, 1, idReservation);
    if (sqlite3_step(stmtSelect) != SQLITE_ROW) {
        std::cerr << "Réservation non trouvée : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmtSelect);
        throw std::runtime_error("Réservation non trouvée");
    }
    idTrajet = sqlite3_column_int(stmtSelect, 0);
    sqlite3_finalize(stmtSelect);

    // Supprimer la réservation
    sqlite3_stmt* stmtDelete;
    std::string sqlDelete = "DELETE FROM reservations WHERE idReservation = ?;";
    if (sqlite3_prepare_v2(db, sqlDelete.c_str(), -1, &stmtDelete, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation DELETE réservation : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_int(stmtDelete, 1, idReservation);
    if (sqlite3_step(stmtDelete) != SQLITE_DONE) {
        std::cerr << "Erreur suppression réservation : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmtDelete);
        throw std::runtime_error("Suppression réservation échouée");
    }
    sqlite3_finalize(stmtDelete);

    // Incrémenter le nombre de places disponibles du trajet
    int nbPlaceDispo = 0;
    int etat = 1;

    sqlite3_stmt* stmtUpdateSelect;
    std::string sqlUpdateSelect = "SELECT nombrePlaceDispo, etat FROM trajets WHERE idTrajet = ?;";
    if (sqlite3_prepare_v2(db, sqlUpdateSelect.c_str(), -1, &stmtUpdateSelect, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation SELECT places : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_int(stmtUpdateSelect, 1, idTrajet);
    if (sqlite3_step(stmtUpdateSelect) == SQLITE_ROW) {
        nbPlaceDispo = sqlite3_column_int(stmtUpdateSelect, 0);
        etat = sqlite3_column_int(stmtUpdateSelect, 1);
    } else {
        std::cerr << "Trajet non trouvé : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmtUpdateSelect);
        throw std::runtime_error("Trajet non trouvé");
    }
    sqlite3_finalize(stmtUpdateSelect);

    // Incrémenter le nombre de places disponibles
    nbPlaceDispo++;

    // Si le nombre de places passe de 0 à 1, mettre l’état à "vrai"
    if (nbPlaceDispo == 1 && etat == 0) {
        etat = 1;
    }

    // Mettre à jour le trajet
    sqlite3_stmt* stmtUpdate;
    std::string sqlUpdate = "UPDATE trajets SET nombrePlaceDispo = ?, etat = ? WHERE idTrajet = ?;";
    if (sqlite3_prepare_v2(db, sqlUpdate.c_str(), -1, &stmtUpdate, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation UPDATE trajet : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_bind_int(stmtUpdate, 1, nbPlaceDispo);
    sqlite3_bind_int(stmtUpdate, 2, etat);
    sqlite3_bind_int(stmtUpdate, 3, idTrajet);
    if (sqlite3_step(stmtUpdate) != SQLITE_DONE) {
        std::cerr << "Erreur mise à jour trajet : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmtUpdate);
        throw std::runtime_error("Erreur base de données");
    }
    sqlite3_finalize(stmtUpdate);

    //std::cout << "Trajet " << idTrajet << " : nombrePlaceDispo = " << nbPlaceDispo << ", etat = " << etat << std::endl;
}

std::vector<std::pair<Reservation, Trajet>> Database::getReservationEtTrajetByIdPassager(int idPassager) {

    std::vector<std::pair<Reservation, Trajet>> resultat;

    std::string updateReservation = R"(
        UPDATE reservations
        SET statut = 0
        WHERE idReservation IN (
            SELECT r.idReservation
            FROM reservations r
            JOIN trajets t ON r.idTrajet = t.idTrajet
            WHERE r.idPassager = ?
              AND (t.date < date('now') OR (t.date = date('now') AND t.heureDepart < time('now')))
        ))";

    std::string updateTrajet = R"(
        UPDATE trajets
        SET disponible = 0
        WHERE idTrajet IN (
            SELECT t.idTrajet
            FROM reservations r
            JOIN trajets t ON r.idTrajet = t.idTrajet
            WHERE r.idPassager = ?
              AND (t.date < date('now') OR (t.date = date('now') AND t.heureDepart < time('now')))
        ))";

    // Exécution des mises à jour
    sqlite3_stmt* stmtupd;
    if (sqlite3_prepare_v2(db, updateReservation.c_str(), -1, &stmtupd, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmtupd, 1, idPassager);
        sqlite3_step(stmtupd);
        sqlite3_finalize(stmtupd);
    }
    if (sqlite3_prepare_v2(db, updateTrajet.c_str(), -1, &stmtupd, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmtupd, 1, idPassager);
        sqlite3_step(stmtupd);
        sqlite3_finalize(stmtupd);
    }

    //Recuperation des reservations et trajets
    std::string sql = R"(
        SELECT r.idReservation, r.idTrajet, r.statut, r.prix, r.idPassager,
               t.idTrajet, t.idConducteur, t.date, t.heureDepart, t.heureArrivee,
               t.lieuDepart, t.lieuArrivee, t.disponible, t.allerRetour, t.animaux,
               t.voiture, t.nombrePlaceDispo, t.etat, t.emissionCO2, t.description
        FROM reservations r
        JOIN trajets t ON r.idTrajet = t.idTrajet
        WHERE r.idPassager = ?;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        return resultat;
    }

    sqlite3_bind_int(stmt, 1, idPassager);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idReservation = sqlite3_column_int(stmt, 0);
        int idTrajet = sqlite3_column_int(stmt, 1);
        bool statut = sqlite3_column_int(stmt, 2) != 0;
        float prix = static_cast<float>(sqlite3_column_double(stmt, 3));
        int idPassagerRes = sqlite3_column_int(stmt, 4);

        Reservation reservation(idTrajet, statut, prix, idPassagerRes);
        reservation.setIdReservation(idReservation);

        int idTrajetT = sqlite3_column_int(stmt, 5);
        int idConducteur = sqlite3_column_int(stmt, 6);
        const char* datePtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        std::string date = datePtr ? datePtr : "";
        const char* heureDepartPtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        std::string heureDepart = heureDepartPtr ? heureDepartPtr : "";
        const char* heureArriveePtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        std::string heureArrivee = heureArriveePtr ? heureArriveePtr : "";
        const char* lieuDepartPtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
        std::string lieuDepart = lieuDepartPtr ? lieuDepartPtr : "";
        const char* lieuArriveePtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
        std::string lieuArrivee = lieuArriveePtr ? lieuArriveePtr : "";
        bool disponible = sqlite3_column_int(stmt, 12) != 0;
        bool allerRetour = sqlite3_column_int(stmt, 13) != 0;
        bool animaux = sqlite3_column_int(stmt, 14) != 0;
        const char* voiturePtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 15));
        std::string voiture = voiturePtr ? voiturePtr : "";
        int nombrePlaceDispo = sqlite3_column_int(stmt, 16);
        bool etat = sqlite3_column_int(stmt, 17) != 0;
        double emissionCO2 = sqlite3_column_double(stmt, 18);
        const char* descriptionPtr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 19));
        std::string description = descriptionPtr ? descriptionPtr : "";

        std::vector<std::pair<std::string, float>> segmentsPrix = getPrixByIdTrajet(idTrajetT);

        Trajet trajet(date,heureDepart,heureArrivee,lieuDepart,lieuArrivee,segmentsPrix,{},disponible,allerRetour,animaux,voiture,nombrePlaceDispo,etat,emissionCO2,description);
        trajet.setIdTrajet(idTrajet);

        resultat.push_back({reservation, trajet});
    }

    sqlite3_finalize(stmt);
    return resultat;
}



bool Database::ajouterConducteur(int idUtilisateur) {
    std::string sql = "INSERT INTO conducteurs (id) VALUES (?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation ajout conducteur : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idUtilisateur);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur insertion conducteur : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool Database::ajouterPassager(int idUtilisateur) {
    std::string sql = "INSERT INTO passagers (id) VALUES (?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation ajout passager : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idUtilisateur);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erreur insertion passager : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}













