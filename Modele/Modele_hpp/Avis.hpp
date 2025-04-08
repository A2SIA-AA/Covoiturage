#ifndef __AVIS_HPP__
#define __AVIS_HPP__

#include <string>

class Avis{
    private:
            int note;
            std::string commentaire;
            std::string typeAvis;

   public:
     Avis(int note, std::string commentaire, std::string typeAvis);

     int getNote();
     std::string getCommentaire();
     std::string getTypeAvis();

     void setNote(int note);
     void setCommentaire(std::string commentaire);
     void setTypeAvis(std::string typeAvis);

};
#endif