#ifndef __Trajet_HPP__
#define __Trajet_HPP__

#include <string>
#include <vector>
/**
 * @class Trajet
 * Permet de modeliser et definir un trajet de covoiturage
 */
class Trajet{

private:
    int idTrajet;
    int idConducteur;
    std::string date;
    std::string heureDepart;
    std::string heureArrivee;
    std::string lieuDepart;
    std::string lieuArrivee;
    std::vector<std::pair<std::string, float>> segmentsPrix;
    std::vector<std::string> villesEtapes;
    bool disponible;
    bool allerRetour;
    bool animaux;
    std::string voiture;
    int nombrePlaceDispo;
    bool etat;
    float emissionCO2;
    std::string description;
    float prixTotal;

public:
    Trajet(std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);
    void setIdTrajet(int idTrajet);
    void setIdConducteur(int idConducteur);
    void setDate(std::string date);
    void setHeureDepart(std::string heureDepart);
    void setHeureArrive(std::string heureArrivee);
    void setLieuDepart(std::string lieuDepart);
    void setLieuArrive(std::string lieuArrivee);
    void setVoiture(std::string voiture);
    void setNombrePlaceDispo(int nombrePlaceDispo);
    void setDisponible(bool disponible);
    void setAllerRetour(bool allerRetour);
    void setAnimaux(bool animaux);
    void setEtat(bool etat);
    void setEmissionCO2(float emissionCO2);
    void setDescription(std::string description);
    void setSegmentsPrix(std::vector<std::pair<std::string, float>> segmentsPrix);
    void setVillesEtapes(std::vector<std::string> villesEtapes);
    void setPrixTotal(float prix);

    int getIdTrajet() const;
    int getIdConducteur() const;
    std::string getDate() const;
    std::string getHeureDepart() const;
    std::string getHeureArrive() const;
    std::string getLieuDepart() const;
    std::string getLieuArrive() const;
    std::string getVoiture() const;
    int getNombrePlaceDispo() const;
    bool getDisponible() const;
    bool getAllerRetour() const;
    bool getAnimaux() const;
    bool getEtat() const;
    float getEmissionCO2() const;
    std::string getDescription() const;
    std::vector<std::pair<std::string, float>> getSegmentsPrix() const;
    std::vector<std::string> getVillesEtapes() const;
    float getPrixTotal() const;

};

#endif
