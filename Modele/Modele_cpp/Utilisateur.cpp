#include "../Modele_hpp/Utilisateur.hpp"



Utilisateur::Utilisateur(std::string nom, std::string prenom,
                         std::string email, std::string motPasse,
                         std::string adressePostale, bool fumeur) {
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->motPasse = motPasse;
    this->adressePostale = adressePostale;
    this->fumeur = fumeur;
}

//getters

int Utilisateur::getIdUtilisateur() const{
    return idUtilisateur;
}

std::string Utilisateur::getNom() const{
    return nom;
}

std::string Utilisateur::getPrenom() const{
    return prenom;
}

std::string Utilisateur::getEmail() const{
    return email;
}

std::string Utilisateur::getMotPasse() const{
    return motPasse;
}

std::string Utilisateur::getAdressePostale() const{
    return adressePostale;
}

bool Utilisateur::getFumeur() const{
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

