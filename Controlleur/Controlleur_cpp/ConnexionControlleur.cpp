#include "../Controlleur_hpp/ConnexionControlleur.hpp"
#include <optional>


std::optional<Utilisateur> ConnexionControlleur::verifierUtilisateur(std::string email, std::string motPasse) {
    Utilisateur utilisateur = baseDeDonnees.getUtilisateurByEmailAndMDP(email, motPasse);
    if (!utilisateur.getEmail().empty()) {
        return utilisateur;
    } else {
        return std::nullopt;
    }
}

