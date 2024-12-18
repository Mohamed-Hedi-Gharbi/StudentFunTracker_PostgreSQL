# 🗂️ Gestion des Dossiers Apprenants

Ce projet, développé en **langage C**, est un outil de gestion des dossiers des apprenants. Il permet d'effectuer des opérations courantes telles que la création, l'affichage, la modification et la suppression des dossiers, tout en calculant des moyennes pondérées. Les données sont sauvegardées de manière persistante dans une base de données **PostgreSQL**.

---

## ✨ Fonctionnalités

- 📋 **Créer un dossier** : Ajouter un nouvel apprenant dans la base de données PostgreSQL.  
- 🔍 **Rechercher un dossier** : Rechercher un apprenant par **nom**.  
- 📊 **Afficher les dossiers** : Lister tous les apprenants enregistrés dans la base.  
- 🧮 **Calculer les moyennes** : Calculer la moyenne pondérée des notes.  
- 🗑️ **Supprimer un dossier** : Supprimer un apprenant par son identifiant.  
- 💾 **Sauvegarde et Chargement** : Gérer la persistance des données via une base PostgreSQL.  

---

## 📁 Architecture du Projet

La structure du projet est organisée comme suit :  

```bash
.
├── include/              # Fichiers d'en-tête (.h)
│   ├── student.h
│   ├── utils.h
│   └── file_operations.h
│
├── src/                  # Fichiers sources (.c)
│   ├── main.c
│   ├── student.c
│   ├── utils.c
│   ├── file_operations.c
│   └── database.c
│
├── build/                # Fichiers objets compilés (.o)
│
├── bin/                  # Fichiers exécutables
│   └── gestion_dossiers
│
├── sql/
│   └── setup_database.sql # Script SQL pour créer la base PostgreSQL
│
├── .gitignore            # Exclusion des fichiers inutiles
├── Makefile              # Automatisation de la compilation
└── README.md             # Documentation du projet
```

---

## 🛠️ Pré-requis

Pour exécuter ce projet, vous devez disposer des éléments suivants :  
- **GCC** : Compilateur C.  
- **PostgreSQL** : Base de données relationnelle.  

### 📥 Installation de PostgreSQL  
Pour installer PostgreSQL sous Ubuntu, exécutez :  
```bash
sudo apt update
sudo apt install postgresql postgresql-contrib
```

---

## 🚀 Instructions de Compilation et d'Exécution

1. **Configurer la base de données** :  
   Exécutez le script SQL pour créer la base de données et la table des apprenants :  
   ```bash
   psql -U postgres -f sql/setup_database.sql
   ```

2. **Compiler le projet** avec la commande `make` :  
   ```bash
   make
   ```

3. **Exécuter le programme** :  
   ```bash
   ./bin/gestion_dossiers
   ```

4. **Nettoyer les fichiers objets** :  
   ```bash
   make clean
   ```

---

## 🗄️ Configuration de la Base de Données

Le script `setup_database.sql` contient la structure suivante :  

```sql
CREATE DATABASE student_db;

\c student_db;

CREATE TABLE students (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INTEGER NOT NULL,
    evale1 NUMERIC(4,2),
    evale2 NUMERIC(4,2)
);
```

---

## 📊 Exemple d'Exécution

Voici un exemple d'ajout et d'affichage d'un apprenant :  

1. **Ajouter un apprenant** :  
   ```
   Veuillez entrer le nom : Mohamed Hedi Gharbi  
   Veuillez entrer l'âge : 22  
   Veuillez entrer les notes (eval1, eval2) : 15.00, 19.00  
   ```
2. **Afficher les dossiers** :  
   ```
   ================================================================================
   | N° | Nom et Prénom            | Âge | Eval Num 1 | Eval Num 2 |
   ================================================================================
   | 1  | Mohamed Hedi Gharbi      | 22  | 15.00      | 14.00      |
   ================================================================================ 
   ```

---

## 🛡️ Licence

Ce projet est distribué sous la licence **MIT**. Voir le fichier `LICENSE` pour plus de détails.

---

## 🤝 Contribution

Les contributions sont les bienvenues ! Voici comment vous pouvez aider :  

1. Forkez ce dépôt.  
2. Créez une branche pour vos modifications : `git checkout -b feature/amélioration`.  
3. Soumettez vos modifications : `git commit -m "Ajout d'une nouvelle fonctionnalité"`.  
4. Poussez vers la branche distante : `git push origin feature/amélioration`.  
5. Ouvrez une **Pull Request**.  

---

## 👨‍💻 Auteur

- **Mohamed Hedi Gharbi [GitHub](https://github.com/Mohamed-Hedi-Gharbi)**  
    
- **Eya Gasmi**
  [GitHub](https://github.com/eyagasmi)
---

## 🧩 Remerciements

Merci à toutes les personnes qui ont contribué directement ou indirectement à la réalisation de ce projet.