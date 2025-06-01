cmake_minimum_required(VERSION 3.10)
project(Covoiturage)

set(CMAKE_CXX_STANDARD 20)


include_directories(
        ${PROJECT_SOURCE_DIR}/Controlleur/Controlleur_hpp
        ${PROJECT_SOURCE_DIR}/Controlleur/Controlleur_cpp
        ${PROJECT_SOURCE_DIR}/Modele
        ${PROJECT_SOURCE_DIR}/Interface
        ${PROJECT_SOURCE_DIR}/Tests
)

# console

#set(CONSOLE_SOURCES
        #main1.cpp
        #Controlleur/Controlleur_cpp/ConnexionControlleur.cpp
        #Controlleur/Controlleur_cpp/InscriptionControlleur.cpp
        #Controlleur/Controlleur_cpp/RechercheControlleur.cpp
        #Controlleur/Controlleur_cpp/TrajetControlleur.cpp
        #Interface/Interface_cpp/AccueilConsole.cpp
        #Interface/Interface_cpp/ConnexionConsole.cpp
        #Interface/Interface_cpp/InscriptionConsole.cpp
        #Interface/Interface_cpp/MesAnnoncesConsole.cpp
        #Interface/Interface_cpp/MesReservationsConsole.cpp
        #Interface/Interface_cpp/TrajetConsole.cpp
        #Modele/Modele_cpp/BaseDonnees.cpp
        #Modele/Modele_cpp/Conducteur.cpp
        #Modele/Modele_cpp/Passager.cpp
        #Modele/Modele_cpp/Reservation.cpp
        #Modele/Modele_cpp/Trajet.cpp
        #Modele/Modele_cpp/Utilisateur.cpp


        #Tests/Test_controlleur/Test_calculerEmission.cpp
        #Tests/Test_controlleur/Test_verifierSaisieInscription.cpp
        #Tests/Test_controlleur/Test_VerifierSaisieTrajet.cpp
        #Tests/Test_controlleur/Test_verifierUtilisateur.cpp
        #Tests/Test_controlleur/Test_rechercherTrajet.cpp
        #Tests/Test_controlleur/Test_comparer.cpp
        #Tests/Test_controlleur/Test_comparerEmission.cpp
        #Tests/Test_controlleur/Test_comparerHeureDepart.cpp
        #Tests/Test_controlleur/Test_comparerPointIntermediaire.cpp
        #Tests/Test_controlleur/Test_comparerDuree.cpp
        #Tests/Test_controlleur/Test_comparerPrix.cpp
        #Tests/Test_interface/TestAccueilInterface.cpp
        #Tests/Test_interface/TestConnexionInterface.cpp
        #Tests/Test_interface/TestInscriptionInterface.cpp
        #Tests/Test_modele/Test_BDD.cpp

#)

#add_executable(Covoiturage ${CONSOLE_SOURCES})

# interface graphique
#set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

include_directories(
        ${PROJECT_SOURCE_DIR}/Interface/Interface_graphique/src
)

set(GUI_SOURCES
        main.cpp
        Controlleur/Controlleur_cpp/MainControlleur.cpp
        Controlleur/Controlleur_cpp/InscriptionControlleur.cpp
        Controlleur/Controlleur_cpp/ConnexionControlleur.cpp
        Controlleur/Controlleur_cpp/ModifierProfilControlleur.cpp
        Controlleur/Controlleur_cpp/RechercheControlleur.cpp
        Controlleur/Controlleur_cpp/TrajetControlleur.cpp
        Modele/Modele_cpp/BaseDonnees.cpp
        Modele/Modele_cpp/Utilisateur.cpp
        Modele/Modele_cpp/Trajet.cpp
        Modele/Modele_cpp/Reservation.cpp
        Modele/Modele_cpp/Conducteur.cpp
        Modele/Modele_cpp/Passager.cpp
        Interface/Interface_graphique/src/InscriptionFenetre.cpp
        Interface/Interface_graphique/src/AccueilFenetre.cpp
        Interface/Interface_graphique/src/ConnexionFenetre.cpp
        Interface/Interface_graphique/src/DetailTrajetFenetre.cpp
        Interface/Interface_graphique/src/DetailTrajetReservationFenetre.cpp
        Interface/Interface_graphique/src/MesAnnoncesFenetre.cpp
        Interface/Interface_graphique/src/MesReservationsFenetre.cpp
        Interface/Interface_graphique/src/ModifierProfilFenetre.cpp
        Interface/Interface_graphique/src/PublierTrajetFenetre.cpp
        Interface/Interface_graphique/src/RechercherTrajetFenetre.cpp


        # MOC
        moc_MainControlleur.cpp
        moc_AccueilFenetre.cpp
        moc_ConnexionFenetre.cpp
        moc_DetailTrajetFenetre.cpp
        moc_DetailTrajetReservationFenetre.cpp
        moc_InscriptionFenetre.cpp
        moc_MesAnnoncesFenetre.cpp
        moc_MesReservationsFenetre.cpp
        moc_ModifierProfilFenetre.cpp
        moc_PublierTrajetFenetre.cpp
        moc_RechercherTrajetFenetre.cpp
)


add_executable(CovoiturageGUI ${GUI_SOURCES})
target_link_libraries(CovoiturageGUI Qt5::Widgets sqlite3)
