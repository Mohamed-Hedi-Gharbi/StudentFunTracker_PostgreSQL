# Gestion des Dossiers Apprenants

Ce projet, réalisé en langage C, est un outil de gestion des dossiers des apprenants. Il permet de créer, afficher, modifier et sauvegarder des dossiers, tout en calculant des moyennes.

## Fonctionnalités
- **Créer un dossier** : Ajout d'un nouvel apprenant dans la base de données PostgreSQL.
- **Afficher les dossiers** : Liste des apprenants enregistrés.
- **Calculer les moyennes** : Moyenne pondérée des notes.
- **Rechercher un dossier** : Recherche par nom.
- **Supprimer un dossier** : Suppression par identifiant.
- **Sauvegarde et Chargement** : Gestion des données persistantes dans une base de données PostgreSQL.

## Architecture du Projet
Le projet est organisé comme suit :

- **src/** : Contient les fichiers sources `.c` (par exemple `student.c`, `utils.c`, etc.).
- **include/** : Contient les fichiers d'en-tête `.h` (par exemple `student.h`, `utils.h`).
- **build/** : Contient les fichiers objets compilés (`*.o`).
- **Makefile** : Fichier pour gérer la compilation et le nettoyage du projet.
- **setup_database.sql** : Script SQL pour créer la base de données et la table des apprenants dans PostgreSQL.

## Instructions de Compilation et d'Exécution
1. **Compiler le projet** avec la commande `make` :
   ```bash
   make
