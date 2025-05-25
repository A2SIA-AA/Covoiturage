#ifndef ACCUEILCONTROLLEUR_H
#define ACCUEILCONTROLLEUR_H
#include "BaseControlleur.hpp"
#include "Modele_hpp/BaseDonnees.hpp"

class AccueilControlleur : public BaseControlleur{
public:

    /**
 * @brief Constructeur implicite à partir de la base de données.
 * @param db Référence à l'objet Database partagé.
 */
    explicit AccueilControlleur(Database& db)
        : BaseControlleur(db)
    {
    }

    /**
    * @brief Redirige l'utilisateur vers "ModifierProfilInterface"
    */
    void TraiterModifierProfil();

    /**
     * @brief Redirige l'utilisateur vers "RechercheInterface"
     */
    void TraiterRecherche();

    /**
     * @brief Redirige l'utilisateur vers "MesReservationInterface"
     */
    void TraiterMesReservation();

    /**
     * @brief Redirige l'utilisateur vers "MesAnnoncesInterface"
     */
    void TraiterMesAnnonces();
};

#endif //ACCUEILCONTROLLEUR_H
