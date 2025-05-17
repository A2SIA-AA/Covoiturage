#include "../Controlleur_hpp/modifierProfilControlleur.hpp"
#include "../../Interface/Interface_hpp/ConnexionInterface.hpp"
#include "../../Interface/Interface_hpp/AccueilInterface.hpp"
#include <iostream>


void ModifierProfilControlleur::ModifierProfil(int id, std::string choix, std::string modification){
    baseDeDonnees.mettreAJourChampProfil(id, choix, modification);
}

