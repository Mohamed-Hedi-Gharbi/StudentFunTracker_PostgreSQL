--? Création de la base de données
CREATE DATABASE cft_db;


--? Connexion à la base de données
\c cft_db;

--? Création de la table students
CREATE TABLE students (
    id SERIAL PRIMARY KEY,                                              --* Identifiant unique pour chaque apprenant
    name VARCHAR(100) NOT NULL,                                         --* Nom et prénom de l'apprenant
    age INTEGER NOT NULL CHECK (age > 0),                               --* Àge de l'apprenant (doit étre positif)
    evale1 NUMERIC(4, 2) NOT NULL CHECK (evale1 BETWEEN 0.0 AND 20.0),  --* Note 1
    evale2 NUMERIC(4, 2) NOT NULL CHECK (evale2 BETWEEN 0.0 AND 20.0)  --* Note 2
); 