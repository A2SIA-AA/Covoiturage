#include "../Controlleur_hpp/RechercheControlleur.hpp"
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <sstream>

RechercheControlleur::RechercheControlleur() {}


std::vector<Trajet> RechercheControlleur::rechercherTrajet(std::string villeDepart,
                                                           std::string villeArrivee,
                                                           std::string Date) {
    //  récupérer les trajets le modèle
    throw std::logic_error("rechercherTrajet non implémentée");
}

std::vector<Trajet> RechercheControlleur::comparerPrix(const std::vector<Trajet>& trajetsDisponibles) {
    if (trajetsDisponibles.empty()) {
        return {};
    }
    //Copie de la liste pour ne pas la modifier
    auto sorted = trajetsDisponibles;
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        float prixA = std::accumulate(
                a.getSegmentsPrix().begin(), a.getSegmentsPrix().end(),
                0.0f,
                [](float sum, const auto& seg){
                    return sum + seg.second;
                });
        float prixB = std::accumulate(
                b.getSegmentsPrix().begin(), b.getSegmentsPrix().end(),
                0.0f,
                [](float sum, const auto& seg){
                    return sum + seg.second;
                });
        return prixA < prixB;
    });
    return sorted;
}

std::vector<Trajet> RechercheControlleur::comparerEmission(const std::vector<Trajet>& trajetsDisponibles) {
    if (trajetsDisponibles.empty()) {
        return {};
    }
    auto sorted = trajetsDisponibles;
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.getEmissionCO2() < b.getEmissionCO2();
    });
    return sorted;
}

float RechercheControlleur::calculerEmission(float distance,
                                             std::string voiture,
                                             float consommationMoyenne) {
    const float facteurCO2_parLitre = 2.31f; // kg CO2 par litre
    // Calcul : (distance en km) * (L/100km) * facteur, converti en tonnes
    return (distance * consommationMoyenne / 100.0f) * facteurCO2_parLitre / 1000.0f;
}


static int minutesDepuisMinuit(const std::string& hhmm) {
    std::istringstream ss(hhmm);
    int h, m;
    char sep;
    ss >> h >> sep >> m; // lit par exemple  "08:30" -> h=8, m=30
    return h * 60 + m;
}

std::vector<Trajet> RechercheControlleur::comparerDuree(
    const std::vector<Trajet>& trajetsDisponibles)
{
    if (trajetsDisponibles.empty()) {
        return {};
    }
    // Copie pour ne pas modifier l'original
    auto sorted = trajetsDisponibles;

    // Lambda qui renvoie la durée en minutes de chaque trajet
    auto dureeEnMinutes = [](Trajet& t) {
        int depart  = minutesDepuisMinuit(t.getHeureDepart());
        int arrivee = minutesDepuisMinuit(t.getHeureArrive());
        int diff = arrivee - depart;
        // Si le trajet peut passer après minuit : gère un cas > 1440
        if (diff < 0) diff += 24 * 60;
        return diff;
    };

    // Tri selon cette durée
    std::sort(sorted.begin(), sorted.end(),
        [&](auto& a, auto& b) {
            return dureeEnMinutes(a) < dureeEnMinutes(b);
        });

    return sorted;
}

std::vector<Trajet> RechercheControlleur::comparerHeureDepart(const std::vector<Trajet>& trajetsDisponibles) {
    if (trajetsDisponibles.empty()) {
        return {};
    }
    auto sorted = trajetsDisponibles;
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.getHeureDepart() < b.getHeureDepart();
    });
    return sorted;
}

std::vector<Trajet> RechercheControlleur::comparerPointIntermediaire(const std::vector<Trajet>& trajetsDisponibles) {
    if (trajetsDisponibles.empty()) {
        return {};
    }
    auto sorted = trajetsDisponibles;
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.getNbEtapes() < b.getNbEtapes();
    });
    return sorted;
}

std::vector<Trajet> RechercheControlleur::comparer(const std::vector<Trajet>& trajetsDisponibles) {
    // critère par défaut : prix
    return comparerPrix(trajetsDisponibles);
}
