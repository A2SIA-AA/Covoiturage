#include <iostream>
#include <regex>
#include <vector>
#include <utility>
#include "../Controlleur_hpp/TrajetControlleur.hpp"

bool TrajetControlleur::verifierSaisieTrajet(
    int idTrajet,
    std::string date,
    std::string heureDepart,
    std::string heureArrivee,
    std::string lieuDepart,
    std::string lieuArrivee,
    std::vector<std::pair<std::string, float>> segmentsPrix,
    std::vector<std::string> villesEtapes,
    bool disponible,
    bool allerRetour,
    bool animaux,
    std::string voiture,
    int nombrePlaceDispo,
    bool etat,
    float emissionCO2,
    std::string description
) {
    // On vérifie le format de la date
    std::regex regexDate(R"(^\d{4}-\d{2}-\d{2}$)");
    if (!std::regex_match(date, regexDate)) {
       // std::cerr << "Erreur : le format de la date est invalide (attendu : YYYY-MM-DD).\n";
        return false;
    }

    //  On vérifie le format des heures
    std::regex regexHeure(R"(^\d{2}:\d{2}$)");
    if (!std::regex_match(heureDepart, regexHeure) || !std::regex_match(heureArrivee, regexHeure)) {
        //std::cerr << "Erreur : le format des heures est invalide (attendu : HH:MM).\n";
        return false;
    }

    //  On vérifie que les lieux ne sont pas vides
    if (lieuDepart.empty() || lieuArrivee.empty()) {
       // std::cerr << "Erreur : les lieux de départ et d’arrivée ne doivent pas être vides.\n";
        return false;
    }

    //  On vérifie que les segments de prix ont des valeurs positives
    for (const auto& segment : segmentsPrix) {
        if (segment.second < 0) {
            //std::cerr << "Erreur : un segment a un prix négatif.\n";
            return false;
        }
    }

    // On vérifie que le nombre de places est positif
    if (nombrePlaceDispo <= 0) {
        //std::cerr << "Erreur : le nombre de places disponibles doit être supérieur à 0.\n";
        return false;
    }

    // On vérifie que la voiture n'est pas vide
    if (voiture.empty()) {
        //std::cerr << "Erreur : le champ voiture ne doit pas être vide.\n";
        return false;
    }

    //  On vérifie que les émissions de CO2 sont cohérentes
    if (emissionCO2 < 0) {
        std::cerr << "Erreur : les émissions de CO2 ne peuvent pas être négatives.\n";
        return false;
    }

    // et si tout est bon
    return true;
}


void TrajetControlleur::reservation(int idTrajet, float prix, int idPassager, bool statut){
    Reservation nouvelleReservation(idTrajet, statut, prix, idPassager);
    baseDeDonnees.ajouterReservation(nouvelleReservation);
	baseDeDonnees.ajouterPassager(idPassager);
    std::cout << "Réservation créée et enregistrée  avec succès.\n";
}


std::vector<Trajet> TrajetControlleur::obtenirTrajets(std::string lieuDepart, std::string lieuArrivee, std::string date){
	return baseDeDonnees.getTrajetByVilleDepartEtArriveeEtDateDepart( lieuDepart, lieuArrivee, date);

}

void TrajetControlleur::creerTrajet(
	int idConducteur,
	std::string date,
	std::string heureDepart,
	std::string heureArrivee,
	std::string lieuDepart,
	std::string lieuArrivee,
	std::vector<std::pair<std::string, float>> segmentsPrix,
	std::vector<std::string> villesEtapes,
	bool disponible,
	bool allerRetour,
	bool animaux,
	std::string voiture,
	int nombrePlaceDispo,
	bool etat,
	float emissionCO2,
	std::string description){

    if (verifierSaisieTrajet(idConducteur, date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, segmentsPrix, {}, disponible, false, animaux, voiture, nombrePlaceDispo, true, emissionCO2, description)) {
    	Trajet nouveauTrajet(date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, segmentsPrix, {}, disponible, false, animaux, voiture, nombrePlaceDispo, true, emissionCO2, description);
    	baseDeDonnees.ajouterTrajet(nouveauTrajet, idConducteur);
    	baseDeDonnees.ajouterConducteur(idConducteur);
    	std::cout << "trajet ajouté.\n";
		} else {
			std::cout << "trajet non ajouté veuillez verifier vos infos.\n";
		}
    }


void TrajetControlleur::supprimerTrajet(int idTrajet){
	baseDeDonnees.supprimerTrajetByIDTrajet(idTrajet);
	std::cout << "trajet supprimé.\n";
}


void TrajetControlleur::supprimerReservation(int idReservation){
	baseDeDonnees.supprimerReservationByIDReservation(idReservation);
	std::cout << "Reservation supprimé.\n";
}


std::vector<Trajet> TrajetControlleur::obtenirTrajetsUtilisateur(int idConducteur) {
    try {
        Conducteur cond = baseDeDonnees.getConducteurByID(idConducteur);
        std::cout << "ID utilisateur envoyé : " << cond.getIdUtilisateur() << std::endl;
        std::cout << "tout va bien" << std::endl;
        std::vector<Trajet> liste = cond.getListeTrajet();
        std::cout << "tout va bien" << std::endl;
        return liste;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return {};
    }
}


std::map<Reservation, Trajet> TrajetControlleur::obtenirResvervationEtTrajetUtilisateur(int idUtilisateur) {
	std::vector<std::pair<Reservation, Trajet>> listePaires = baseDeDonnees.getReservationEtTrajetByIdPassager(idUtilisateur);
	std::map<Reservation, Trajet> dictionnaire;

	for (const auto& paire : listePaires) {
		dictionnaire.insert(paire);

	}
	return dictionnaire;
}
