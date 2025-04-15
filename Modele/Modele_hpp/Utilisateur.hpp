#ifndef __UTILISATEUR_HPP__
#define __UTILISATEUR_HPP__

#include <string>
/**
 * @class Utilisateur
 * Permet de modeliser et definir un utilisateur
 */
class Utilisateur{
    // attributs
    private:
        int idUtilisateur;
        std::string nom;
        std::string prenom;
        std::string email;
        std::string motPasse;
        std::string adressePostale;
        bool fumeur;


    public:

        Utilisateur(int idUtilisateur, std::string nom, std::string prenom,std::string email,std::string motPasse,std::string adressePostale, bool fumeur);
        int getIdUtilisateur();
        std::string getNom();
        std::string getPrenom();
        std::string getEmail();
        std::string getMotPasse();
        std::string getAdressePostale();
        bool getFumeur();
        void setIdUtilisateur(int id);
        void setNom(std::string nom);
        void setPrenom(std::string prenom);
        void setEmail(std::string mail);
        void setMotPasse(std::string motpasse);
        void setAdressePostale(std::string adressePostale);
        void setFumeur(bool fumeur);


};

#endif
