#include <iostream>
#include <regex>
#include <vector>
#include <utility>

void TrajetControlleur::verifierSaisieTrajet(
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
    if (idTrajet <= 0) {
        std::cerr << "Erreur : idTrajet doit être supérieur à 0.\n";
        return;
    }

    // Vérifier format de la date (YYYY-MM-DD)
    std::regex regexDate(R"(^\d{4}-\d{2}-\d{2}$)");
    if (!std::regex_match(date, regexDate)) {
        std::cerr << "Erreur : le format de la date est invalide (attendu : YYYY-MM-DD).\n";
        return;
    }

    // Vérifier format des heures (HH:MM)
    std::regex regexHeure(R"(^\d{2}:\d{2}$)");
    if (!std::regex_match(heureDepart, regexHeure) || !std::regex_match(heureArrivee, regexHeure)) {
        std::cerr << "Erreur : le format des heures est invalide (attendu : HH:MM).\n";
        return;
    }

    // Vérifier que les lieux ne sont pas vides
    if (lieuDepart.empty() || lieuArrivee.empty()) {
        std::cerr << "Erreur : les lieux de départ et d’arrivée ne doivent pas être vides.\n";
        return;
    }

    // Vérifier que les segments de prix ont des valeurs positives
    for (const auto& segment : segmentsPrix) {
        if (segment.second < 0) {
            std::cerr << "Erreur : un segment a un prix négatif.\n";
            return;
        }
    }

    // Vérifier que le nombre de places est positif
    if (nombrePlaceDispo <= 0) {
        std::cerr << "Erreur : le nombre de places disponibles doit être supérieur à 0.\n";
        return;
    }

    // Vérifier que la voiture n'est pas vide
    if (voiture.empty()) {
        std::cerr << "Erreur : le champ voiture ne doit pas être vide.\n";
        return;
    }

    // Vérifier que les émissions de CO2 sont cohérentes
    if (emissionCO2 < 0) {
        std::cerr << "Erreur : les émissions de CO2 ne peuvent pas être négatives.\n";
        return;
    }

    // Si tout est bon
    std::cout << "Saisie du trajet vérifiée avec succès.\n";
}


void TrajetControlleur::reservation(int idTrajet, bool statut, float prix, int idPassager){
    Reservation nouvelleReservation(idTrajet, statut, prix, idPassager);
    baseDeDonnees.ajouterReservationDansBD(nouvelleReservation);
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
	enum etat,
	float emissionCO2,
	std::string description){

	Trajet nouveauTrajet(date, heureDepart, heureArrivee, lieuDepart, lieuArrivee, segmentsPrix, villesEtapes, disponible, allerRetour, animaux, voiture, nombrePlaceDispo, etat, emissionCO2, description);
	baseDeDonnees.ajouterTrajet(nouveauTrajet, idConducteur);
}


void TrajetControlleur::supprimerTrajet(int idTrajet){
	baseDeDonnees.supprimerTrajetByIDTrajet(idTrajet);
}


void TrajetControlleur::supprimerReservation(int idReservation){
	baseDeDonnees.supprimerReservationByIDReservation(idReservation);
}
