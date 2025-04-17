cmake_minimum_required(VERSION 3.10)
project(Covoiturage)

set(CMAKE_CXX_STANDARD 20)

# Ajoute les répertoires contenant les headers
include_directories(${PROJECT_SOURCE_DIR}/Controlleur/Controlleur_hpp)
include_directories(${PROJECT_SOURCE_DIR}/Controlleur/Controlleur_cpp)
include_directories(${PROJECT_SOURCE_DIR}/Modele)
include_directories(${PROJECT_SOURCE_DIR}/Interface)
include_directories(${PROJECT_SOURCE_DIR}/Tests)

# Liste des fichiers sources à compiler
set(SOURCES
        main.cpp
        Controlleur/Controlleur_cpp/ConnexionControlleur.cpp
        Controlleur/Controlleur_cpp/InscriptionControlleur.cpp
        Controlleur/Controlleur_cpp/RechercheControlleur.cpp
        Controlleur/Controlleur_cpp/ReservationControlleur.cpp
        Controlleur/Controlleur_cpp/TrajetControlleur.cpp
        Interface/Interface_cpp/AcceuilInterface.cpp
        Interface/Interface_cpp/ConnexionInterface.cpp
        Interface/Interface_cpp/InscriptionInterface.cpp
        Interface/Interface_cpp/MesAnnoncesInterface.cpp
        Interface/Interface_cpp/MesReservationsInterface.cpp
        Interface/Interface_cpp/RechercheInterface.cpp
        Interface/Interface_cpp/ReservationInterface.cpp
        Interface/Interface_cpp/TrajetInterface.cpp
        Modele/Modele_cpp/Avis.cpp
        Modele/Modele_cpp/BaseDonnees.cpp
        Modele/Modele_cpp/Conducteur.cpp
        Modele/Modele_cpp/Passager.cpp
        Modele/Modele_cpp/Reservation.cpp
        Modele/Modele_cpp/Trajet.cpp
        Modele/Modele_cpp/Utilisateur.cpp
        Tests/Test_controlleur/Test_calculerEmission.cpp
        Tests/Test_controlleur/Test_verifierSaisieInscription.cpp
        Tests/Test_controlleur/Test_VerifierSaisieTrajet.cpp
        Tests/Test_controlleur/Test_verifierUtilisateur.cpp
        Tests/Test_controlleur/Test_rechercherTrajet.cpp
        Tests/Test_controlleur/Test_comparer.cpp
        Tests/Test_controlleur/Test_comparerEmission.cpp
        Tests/Test_controlleur/Test_comparerHeureDepart.cpp
        Tests/Test_controlleur/Test_comparerPointIntermediaire.cpp
        Tests/Test_controlleur/Test_comparerDuree.cpp
        Tests/Test_controlleur/Test_comparerPrix.cpp
        Tests/Test_interface/TestAccueilInterface.cpp
        Tests/Test_interface/TestConnexionInterface.cpp
        Tests/Test_interface/TestInscriptionInterface.cpp
        Tests/Test_modele/Test_BDD.cpp
)

add_executable(Covoiturage ${SOURCES})