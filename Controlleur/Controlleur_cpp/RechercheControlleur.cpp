#include "../Controlleur_hpp/RechercheControlleur.hpp"
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <sstream>


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

float RechercheControlleur::calculerEmission(
    float distance,
    const std::string& typeVehiculeStr,
    float consommationMoyenne,
    int anciennete           // âge du véhicule en années
) {
    // 1) Définit un enum local
    enum class TypeVehicule { Essence, Diesel, Electrique, Inconnu };

    // 2) Passe la chaîne en minuscules
    std::string s = typeVehiculeStr;
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    // 3) Convertis la chaîne en enum
    TypeVehicule type = TypeVehicule::Inconnu;
    if (s == "diesel") {
        type = TypeVehicule::Diesel;
    }
    else if (s == "essence") {
        type = TypeVehicule::Essence;
    }
    else if (s == "electrique") {
        type = TypeVehicule::Electrique;
    }

    // 4) Choisis le facteur CO₂ selon le type
    float facteurKgParUnite;
    switch (type) {
        case TypeVehicule::Diesel:
            facteurKgParUnite = 2.7f;   // kg CO₂ / L
            break;
        case TypeVehicule::Essence:
            facteurKgParUnite = 2.31f;   // kg CO₂ / L
            break;
        case TypeVehicule::Electrique:
            facteurKgParUnite = 0.09f;   // kg CO₂ / kWh (mix moyen)
            break;
        default:
            // si inconnu, on choisit essence par défaut
            facteurKgParUnite = 2.31f;
            break;
    }

    constexpr float alpha = 0.02f;
    float majoration = 1.0f + anciennete * alpha;

    // calcul
    float emissionKg = (distance * consommationMoyenne / 100.0f)
                       * facteurKgParUnite
                       * majoration;
    return emissionKg / 1000.0f;  // en tonnes
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
