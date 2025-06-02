#include "../Controlleur_hpp/RechercheControlleur.hpp"
#include <algorithm>
#include <numeric>
#include <sstream>


std::vector<Trajet> RechercheControlleur::rechercherTrajet(std::string villeDepart,
                                                           std::string villeArrivee,
                                                           std::string Date) {
    // Au lieu de throw, on interroge la BD
    return baseDeDonnees.getTrajetByVilleDepartEtArriveeEtDateDepart(
        villeDepart, villeArrivee, Date
    );
}


std::vector<Trajet> RechercheControlleur::comparerPrix (const std::vector<Trajet>& trajetsDisponibles) {
    if (trajetsDisponibles.empty()) return {};

    auto sorted = trajetsDisponibles;

    std::sort(sorted.begin(), sorted.end(), [](const Trajet& a, const Trajet& b) {
        float prixA = 0;
        for (const auto& seg : a.getSegmentsPrix()) {
            prixA += seg.second;
        }

        float prixB = 0;
        for (const auto& seg : b.getSegmentsPrix()) {
            prixB += seg.second;
        }

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
                                             const std::string& typeVehiculeStr,
                                             float consommationMoyenne,
                                             int anciennete) {
    // Facteurs (kg CO₂ / litre)
    float facteur = 2.31f;              // essence par défaut
    std::string type = typeVehiculeStr;
    std::transform(type.begin(), type.end(), type.begin(), [](unsigned char c){ return std::tolower(c); });
    if (type == "diesel")      facteur = 2.68f;
    else if (type == "essence") facteur = 2.31f;
    else if (type == "electrique" || type == "électrique") facteur = 0.0f;

    if  (consommationMoyenne <= 0.0f)
    {
        std::cout << "Erreur : consommationMoyenne <= 0.0f" << std::endl;
        return -1.0;
    }
    // Émission brute en kg
    float emission = (distance * consommationMoyenne / 100.0f) * facteur;

    // Ajustement selon ancienneté (max 30 ans)
    constexpr float DUREE_MAX = 30.0f;
    if (anciennete >= 0 && anciennete < DUREE_MAX) {
        emission *= (1.0f - anciennete / DUREE_MAX);
    }
    return emission;
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

std::vector<Trajet> RechercheControlleur::comparerPointIntermediaire(
    const std::vector<Trajet>& trajetsDisponibles)
{
    if (trajetsDisponibles.empty()) {
        return {};
    }
    auto sorted = trajetsDisponibles;
    std::sort(sorted.begin(), sorted.end(),
        [](auto& a, auto& b) {
            return a.getVillesEtapes().size() < b.getVillesEtapes().size();
        });
    return sorted;
}

std::vector<Trajet> RechercheControlleur::comparer(const std::vector<Trajet>& trajetsDisponibles) {
    // critère par défaut : prix
    return comparerPrix(trajetsDisponibles);
}
