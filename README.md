# C-Plus-Plus# C-Plus-Plus

Ce dépôt contient des projets développés en C++.

## 1 / MiniRecommender

Un système de recommandation de films basé sur la similarité entre utilisateurs, implémenté en C++.

### Description

MiniRecommender est un système de recommandation collaboratif qui :
- Charge les notes des utilisateurs depuis un fichier
- Calcule la similarité entre utilisateurs (similarité cosinus)
- Recommande des films basés sur les goûts d'utilisateurs similaires

### Structure du projet

```
MiniRecommender/
├── src/
│   ├── Utilisateur.h       # Classe représentant un utilisateur
│   ├── Utilisateur.cc      # Implémentation de la classe Utilisateur
│   ├── Systeme.h           # Classe gérant le système de recommandation
│   ├── Systeme.cc          # Implémentation de la classe Systeme
│   └── main.cc             # Programme principal de test
├── Makefile                # Script de compilation
└── Donnees/
    └── notes.txt           # Fichier de données (utilisateur,film,note)
```

### Fonctionnalités

#### Classe Utilisateur
- Stockage des notes de films (nom du film → note sur 5)
- Calcul de similarité cosinus avec d'autres utilisateurs
- Gestion des notes individuelles

#### Classe Systeme
- Chargement des données depuis un fichier TXT
- Gestion d'une collection d'utilisateurs
- Algorithme de recommandation basé sur l'utilisateur le plus similaire
- Recommandation de films bien notés (≥4/5) non vus par l'utilisateur cible

### Compilation et exécution

```bash
# Compilation
make

# Exécution
./a.out

# Nettoyage
make clean
```

### Format des données

Le fichier `Donnees/notes.txt` doit contenir des lignes au format :
```
nom_utilisateur,nom_film,note
```

Exemple :
```
Alice,Inception,5
Bob,Inception,4
Alice,Matrix,4
Charlie,Matrix,5
```

### Algorithme de recommandation

1. **Calcul de similarité** : Utilise la similarité cosinus entre les vecteurs de notes
2. **Sélection de l'utilisateur similaire** : Trouve l'utilisateur avec la plus haute similarité
3. **Génération de recommandations** : Propose les films bien notés (≥4/5) par l'utilisateur similaire que l'utilisateur cible n'a pas encore vus

### Exemple d'utilisation

Le programme de test affiche :
- La liste des utilisateurs chargés
- Les recommandations pour chaque utilisateur
- La gestion des cas d'erreur (utilisateur inexistant)
- Le détail des notes par utilisateur
##