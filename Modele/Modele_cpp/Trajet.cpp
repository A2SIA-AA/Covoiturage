#include "../Modele_hpp/Trajet.hpp"



Trajet::Trajet( std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee,
               std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes,
               bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo,
               bool etat, float emissionCO2, std::string description)
        : idConducteur(0),
          date(date), heureDepart(heureDepart), heureArrivee(heureArrivee),
          lieuDepart(lieuDepart), lieuArrivee(lieuArrivee),
          segmentsPrix(segmentsPrix), villesEtapes(villesEtapes),
          disponible(disponible), allerRetour(allerRetour), animaux(animaux),
          voiture(voiture), nombrePlaceDispo(nombrePlaceDispo),
          etat(etat), emissionCO2(emissionCO2), description(description) {}


// Getters
int Trajet::getIdTrajet() const{ return idTrajet; }
std::string Trajet::getDate() const{ return date; }
std::string Trajet::getHeureDepart() const{ return heureDepart; }
std::string Trajet::getHeureArrive() const{ return heureArrivee; }
std::string Trajet::getLieuDepart() const{ return lieuDepart; }
std::string Trajet::getLieuArrive() const{ return lieuArrivee; }
std::vector<std::pair<std::string, float>> Trajet::getSegmentsPrix() const{ return segmentsPrix; }
std::vector<std::string> Trajet::getVillesEtapes() const{ return villesEtapes; }
std::string Trajet::getVoiture() const{ return voiture; }
int Trajet::getNombrePlaceDispo() const{ return nombrePlaceDispo; }
bool Trajet::getDisponible() const{ return disponible; }
bool Trajet::getAllerRetour() const{ return allerRetour; }
bool Trajet::getAnimaux() const{ return animaux; }
bool Trajet::getEtat() const{ return etat; }
float Trajet::getEmissionCO2() const{ return emissionCO2; }
std::string Trajet::getDescription() const{ return description; }

// Setters
void Trajet::setIdTrajet(int idTrajet) { this->idTrajet = idTrajet; }
void Trajet::setDate(std::string date) { this->date = date; }
void Trajet::setHeureDepart(std::string heureDepart) { this->heureDepart = heureDepart; }
void Trajet::setHeureArrive(std::string heureArrivee) { this->heureArrivee = heureArrivee; }
void Trajet::setLieuDepart(std::string lieuDepart) { this->lieuDepart = lieuDepart; }
void Trajet::setLieuArrive(std::string lieuArrivee) { this->lieuArrivee = lieuArrivee; }
void Trajet::setSegmentsPrix(std::vector<std::pair<std::string, float>> segmentsPrix) { this->segmentsPrix = segmentsPrix; }
void Trajet::setVillesEtapes(std::vector<std::string> villesEtapes) { this->villesEtapes = villesEtapes; }
void Trajet::setVoiture(std::string voiture) { this->voiture = voiture; }
void Trajet::setNombrePlaceDispo(int nombrePlaceDispo) { this->nombrePlaceDispo = nombrePlaceDispo; }
void Trajet::setDisponible(bool disponible) { this->disponible = disponible; }
void Trajet::setAllerRetour(bool allerRetour) { this->allerRetour = allerRetour; }
void Trajet::setAnimaux(bool animaux) { this->animaux = animaux; }
void Trajet::setEtat(bool etat) { this->etat = etat; }
void Trajet::setEmissionCO2(float emissionCO2) { this->emissionCO2 = emissionCO2; }
void Trajet::setDescription(std::string description) { this->description = description; }
void Trajet::setPrixTotal(float prix) {this->prixTotal = prix;}

float Trajet::getPrixTotal() const {
    float somme = 0.0f;
    for (const auto& segment : this->segmentsPrix) {
        somme += segment.second;
    }
    //this->prixTotal = somme;
    return somme;
}

