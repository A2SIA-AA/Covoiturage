//
// Created by amzil on 20/05/25.
//

#ifndef MESANNONCESCONSOLE_HPP
#define MESANNONCESCONSOLE_HPP

#include <vector>
#include <string>
#include "../MesAnnoncesInterface.hpp"
#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"


/**
 * @class MesAnnoncesConsole
 * @brief Implémentation console pour la gestion des annonces de l'utilisateur.
 *
 * Cette classe permet d'interagir avec les annonces de l'utilisateur via une interface en ligne de commande.
 * Elle offre des fonctionnalités pour afficher, lister et gérer les annonces de trajets de l'utilisateur.
 */
class MesAnnoncesConsole : public MesAnnoncesInterface {
private:
    Database db;
public:
    /**
 * @brief Destructeur virtuel.
 */
    ~MesAnnoncesConsole() override;

    /**
     * @brief Liste les annonces associées à un utilisateur donné.
     * @param utilisateurId Identifiant de l'utilisateur dont on souhaite récupérer les annonces.
     * @return Vecteur de chaînes correspondant aux annonces trouvées.
     */

    std::vector<std::string> listerAnnonces(int utilisateurId) override;

    /**
 * @brief Liste toutes les annonces de l'utilisateur courant.
 * @return Vecteur de chaînes correspondant aux annonces trouvées.
 */

    std::vector<std::string> listerAnnonces();

    /**
 * @brief Constructeur à partir d'une base de données.
 * @param db Base de données à utiliser pour les opérations d’annonces.
 */

    MesAnnoncesConsole(Database& db);

    /**
 * @brief Affiche toutes les annonces de l'utilisateur à la console.
 */

    void afficherAnnonces();
};


#endif //MESANNONCESCONSOLE_HPP
