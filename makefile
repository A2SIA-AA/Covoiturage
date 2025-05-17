# ===============================
# Makefile : Compilation et vérification des headers
# ===============================

TARGET   = testEval

CC       = g++
# Compiling flags
CFLAGS   = -std=c++11 -Wall -I.

LINKER   = g++
# Linking flags
LFLAGS   = -Wall -I. -lm

# Répertoires des fichiers .cpp et .hpp
SRCDIR   = Controlleur_cpp Modele_cpp Interface_cpp
SRCDIR2  = Controlleur_hpp Modele_hpp Interface_hpp
OBJDIR   = obj
BINDIR   = bin

# Récupère tous les fichiers .cpp dans les répertoires spécifiés
SOURCES := $(wildcard $(SRCDIR)/*.cpp) #$(wildcard main.cpp)
# Récupère tous les fichiers .hpp dans les répertoires spécifiés
INCLUDES := $(wildcard $(SRCDIR2)/*.hpp)
# Crée une liste d'objets à partir des fichiers .cpp
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf

# Règle principale pour la compilation et le linking
$(BINDIR)/$(TARGET) : $(OBJECTS)
	$(LINKER) $^ -o $@ $(LFLAGS)
	@echo "Linking complete!"

# Règle de compilation des fichiers .cpp en fichiers .o
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

# ============================
# Commandes de vérification des headers
# ============================

# Vérifie les headers dans Controlleur
check-controlleur:
	@echo "Vérification des headers Controlleur..."
	@for file in $(wildcard Controlleur_hpp/*.hpp); do \
		echo "Vérification de $$file..."; \
		$(CXX) $(CXXFLAGS) -fsyntax-only $$file || echo "Erreur dans $$file"; \
	done
	@echo "Vérification terminée pour Controlleur."

# Vérifie les headers dans Modele
check-modele:
	@echo "Vérification des headers Modele..."
	@for file in $(wildcard Modele_hpp/*.hpp); do \
		echo "Vérification de $$file..."; \
		$(CXX) $(CXXFLAGS) -fsyntax-only $$file || echo "Erreur dans $$file"; \
	done
	@echo "Vérification terminée pour Modele."

# Vérifie les headers dans Interface
check-interface:
	@echo "Vérification des headers Interface..."
	@for file in $(wildcard Interface_hpp/*.hpp); do \
		echo "Vérification de $$file..."; \
		$(CXX) $(CXXFLAGS) -fsyntax-only $$file || echo "Erreur dans $$file"; \
	done
	@echo "Vérification terminée pour Interface."

# ============================
# Commandes de nettoyage
# ============================

# Nettoyage des fichiers .o
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

# Supprimer l'exécutable
.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

# ============================
# Commande par défaut
# ============================

.PHONY: all
all: $(BINDIR)/$(TARGET)
