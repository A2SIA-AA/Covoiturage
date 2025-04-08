#ifndef __RECHERCHE__
#define __RECHERCHE__

#include <string>

class RechercheControlleur{


private:

    void rechercherTrajet(std::string villeDepart, std::string villeArrivee, std::string Horaire, std::string Filtre);
    void comparerPrix();
    void comparerEmission();
    void comparerDistanceTrajet();
    float calculerEmission();
    void comparerDuree();
    void comparerHeureDepart();
    void comparerPointIntermediaire();
    void comparer();

};
#endif