#include "../Controlleur_hpp/ConnexionControlleur.hpp"

bool ConnexionControlleur::verifierUtilisateur(std::string email, std::string motPasse) {
    Utilisateur utilisateur = baseDeDonnees.getUtilisateurByEmailAndMDP(email, motPasse);
    if (!utilisateur.getEmail().empty()) {
        return true;
    } else {
        return false;
    }
}

