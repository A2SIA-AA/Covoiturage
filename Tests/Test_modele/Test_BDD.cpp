#include <iostream>
#include <cstdio>
#include "Modele_hpp/BaseDonnees.hpp"

using namespace std;

void test_execute(Database& db) {
    bool success = db.execute("SELECT 1;");
    cout << "test_execute: " << (success ? "OK" : "FAIL") << endl;
}

void setupDatabase(Database& db) {
    db.ajouterUtilisateur(Utilisateur( 1,"Dupont", "Jean","user1@example.com", "mdp1", "Rouen", true));
    db.ajouterUtilisateur(Utilisateur( 2,"Durand", "Alice","user2@example.com", "mdp2", "Rouen", false));

    db.ajouterTrajet(    Trajet (1,"2025-04-20", "08:00","12:00","Paris","Lyon",{{"Paris-Dijon", 20.0}, {"Dijon-Lyon", 15.0}},{"Dijon"},true,false, true,"Peugeot 208",3,true,85.3f,"Trajet confortable avec clim et musique chill" ));
    db.ajouterReservation(Reservation(15, 1, true));
    db.ajouterPointIntermediaire(1, "Dijon");
}

void test_getUtilisateurByEmailAndMDP(Database& db) {
    Utilisateur u = db.getUtilisateurByEmailAndMDP("user1@example.com", "mdp1");
    cout << "test_getUtilisateurByEmailAndMDP: " << (u.getNom() == "Dupont" ? "OK" : "FAIL") << endl;
}

void test_getTrajetByVilleDate(Database& db) {
    auto t = db.getTrajetByVilleDepartEtArriveeEtDateDepart("Paris", "Lyon", "2025-04-20");
    cout << "test_getTrajetByVilleDate: " << (!t.getLieuDepart().empty() ? "OK" : "FAIL") << endl;
}

void test_getTrajetByVilleDatePrix(Database& db) {
    auto t = db.getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix("Paris", "Lyon", "2023-04-10", 50);
    if (t.getLieuDepart() != "") {
        cout << "test_getTrajetByVilleDatePrix: OK" << endl;
    } else {
        cout << "test_getTrajetByVilleDatePrix: FAIL" << endl;
    }
}

void test_getTrajetByVilleEmission(Database& db) {
    auto t = db.getTrajetByVilleDepartEtArriveeEtEmissionCO2("Paris", "Lyon", "2025-04-20" , 85.3f);
    cout << "test_getTrajetByVilleEmission: " << (!t.getLieuDepart().empty() ? "OK" : "FAIL") << endl;
}


void test_getReservationByID(Database& db) {
    auto r = db.getReservationByID(1);
    cout << "test_getReservationByID: " << (r.getIdTrajet() == 1 ? "OK" : "FAIL") << endl;
}

void test_getEmissionCO2ByIdTrajet(Database& db) {
    cout << "test_getEmissionCO2ByIdTrajet: " << (db.getEmissionCO2ByIdTrajet(1) == 85.3f ? "OK" : "FAIL") << endl;
}


void test_getPrixByIdTrajet(Database& db) {
    auto prix = db.getPrixByIdTrajet(1);
    float total = 0;
    for (auto &p: prix) total += p.second;
    cout << "test_getPrixByIdTrajet: " << (total == 35.0f ? "OK" : "FAIL") << endl;
}

void test_getPointIntermediaireByIdTrajet(Database& db) {
    auto points = db.getPointIntermediaireByIdTrajet(1);
    cout << "test_getPointIntermediaireByIdTrajet: " << (!points.empty() && points[0] == "Dijon" ? "OK" : "FAIL") << endl;
}

void test_dates_heures(Database& db) {
    cout << "test_getDateDepatByIdTrajet: " << (db.getDateDepatByIdTrajet(1) == "2023-04-10" ? "OK" : "FAIL") << endl;
    cout << "test_getDateArriveeByIdTrajet: " << (db.getDateArriveeByIdTrajet(1) == "2023-04-10" ? "OK" : "FAIL") << endl;
    cout << "test_getHeureDepartByIdTrajet: " << (db.getHeureDepartByIdTrajet(1) == "08:00" ? "OK" : "FAIL") << endl;
    cout << "test_getHeureArriveeByIdTrajet: " << (db.getHeureArriveeByIdTrajet(1) == "12:00" ? "OK" : "FAIL") << endl;
}

void test_villes(Database& db) {
    cout << "test_getVilleDepartByIdTrajet: " << (db.getVilleDepartByIdTrajet(1) == "Paris" ? "OK" : "FAIL") << endl;
    cout << "test_getVilleArriveeByIdTrajet: " << (db.getVilleArriveeByIdTrajet(1) == "Lyon" ? "OK" : "FAIL") << endl;
}

void test_getConducteurPassagerByID(Database& db) {
    cout << "test_getConducteurByID: " << (db.getConducteurByID(1).getNom() == "Dupont" ? "OK" : "FAIL") << endl;
    cout << "test_getPassagerByID: " << (db.getPassagerByID(2).getNom() == "Durand" ? "OK" : "FAIL") << endl;
}


int main() {
    const std::string test_db_filename = "test_temp.db";

    Database db(test_db_filename);
    setupDatabase(db);

    // Lancement des tests
    test_getUtilisateurByEmailAndMDP(db);
    test_getTrajetByVilleDate(db);
    test_getTrajetByVilleDatePrix(db);
    test_getTrajetByVilleEmission(db);
    test_getReservationByID(db);
    test_getEmissionCO2ByIdTrajet(db);
    test_getPrixByIdTrajet(db);
    test_getPointIntermediaireByIdTrajet(db);
    test_dates_heures(db);
    test_villes(db);
    test_getConducteurPassagerByID(db);

    // Suppression du fichier de base de test
    if (remove(test_db_filename.c_str()) != 0) {
        cerr << "Erreur lors de la suppression du fichier test_temp.db" << endl;
    } else {
        cout << "Base de test supprime avec succes." << endl;
    }

    return 0;
}
