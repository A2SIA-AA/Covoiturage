//
// Created by amzil on 20/05/25.
//

#ifndef RECHERCHECONSOLE_HPP
#define RECHERCHECONSOLE_HPP

#include <tuple>
#include <string>
#include "../RechercheInterface.hpp"


class RechercheConsole : public RechercheInterface {
private:
    void afficherMenuPrincipal() const override;

public:
    [[nodiscard]] std::tuple<std::string, std::string, std::string> rechercher() const override;

    [[nodiscard]] static std::tuple<std::string, std::string, std::string> rechercher(const std::string& villeDepart,
                                                                                      const std::string& villeArrivee,
                                                                                      const std::string& date);

    // destructeur virtuel
    ~RechercheConsole() override;
};

#endif //RECHERCHECONSOLE_HPP
