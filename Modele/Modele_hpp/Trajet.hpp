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
    static int compteurTrajet;
    int idTrajet;
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

public:
    Trajet(std::string date, std::string heureDepart, std::string heureArrivee, std::string lieuDepart, std::string lieuArrivee, std::vector<std::pair<std::string, float>> segmentsPrix, std::vector<std::string> villesEtapes, bool disponible, bool allerRetour, bool animaux, std::string voiture, int nombrePlaceDispo, bool etat, float emissionCO2, std::string description);
    void setIdTrajet(int idTrajet);
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

    int getIdTrajet();
    std::string getDate();
    std::string getHeureDepart();
    std::string getHeureArrive();
    std::string getLieuDepart();
    std::string getLieuArrive();
    std::string getVoiture();
    int getNombrePlaceDispo();
    bool getDisponible();
    bool getAllerRetour();
    bool getAnimaux();
    bool getEtat();
    float getEmissionCO2();
    std::string getDescription();
    std::vector<std::pair<std::string, float>> getSegmentsPrix();
    std::vector<std::string> getVillesEtapes();

};

#endif
