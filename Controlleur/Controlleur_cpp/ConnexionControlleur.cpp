#include "../Controlleur_hpp/ConnexionControlleur.hpp"

bool ConnexionControlleur::verifierUtilisateur(std::string email, std::string motPasse) {
    Utilisateur* utilisateur = baseDeDonnees.getUtilisateurByEmailAndMDP(email, motPasse);
    if (utilisateur != nullptr) {
        delete utilisateur;  // libérer si alloué dynamiquement
        return true;
    } else {
        return false;
    }
}

