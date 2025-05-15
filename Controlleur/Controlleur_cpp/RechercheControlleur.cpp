#include "../Controlleur_hpp/RechercheControlleur.hpp"
#include <algorithm>
#include <stdexcept>

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
        return a.getPrixTotal() < b.getPrixTotal();
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

std::vector<Trajet> RechercheControlleur::comparerDuree(const std::vector<Trajet>& trajetsDisponibles) {
    if (trajetsDisponibles.empty()) {
        return {};
    }
    auto sorted = trajetsDisponibles;
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.getDuree() < b.getDuree();
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
