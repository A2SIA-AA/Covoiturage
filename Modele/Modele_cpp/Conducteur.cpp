#include "Modele_hpp/Conducteur.hpp"

// Constructeur
Conducteur::Conducteur(std::string nom, std::string prenom,
                       std::string email, std::string motPasse,
                       std::string adressePostale, bool fumeur,
                       std::vector<Trajet> listeTrajet)
    : Utilisateur(nom, prenom, email, motPasse, adressePostale, fumeur),
      listeTrajet(listeTrajet) // Initialisation correcte du membre
{}

// Méthode getter
std::vector<Trajet> Conducteur::getListeTrajet() {
    return listeTrajet;
}

// Méthode setter
void Conducteur::setListeTrajet(const std::vector<Trajet> LTrajet) {
    listeTrajet = LTrajet;
}
