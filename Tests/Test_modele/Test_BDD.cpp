#include "../../Modele/Modele_hpp/BaseDonnees.hpp"
#include <iostream>
#include <string>

void Test_ajouterUtilisateur(){
        std::string fichierBDD = "test_database_utilisateur.sqlite";
        Database db(fichierBDD);
        // Récupération de l'utilisateur ajouté
        Utilisateur utilisateur = db.getUtilisateurByEmailAndMDP("jane.doe@email.com", "motdepasse");

        // Vérifications simples
        std::cout << "Test Nom : " << (utilisateur.getNom() == "Doe" ? "Réussi" : "Échoué") << std::endl;
        std::cout << "Test Prénom : " << (utilisateur.getPrenom() == "Jane" ? "Réussi" : "Échoué") << std::endl;
        std::cout << "Test Email : " << (utilisateur.getEmail() == "jane.doe@email.com" ? "Réussi" : "Échoué") << std::endl;
        std::cout << "Test Adresse : " << (utilisateur.getAdressePostale() == "10 rue de Paris" ? "Réussi" : "Échoué") << std::endl;
        std::cout << "Test Fumeur : " << (utilisateur.getFumeur() == true ? "Réussi" : "Échoué") << std::endl;

};

void Test_ajoutTrajet(){
    std::string fichierBDD = "test_database_trajet.sqlite";
    Database db(fichierBDD);
    Trajet trajet = db.getTrajetByVilleDepartEtArriveeEtDateDepart("Paris", "Lyon","2025-04-15");

    std::cout << "Test id Trajet : " << (trajet.getIdTrajet() == 1 ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test date" <<(trajet.getDate() == "2025-04-15" ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test Heure depart" << (trajet.getHeureDepart() == "16h00" ? "Reussi"  :" Echoue")<<std::endl;
    std::cout << "Test Heure arrivee" << (trajet.getHeureArrive() == "19h00" ? "Reussi"  :" Echoue")<<std::endl;
    std::cout << "Test Lieu depart" << (trajet.getLieuDepart() == "Paris" ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test Lieu arrivee" << (trajet.getLieuArrive() == "Lyon" ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test etat : " << (trajet.getEtat() == true ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test animaux : " << (trajet.getAnimaux() == true ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test aller retour : " << (trajet.getAllerRetour() == true ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test voiture : " << (trajet.getVoiture() == "Mercedes" ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test nb place dispo : " << (trajet.getNombrePlaceDispo() == 2 ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test emission CO2 : " << (trajet.getEmissionCO2() == 57.8 ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test description : " << (trajet.getDescription() == "Voyage aller retour avec clim" ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test dispo : " << (trajet.getDisponible() == true ? "Reussi"  :" Echoue") << std::endl;

    for (auto segment : trajet.getSegmentsPrix()) {
        std::cout << segment.first << " : " << segment.second << "€" << std::endl;
    }

    for (auto ville : trajet.getVillesEtapes()) {
        std::cout << "Étape : " << ville << std::endl;
    }

}

void Test_ajouterReservation(){
    std::string fichierBDD = "test_database_reservation.sqlite";
    Database db(fichierBDD);
    Reservation reservation = db.getReservationByID(2);

    std::cout << "Test id reservation : " << (reservation.getIdReservation() == 2 ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test prix" <<(reservation.getPrix() == 15 ? "Reussi"  :" Echoue") << std::endl;
    std::cout << "Test statut  : " << (reservation.getStatut() == true ? "Reussi"  :" Echoue") << std::endl;


}
int main() {
    // Lancer le test;
    Test_ajouterUtilisateur();

    Test_ajoutTrajet();

    Test_ajouterReservation();

    return 0;
}
