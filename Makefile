# -----------------------------------------------------------------------
# Makefile pour CovoiturageApp + tests unitaires (Test_*.cpp)
# -----------------------------------------------------------------------

# 1) Variables générales
# -----------------------------------------------------------------------
CXX       := g++
CXXFLAGS  := -std=c++17 -Wall
INCLUDES  := -IControlleur/Controlleur_hpp \
             -IModele/Modele_hpp \
             -IInterface/Interface_hpp

LDFLAGS   := -lsqlite3
TARGET    := CovoiturageApp

# -----------------------------------------------------------------------
# 2) Sources de l’application principale
# -----------------------------------------------------------------------
SRC_MAIN        := main_console.cpp

SRC_CONTROLLEUR := \
    Controlleur/Controlleur_cpp/InscriptionControlleur.cpp \
    Controlleur/Controlleur_cpp/ConnexionControlleur.cpp    \
    Controlleur/Controlleur_cpp/TrajetControlleur.cpp       \
    Controlleur/Controlleur_cpp/RechercheControlleur.cpp    \
    Controlleur/Controlleur_cpp/ModifierProfilControlleur.cpp

SRC_MODELE      := \
    Modele/Modele_cpp/BaseDonnees.cpp \
    Modele/Modele_cpp/Utilisateur.cpp \
    Modele/Modele_cpp/Conducteur.cpp  \
    Modele/Modele_cpp/Passager.cpp    \
    Modele/Modele_cpp/Reservation.cpp \
    Modele/Modele_cpp/Trajet.cpp

SRC_INTERFACE   := \
    Interface/Interface_cpp/TrajetConsole.cpp         \
    Interface/Interface_cpp/ConnexionConsole.cpp       \
    Interface/Interface_cpp/InscriptionConsole.cpp     \
    Interface/Interface_cpp/ModifierProfilConsole.cpp  \
    Interface/Interface_cpp/AccueilConsole.cpp         \
    Interface/Interface_cpp/MesAnnoncesConsole.cpp     \
    Interface/Interface_cpp/MesReservationsConsole.cpp

SRCS := \
    $(SRC_MAIN) \
    $(SRC_CONTROLLEUR) \
    $(SRC_MODELE) \
    $(SRC_INTERFACE)

# -----------------------------------------------------------------------
# 3) Conversion noms de .cpp → .o (dans obj/…)
# -----------------------------------------------------------------------
OBJDIR := obj
OBJS   := $(SRCS:%.cpp=$(OBJDIR)/%.o)

# -----------------------------------------------------------------------
# 4) Sources des tests (fichiers Test_*.cpp dans Tests/)
# -----------------------------------------------------------------------
TEST_DIR   := Tests
# Rechercher tous les fichiers Tests/Test_controlleur/Test_*.cpp
TEST_SRCS  := $(wildcard $(TEST_DIR)/Test_controlleur/Test_*.cpp)
# Extraire le nom simple (ex: “Test_monFonctionnalité”) sans le .cpp
TEST_NAMES := $(notdir $(TEST_SRCS:.cpp=))
# On produira pour chaque TEST_NAMES un exécutable bin/Test_monFonctionnalité
TEST_BINS  := $(addprefix bin/,$(TEST_NAMES))

# -----------------------------------------------------------------------
# 5) Cibles principales
# -----------------------------------------------------------------------
.PHONY: all app tests clean

all: app tests

# 5.1 Compilation de l’application principale
app: $(TARGET)

$(TARGET): $(OBJS)
	@echo "----------------------------"
	@echo "Édition des liens → $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)
	@echo "Compilation terminée : $@ généré."
	@echo "----------------------------"

# 5.2 Règle générique .cpp → .o pour l’application principale
$(OBJDIR)/%.o: %.cpp
	@echo "Compilation de $< → $@"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------------------------------------------------------
# 6) Compilation des tests unitaires
# -----------------------------------------------------------------------
# Pour chaque Tests/Test_controlleur/Test_*.cpp, on produit bin/Test_*.
# On lie chaque test avec toutes les sources de l’application.

# 6.1 Création du dossier bin/ s’il n’existe pas
bin:
	@mkdir -p bin

# 6.2 Règle globale « tests » qui dépend de bin/ et de tous les exécutables bin/Test_*
tests: | bin $(TEST_BINS)

# 6.3 Construire chaque exécutable de test
#     Exemple : Tests/Test_controlleur/Test_example.cpp → bin/Test_example
$(foreach T,$(TEST_NAMES),\
  $(eval \
    bin/$(T): $(TEST_DIR)/Test_controlleur/$(T).cpp $(SRCS) ; \
        @echo "=== Compilation du test $< → bin/$(T) ===" ; \
        $(CXX) $(CXXFLAGS) $(INCLUDES) \
            $(TEST_DIR)/Test_controlleur/$(T).cpp \
            $(SRC_CONTROLLEUR) \
            $(SRC_MODELE) \
            $(SRC_INTERFACE) \
            -o bin/$(T) $(LDFLAGS) ; \
  )\
)

# -----------------------------------------------------------------------------
# 7) Nettoyage
# -----------------------------------------------------------------------------
clean:
	@echo "Suppression des .o et des exécutables…"
	@rm -rf $(OBJDIR) $(TARGET) bin
	@echo "Nettoyage effectué."
