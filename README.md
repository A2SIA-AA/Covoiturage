# Projet Covoiturage (C++)

Application en ligne de commande (CLI) qui simule un service de covoiturage :  
inscription d’utilisateurs, publication et recherche de trajets, réservation de places, et gestion des annonces.  
Le projet contient aussi des tests unitaires pour les contrôleurs et les modèles.

Dépôt d’origine : <https://github.com/Lolorien/Covoiturage.git>.

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

