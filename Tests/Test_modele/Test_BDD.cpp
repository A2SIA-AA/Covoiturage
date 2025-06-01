#include <iostream>
#include <cstdio>
#include "Modele_hpp/BaseDonnees.hpp"

using namespace std;

void test_execute(Database& db) {
    bool success = db.execute("SELECT 1;");
    cout << "test_execute: " << (success ? "OK" : "FAIL") << endl;
}

void setupDatabase(Database& db) {
    bool ajout1;
    bool ajout2;
    bool ajout3;
    bool ajout4;
    bool ajout5;

    ajout1 = db.ajouterUtilisateur(Utilisateur( 1,"Dupont", "Jean","user1@example.com", "mdp1", "Rouen", true));
    ajout2 = db.ajouterUtilisateur(Utilisateur( 2,"Durand", "Alice","user2@example.com", "mdp2", "Rouen", false));

    ajout3 = db.ajouterTrajet(Trajet (1,"2025-04-20", "08:00","12:00","Paris","Lyon",{{"Paris-Lyon", 50.0}},{},true,false, true,"Peugeot 208",3,true,85.3f,"Trajet confortable avec clim et musique chill" ), 1);
    ajout4 = db.ajouterReservation(Reservation(15, 1, true));
    ajout5 = db.ajouterPointIntermediaire(1, "Dijon");
}

void test_getUtilisateurByEmailAndMDP(Database& db) {
    Utilisateur u = db.getUtilisateurByEmailAndMDP("user1@example.com", "mdp1");
    cout << "test_getUtilisateurByEmailAndMDP: " << (u.getNom() == "Dupont" ? "OK" : "FAIL") << endl;
}

void test_modifierUtilisateur(Database& db) {
    // 1. Création d'un objet utilisateur modifié, avec même id que celui créé dans setupDatabase()
    Utilisateur u_modifie(1, "Dupont", "Jean-Marie", "user1@example.com", "mdp1", "Caen", true);

    // 2. Appel de la fonction modifierUtilisateur
    bool success = db.modifierUtilisateur(u_modifie);

    // 3. Récupération de l'utilisateur modifié avec la fonction existante getUtilisateurByEmailAndMDP
    Utilisateur u_recupere = db.getUtilisateurByID(1);

    // 4. Vérification du résultat et affichage
    cout << "test_modifierUtilisateur: "
         << ((success && u_recupere.getPrenom() == "Jean-Marie" && u_recupere.getVille() == "Caen") ? "OK" : "FAIL")
         << endl;
}




void test_getTrajetByVilleDepartEtArriveeEtDateDepart(Database& db) {
    auto t = db.getTrajetByVilleDepartEtArriveeEtDateDepart("Paris", "Lyon", "2025-04-20");
    cout << "test_getTrajetByVilleDepartEtArriveeEtDateDepart: " << (t.getIdTrajet() ==  1 ? "OK" : "FAIL") << endl;
}

void test_getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(Database& db) {
    auto t = db.getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix("Paris", "Lyon", "2025-04-20", 50);
    cout << "test_getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix: " << (t.getIdTrajet() ==  1 ? "OK" : "FAIL") << endl;
}

void test_getTrajetByVilleDepartEtArriveeEtEmissionCO2(Database& db) {
    auto t = db.getTrajetByVilleDepartEtArriveeEtEmissionCO2("Paris", "Lyon", "2025-04-20" , 85.3f);
    cout << "getTrajetByVilleDepartEtArriveeEtEmissionCO2: " << (t.getIdTrajet() ==  1 ? "OK" : "FAIL") << endl;
}


void test_getReservationByID(Database& db) {
    auto r = db.getReservationByID(1);
    cout << "test_getReservationByID: " << (r.getIdReservation() == 1 ? "OK" : "FAIL") << endl;
}


void test_getTrajetByIdTrajet(Database& db) {
    auto r = db.getTrajetByIdTrajet(1);
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
    cout << "test_getPointIntermediaireByIdTrajet: " << (points.empty() ? "OK" : "FAIL") << endl;
}

void test_getDateDepatByIdTrajet(Database& db) {
    cout << "test_getDateDepatByIdTrajet: " << (db.getDateDepatByIdTrajet(1) == "2025-04-20" ? "OK" : "FAIL") << endl;
}

void test_getDateArriveeByIdTrajet(Database& db) {
    cout << "test_getDateArriveeByIdTrajet: " << (db.getDateArriveeByIdTrajet(1) == "2025-04-20" ? "OK" : "FAIL") << endl;
}

void test_getHeureDepartByIdTrajet(Database& db) {
    cout << "test_getHeureDepartByIdTrajet: " << (db.getHeureDepartByIdTrajet(1) == "08:00" ? "OK" : "FAIL") << endl;
}

void test_getHeureArriveeByIdTrajet(Database& db) {
    cout << "test_getHeureArriveeByIdTrajet: " << (db.getHeureArriveeByIdTrajet(1) == "12:00" ? "OK" : "FAIL") << endl;
}


void test_getVilleDepartByIdTrajet(Database& db) {
    cout << "test_getVilleDepartByIdTrajet: " << (db.getVilleDepartByIdTrajet(1) == "Paris" ? "OK" : "FAIL") << endl;
}

void test_getVilleArriveeByIdTrajet(Database& db) {
    cout << "test_getVilleArriveeByIdTrajet: " << (db.getVilleArriveeByIdTrajet(1) == "Lyon" ? "OK" : "FAIL") << endl;
}

void test_getConducteurByID(Database& db) {
    cout << "test_getConducteurByID: " << (db.getConducteurByID(1).getNom() == "Dupont" ? "OK" : "FAIL") << endl;
}

void test_getPassagerByID(Database& db) {
    cout << "test_getPassagerByID: " << (db.getPassagerByID(2).getNom() == "Durand" ? "OK" : "FAIL") << endl;
}

void test_supprimerTrajetByIDTrajet(Database& db) {
    db.supprimerTrajetByIDTrajet(1); // Supposons qu'on supprime le trajet avec ID 3
    Trajet t = db.getTrajetByIdTrajet(1);
    cout << "test_supprimerTrajetByIDTraget: "
         << ( t.getIdTrajet() == -1 ? "OK" : "FAIL") << endl;
}



void test_supprimerReservationByIdReservation(Database& db){
    db.supprimerReservationByIdReservation(1);
    Reservation r = db.getReservationByID(1);
    cout << "test_supprimerTrajetByIDTraget: "
         << (r.getIdReservation() == -1  ? "OK" : "FAIL") << endl;
}

void test_getUtilisateurByID(Database& db) {
    Utilisateur u = db.getUtilisateurByID(1);
    cout << "test_getUtilisateurByID: "
         << (u.getNom() == "Dupont" && u.getPrenom() == "Jean" ? "OK" : "FAIL")
         << endl;
}

int main() {
    const std::string test_db_filename = "test_temp.db";

    Database db(test_db_filename);
    setupDatabase(db);

    // Lancement des tests
    test_execute(db);
    test_getUtilisateurByEmailAndMDP(db);
    test_getTrajetByVilleDepartEtArriveeEtDateDepart(db);
    test_getTrajetByVilleDepartEtArriveeEtDateDepartEtPrix(db);
    test_getTrajetByVilleDepartEtArriveeEtEmissionCO2(db);
    test_getTrajetByIdTrajet(db);
    test_getReservationByID(db);
    test_getEmissionCO2ByIdTrajet(db);
    test_getPrixByIdTrajet(db);
    test_getPointIntermediaireByIdTrajet(db);
    test_getDateDepatByIdTrajet(db);
    test_getDateArriveeByIdTrajet(db);
    test_getHeureDepartByIdTrajet(db);
    test_getHeureArriveeByIdTrajet(db);
    test_getVilleDepartByIdTrajet(db);
    test_getVilleArriveeByIdTrajet(db);
    test_getConducteurByID(db);
    test_getPassagerByID(db);
    test_supprimerReservationByIdReservation(db);
    test_supprimerTrajetByIDTrajet(db);
    test_getUtilisateurByID(db);

    // Suppression du fichier de base de test
    if (remove(test_db_filename.c_str()) != 0) {
        cerr << "Erreur lors de la suppression du fichier test_temp.db" << endl;
    } else {
        cout << "Base de test supprime avec succes." << endl;
    }

    return 0;
}
