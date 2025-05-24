#include <iostream>
#include <stdexcept>
#include <utility>
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
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            FOREIGN KEY(id) REFERENCES utilisateurs(idUtilisateur) ON DELETE CASCADE
        );
    )";

    std::string createPassagerTable = R"(
        CREATE TABLE IF NOT EXISTS passagers (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
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
        std::string sql = "INSERT INTO utilisateurs (nom, prenom, email, mdp, adressePostale) VALUES (?, ?, ?, ?, ?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        sqlite3_bind_text(stmt, 1, u.getNom().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, u.getPrenom().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, u.getEmail().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, u.getMotPasse().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, u.getAdressePostale().c_str(), -1, SQLITE_TRANSIENT);

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
        SELECT idUtilisateur, nom, prenom, email, mdp, adressePostale
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
        bool fumeur = sqlite3_column_int(stmt, 6);

        Utilisateur user(
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)),
                fumeur
        );
        user.setIdUtilisateur(idUtilisateur);
        sqlite3_finalize(stmt);
        return user;
    }

    sqlite3_finalize(stmt);
    throw std::runtime_error("Utilisateur non trouvé");
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
        std::string sql = "INSERT INTO reservations ( idTrajet, statut, prix, idPassager) VALUES (?, ?, ?, ?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur préparation ajout réservation : " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        sqlite3_bind_double(stmt, 1, r.getIdTrajet());
        sqlite3_bind_int(stmt, 2, r.getStatut() ? 1 : 0);
        sqlite3_bind_int(stmt, 3, r.getPrix());
        sqlite3_bind_int(stmt, 4, r.getIdPassager());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Erreur insertion réservation : " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            return false;
        }

        sqlite3_finalize(stmt);
        return true;

    }

Trajet Database::getTrajetByIdTrajet(int idTrajet) {
    std::string sql = R"(
        SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, disponible, allerRetour, animaux, voiture, nombrePlaceDispo, etat, emissionCO2, description
        FROM trajets WHERE idTrajet = ?)";

    sqlite3_stmt* stmt;

    sqlite3_bind_int(stmt, 1, idTrajet);

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur préparation requête : " << sqlite3_errmsg(db) << std::endl;
        throw std::runtime_error("Erreur base de données");
    }

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

        // Récupérer les villesEtapes associées à ce trajet
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
        }

        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);

        sqlite3_finalize(stmt);
        return trajet;
    }

    sqlite3_finalize(stmt);
    throw std::runtime_error("Trajet non trouvé");
}


std::vector<Trajet> Database::getTrajetByVilleDepartEtArriveeEtDateDepart(std::string villeDepart, std::string villeArrivee, std::string date) {
    std::vector<Trajet> resultats;
    std::string sql = R"(
        SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, disponible, allerRetour, animaux, voiture, nombrePlaceDispo, etat, emissionCO2, description
        FROM trajets WHERE lieuDepart = ? AND lieuArrivee = ? AND date = ?)";

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
        // VillesEtapes
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
        }
        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);
        resultats.push_back(trajet);
    }
    sqlite3_finalize(stmt);
    return resultats;
}


std::vector<Trajet> Database::getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(
        std::string villeDepart, std::string villeArrivee, std::string date, int prix)
{
    std::vector<Trajet> resultats;
    // les prix sont stockes dans segment_prix donc on a besoin de faire une jointure pour recuperer les prix
    std::string sql =
            "SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, "
            "disponible, allerRetour, animaux, voiture, nombrePlaceDispo, "
            "etat, emissionCO2, description "
            "FROM trajets "
            "JOIN segment_prix ON trajets.idTrajet = segment_prix.idTrajet "
            "WHERE lieuDepart = ? AND lieuArrivee = ? AND date = ? AND segment_prix.prix = ?";
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
        // VillesEtapes
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
        }
        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);
        resultats.push_back(trajet);
    }
    sqlite3_finalize(stmt);
    return resultats;
}



std::vector<Trajet> Database::getTrajetByVilleDepartEtArriveeEtEmissionCO2(std::string villeDepart, std::string villeArrivee, std::string date, float emissionCO2) {
    std::vector<Trajet> resultats;
    std::string sql = R"(
        SELECT idTrajet, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, disponible, allerRetour, animaux, voiture, nombrePlaceDispo, etat, emissionCO2, description
        FROM trajets WHERE lieuDepart = ? AND lieuArrivee = ? AND date = ? AND emissionCO2 = ?)";
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
        // VillesEtapes
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
        }
        Trajet trajet(
                date, heureDepart, heureArrivee, lieuDepart, lieuArrivee,
                segmentsPrix, villesEtapes, disponible, allerRetour, animaux,
                voiture, nombrePlaceDispo, etat, emissionCO2, description
        );
        trajet.setIdTrajet(idTrajet);
        resultats.push_back(trajet);
    }
    sqlite3_finalize(stmt);
    return resultats;
}



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
    std::string sql = R"(SELECT id, nom, prenom, email, mdp, adressePostale, fumeur FROM utilisateurs WHERE id = ?)";
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
        return Utilisateur(nom, prenom, email, mdp, adresse, fumeur);
    } else {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Utilisateur non trouvé");
    }
}


Conducteur Database::getConducteurByID(int idUtilisateur) {
    std::string sql = R"(SELECT 1 FROM conducteurs WHERE id = ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erreur base de données (conducteurs)");
    }
    sqlite3_bind_int(stmt, 1, idUtilisateur);

    if (sqlite3_step(stmt) != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("L'utilisateur n'est pas un conducteur");
    }
    sqlite3_finalize(stmt);

    Utilisateur user = getUtilisateurByID(idUtilisateur);

    std::vector<Trajet> listeTrajet;
    {
        std::string sqlTrajets = R"(SELECT idTrajet FROM trajets WHERE idConducteur = ?)";
        sqlite3_stmt* stmtTrajet;
        if (sqlite3_prepare_v2(db, sqlTrajets.c_str(), -1, &stmtTrajet, nullptr) == SQLITE_OK) {
            sqlite3_bind_int(stmtTrajet, 1, idUtilisateur);
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

    Passager Database::getPassagerByID(int idUtilisateur){
        std::string sql = R"(SELECT 1 FROM passagers WHERE id = ?)";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erreur base de données (conducteurs)");
        }
        sqlite3_bind_int(stmt, 1, idUtilisateur);

        if (sqlite3_step(stmt) != SQLITE_ROW) {
            sqlite3_finalize(stmt);
            throw std::runtime_error("L'utilisateur n'est pas un passager");
        }
        sqlite3_finalize(stmt);

        Utilisateur user = getUtilisateurByID(idUtilisateur);

        std::vector<Reservation> listeReservation;
        {
            std::string sqlReservations = R"(SELECT idReservation FROM reservations WHERE idPassager = ?)";
            sqlite3_stmt* stmtReservation;
            if (sqlite3_prepare_v2(db, sqlReservations.c_str(), -1, &stmtReservation, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmtReservation, 1, idUtilisateur);
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

void Database::supprimerReservationByIDReservation(int idReservation) {
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
}


