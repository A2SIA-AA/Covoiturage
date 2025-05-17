#include "Modele_hpp/Utilisateur.hpp"

int Utilisateur::compteurUtilisateur = 0;

Utilisateur::Utilisateur(std::string nom, std::string prenom,
                         std::string email, std::string motPasse,
                         std::string adressePostale, bool fumeur) {
    compteurUtilisateur++;
    this->idUtilisateur = compteurUtilisateur;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->motPasse = motPasse;
    this->adressePostale = adressePostale;
    this->fumeur = fumeur;
}

//getters

int Utilisateur::getIdUtilisateur() {
    return idUtilisateur;
}

std::string Utilisateur::getNom() {
    return nom;
}

std::string Utilisateur::getPrenom() {
    return prenom;
}

std::string Utilisateur::getEmail() {
    return email;
}

std::string Utilisateur::getMotPasse() {
    return motPasse;
}

std::string Utilisateur::getAdressePostale() {
    return adressePostale;
}

bool Utilisateur::getFumeur() {
    return fumeur;
}

//setters

void Utilisateur::setIdUtilisateur(int id) {
    idUtilisateur = id;
}

void Utilisateur::setNom(std::string nom) {
    this->nom = nom;
}

void Utilisateur::setPrenom(std::string prenom) {
    this->prenom = prenom;
}

void Utilisateur::setEmail(std::string email) {
    this->email = email;
}

void Utilisateur::setMotPasse(std::string mdp) {
    motPasse = mdp;
}

void Utilisateur::setAdressePostale(std::string adressePostale) {
    this->adressePostale = adressePostale;
}

void Utilisateur::setFumeur(bool fumeur) {
    this->fumeur = fumeur;
}

