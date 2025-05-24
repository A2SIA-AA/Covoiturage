#ifndef ACCUEILCONTROLLEUR_H
#define ACCUEILCONTROLLEUR_H

class AccueilControlleur
{
public:

    AccueilControlleur();

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
