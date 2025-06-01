# Makefile pour CovoiturageApp

# -----------------------------------------------------------------------
# 1. Variables générales
# -----------------------------------------------------------------------

CXX        := g++
CXXFLAGS   := -std=c++17 -Wall
INCLUDES   := -IControlleur/Controlleur_hpp \
              -IModele/Modele_hpp \
              -IInterface/Interface_hpp
LDFLAGS    := -lsqlite3
TARGET     := CovoiturageApp

# -----------------------------------------------------------------------
# 2. Listes des sources par répertoire
# -----------------------------------------------------------------------

SRC_MAIN          := main1.cpp

SRC_CONTROLLEUR   := \
    Controlleur/Controlleur_cpp/InscriptionControlleur.cpp \
    Controlleur/Controlleur_cpp/ConnexionControlleur.cpp    \
    Controlleur/Controlleur_cpp/TrajetControlleur.cpp       \
    Controlleur/Controlleur_cpp/RechercheControlleur.cpp    \
    Controlleur/Controlleur_cpp/ModifierProfilControlleur.cpp

SRC_MODELE        := \
    Modele/Modele_cpp/BaseDonnees.cpp \
    Modele/Modele_cpp/Utilisateur.cpp \
    Modele/Modele_cpp/Conducteur.cpp  \
    Modele/Modele_cpp/Passager.cpp    \
    Modele/Modele_cpp/Reservation.cpp \
    Modele/Modele_cpp/Trajet.cpp

SRC_INTERFACE     := \
    Interface/Interface_cpp/TrajetConsole.cpp         \
    Interface/Interface_cpp/ConnexionConsole.cpp       \
    Interface/Interface_cpp/InscriptionConsole.cpp     \
    Interface/Interface_cpp/ModifierProfilConsole.cpp  \
    Interface/Interface_cpp/AccueilConsole.cpp         \
    Interface/Interface_cpp/MesAnnoncesConsole.cpp     \
    Interface/Interface_cpp/MesReservationsConsole.cpp

# -----------------------------------------------------------------------
# 3. Construction de la liste complète des sources
# -----------------------------------------------------------------------

SRCS := \
    $(SRC_MAIN) \
    $(SRC_CONTROLLEUR) \
    $(SRC_MODELE) \
    $(SRC_INTERFACE)

# -----------------------------------------------------------------------
# 4. Conversion noms de .cpp en .o (même arborescence d’objets)
# -----------------------------------------------------------------------

# Pour chaque .cpp, on définit le .o correspondant dans obj/…
# Exemple : Controlleur/Controlleur_cpp/InscriptionControlleur.cpp → obj/Controlleur/InscriptionControlleur.o

OBJDIR := obj
OBJS   := $(SRCS:%.cpp=$(OBJDIR)/%.o)

# -----------------------------------------------------------------------
# 5. Règles principales
# -----------------------------------------------------------------------

.PHONY: all clean

all: $(TARGET)

# Règle d’édition de liens finale
$(TARGET): $(OBJS)
	@echo "----------------------------"
	@echo "Édition des liens → $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)
	@echo "Compilation terminée : $@ généré."
	@echo "----------------------------"

# -----------------------------------------------------------------------
# 6. Règle générique de compilation .cpp → .o
# -----------------------------------------------------------------------
# Chaque .cpp produit obj/<même_chemin>.o

# $(OBJDIR)/%.o dépend de %.cpp
# Exemple : obj/Controlleur/InscriptionControlleur.o dépend de Controlleur/Controlleur_cpp/InscriptionControlleur.cpp

$(OBJDIR)/%.o: %.cpp
	@echo "Compilation de $< → $@"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------------------------------------------------------
# 7. Nettoyage
# -----------------------------------------------------------------------

clean:
	@echo "Suppression des .o et de l’exécutable…"
	@rm -rf $(OBJDIR) $(TARGET)
	@echo "Nettoyage effectué."
