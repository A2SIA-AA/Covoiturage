#ifndef MODIFIERPROFILCONSOLE_HPP
#define MODIFIERPROFILCONSOLE_HPP

#include "../ModifierProfilInterface.hpp"
#include "../../../Modele/Modele_hpp/BaseDonnees.hpp"

/**
 * @brief Classe permettant de modifier le profil d'un utilisateur via une interface console.
 *
 * ModifierProfilConsole hérite de ModifierProfilInterface et propose une implémentation pour permettre
 * à un utilisateur de modifier ses informations personnelles directement depuis la console.
 */
class ModifierProfilConsole : public ModifierProfilInterface {
private:
    /**
 * @brief Référence à la base de données de l'application.
 *
 * Permet de lire et modifier les données de l'utilisateur durant la modification du profil.
 */

    Database db;
public:
    /**
     * @brief Constructeur de la classe ModifierProfilConsole.
     *
     * Initialise l'interface de modification du profil avec la base de données fournie.
     *
     * @param db Référence vers l'objet Database permettant d'accéder aux données persistantes.
     */

    ~ModifierProfilConsole() override;


    /**
 * @brief Destructeur de la classe ModifierProfilConsole.
 *
 * Libère les ressources éventuellement allouées lors de la gestion du profil.
 */

    bool modifierCoordonnees();

    /**
 * @brief Permet à l'utilisateur de modifier ses coordonnées via la console.
 *
 * Lance une interaction avec l'utilisateur pour saisir les nouvelles informations (nom, email, etc.).
 * Valide les entrées et met à jour la base de données.
 *
 * @return true si la modification a été effectuée avec succès, false sinon.
 */

    ModifierProfilConsole(Database& db);
};

#endif // MODIFIERPROFILCONSOLE_HPP
