#ifndef __AVIS_HPP__
#define __AVIS_HPP__

#include <string>
/**
 * @class Avis
 * @brief Représente un avis laissé ou recu par un utilisateur à propos d’un trajet.
 *
 * Cette classe permet de gérer les retours (notes et commentaires) associés à un trajet.
 */

class Avis{
    private:
            int note;
            int idTrajet;
            std::string commentaire;
            std::string typeAvis;
            std::string nomEmetteur;
            std::string nomRecepteur;

   public:
     Avis(int note, std::string commentaire, std::string typeAvis);

     int getNote();
     int getIdTrajet();
     std::string getCommentaire();
     std::string getTypeAvis();

     void setNote(int note);
     void setCommentaire(std::string commentaire);
     void setTypeAvis(std::string typeAvis);
     void setIdTrajet(int ID);
};
#endif