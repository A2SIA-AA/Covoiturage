# Projet Covoiturage (C++)

Application en ligne de commande (CLI) qui simule un service de covoiturage :  
inscription d’utilisateurs, publication et recherche de trajets, réservation de places, et gestion des annonces.  
Le projet contient aussi des tests unitaires pour les contrôleurs et les modèles.

---

## Fonctionnalités principales
- **Authentification** : inscription / connexion (conducteur ou passager)  
- **Création d’annonces** : un conducteur publie son trajet (date, villes, places)  
- **Recherche & réservation** : un passager trouve un trajet et réserve une place  
- **Tableaux personnels**  
  - « Mes annonces » pour les conducteurs  
  - « Mes réservations » pour les passagers  
- **Base de données en mémoire** : pratique pour lancer les tests sans dépendance externe  

---

## Arborescence (simplifiée)
```
Covoiturage/
├── Controlleur/             # Logique métier (Inscription, Connexion, etc.)
├── Modele/                  # Entités : Utilisateur, Trajet, Reservation…
├── Interface/               # Vue console (et ébauche GUI Qt)
├── Tests/                   # Tests unitaires
├── main_console.cpp         # Point d’entrée CLI
└── Makefile                 # Build + tests + clean

````

---

## Prérequis
| Outil / lib | Version conseillée |
|-------------|--------------------|
| **g++**     | ≥ 11 (C++17) |
| **make**    | GNU Make |
| **SQLite3** | (linké via `-lsqlite3`) |

---

## Compilation et exécution

```bash
# Cloner le projet
git clone https://github.com/Lolorien/Covoiturage.git
cd Covoiturage

# Construire l’application et les tests
make          # équivaut à "make all"

# Lancer l’application CLI
./bin/CovoiturageApp
```

### Exécuter les tests unitaires

```bash
make tests    # compile chaque Test_*.cpp dans bin/
# puis exécuter les exécutables générés, ex. :
./bin/Test_InscriptionControlleur
./bin/Test_Utilisateur
```

### Nettoyer les fichiers générés

```bash
make clean
```
