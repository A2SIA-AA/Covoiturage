#ifndef AVISINTERFACE_HPP
#define AVISINTERFACE_HPP

#include <string>

/**
 * @file AvisInterface.hpp
 * @brief Interface pour la gestion des avis utilisateurs.
 *
 * Un avis possède une note, un commentaire, un type, un nom d'émetteur et un nom de récepteur.
 */
class AvisInterface {
public:
    virtual ~AvisInterface() = default;

    /**
     * @brief Crée un nouvel avis.
     * @param note La note (entier, par exemple sur 5).
     * @param commentaire Le texte du commentaire.
     * @param type_avis Le type d'avis (ex: "conducteur", "trajet", etc.).
     * @param nomEmetteur Le nom de la personne qui laisse l'avis.
     * @param nomRecepteur Le nom de la personne qui reçoit l'avis.
     * @return true si la création a réussi, false sinon.
     */
    virtual bool creerAvis(int note,
                           const std::string& commentaire,
                           const std::string& type_avis,
                           const std::string& nomEmetteur,
                           const std::string& nomRecepteur) = 0;

    /**
     * @brief Affiche ou récupère les informations d'un avis.
     * @param idAvis L'identifiant de l'avis à consulter (si tu as une gestion d'identifiants).
     * @return Une chaîne contenant les informations de l'avis (à adapter selon ton besoin).
     */
    virtual std::string consulterAvis(int idAvis) = 0;
};

#endif // AVISINTERFACE_HPP

