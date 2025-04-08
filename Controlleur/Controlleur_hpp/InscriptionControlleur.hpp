#ifndef __InscriptionControlleur_HPP__
#define __InscriptionControlleur_HPP__

#include <string>
/**
*
*/
class InscriptionControlleur{


  private:
    /**
     * 
     * @param a 
     * @param b 
     */
    void testDoc(int a, int b);
    /**
     * 
     * @param nom 
     * @param prenom 
     * @param email 
     * @param motPasse 
     * @param adressePostale 
     */
    void verifierSaisie(std::string nom, std::string prenom, std::string email, std::string motPasse,std::string adressePostale);


};
#endif