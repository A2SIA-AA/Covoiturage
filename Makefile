# -----------------------------------------------------------------------
# Makefile pour CovoiturageApp + tests unitaires (Tests/Test_controlleur/* et Tests/Test_modele/*)
# -----------------------------------------------------------------------

CXX       := g++
CXXFLAGS  := -std=c++17 -Wall
INCLUDES  := -IControlleur/Controlleur_hpp \
             -IModele/Modele_hpp \
             -IInterface/Interface_hpp

LDFLAGS   := -lsqlite3
TARGET    := bin/CovoiturageApp

# -----------------------------------------------------------------------
# Sources de l’application principale
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
# Conversion noms de .cpp → .o (dans obj/…)
# -----------------------------------------------------------------------
OBJDIR := obj
OBJS   := $(SRCS:%.cpp=$(OBJDIR)/%.o)

# -----------------------------------------------------------------------
# Sources des tests (fichiers Test_*.cpp dans Tests/)
# -----------------------------------------------------------------------
TEST_DIR  := Tests

# On cherche tous les Test_*.cpp dans Test_controlleur ET dans Test_modele
TEST_SRCS := \
    $(wildcard $(TEST_DIR)/Test_controlleur/Test_*.cpp) \
    $(wildcard $(TEST_DIR)/Test_modele/Test_*.cpp)

# Nom simple de chaque test (Sans chemin ni .cpp)
TEST_NAMES := $(notdir $(TEST_SRCS:.cpp=))

# Chaque test donne lieu à un exécutable bin/Test_<nom>
TEST_BINS := $(addprefix bin/,$(TEST_NAMES))

# -----------------------------------------------------------------------
# Cibles principales
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

# 6.1 Création du dossier bin/ s’il n’existe pas
bin:
	@mkdir -p bin

# 6.2 Règle globale « tests » qui dépend de bin/ et de tous les exécutables bin/Test_*
tests: | bin $(TEST_BINS)

# 6.3 Construire chaque exécutable de test (Test_controlleur & Test_modele)
#     On définit deux motifs : l’un pour Test_controlleur, l’autre pour Test_modele

# Pour Tests/Test_controlleur/Test_<T>.cpp → bin/Test_<T>
bin/%: $(TEST_DIR)/Test_controlleur/%.cpp $(SRCS)
	@echo "=== Compilation du test $< → $@ ==="
	$(CXX) $(CXXFLAGS) $(INCLUDES) \
	    $< \
	    $(SRC_CONTROLLEUR) \
	    $(SRC_MODELE) \
	    $(SRC_INTERFACE) \
	    -o $@ $(LDFLAGS)

# Pour Tests/Test_modele/Test_<T>.cpp → bin/Test_<T>
bin/%: $(TEST_DIR)/Test_modele/%.cpp $(SRCS)
	@echo "=== Compilation du test $< → $@ ==="
	$(CXX) $(CXXFLAGS) $(INCLUDES) \
	    $< \
	    $(SRC_CONTROLLEUR) \
	    $(SRC_MODELE) \
	    $(SRC_INTERFACE) \
	    -o $@ $(LDFLAGS)

# -----------------------------------------------------------------------------
# 7) Nettoyage
# -----------------------------------------------------------------------------
clean:
	@echo "Suppression des .o et des exécutables…"
	@rm -rf $(OBJDIR) $(TARGET) bin
	@echo "Nettoyage effectué."
