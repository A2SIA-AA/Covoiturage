#ifndef __UTILISATEUR_HPP__
#define __UTILISATEUR_HPP__

#include <string>
/**
 * @class Utilisateur
 * Permet de modeliser et definir un utilisateur
 */
class Utilisateur{
    private:

    int idUtilisateur;
        std::string nom;
        std::string prenom;
        std::string email;
        std::string motPasse;
        std::string adressePostale;
        bool fumeur;




public:
        Utilisateur(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale, bool fumeur);
        int getIdUtilisateur() const;
        std::string getNom() const;
        std::string getPrenom() const;
        std::string getEmail() const;
        std::string getMotPasse() const;
        std::string getAdressePostale() const;
        bool getFumeur() const;
        void setIdUtilisateur(int id);
        void setNom(std::string nom);
        void setPrenom(std::string prenom);
        void setEmail(std::string mail);
        void setMotPasse(std::string motpasse);
        void setAdressePostale(std::string adressePostale);
        void setFumeur(bool fumeur);


};

#endif
