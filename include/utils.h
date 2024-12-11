#ifndef UTILS_H
#define UTILS_H

#include "student.h"

//? Connexion globale PostgreSQL
extern PGconn *conn; 

//* Fonction pour la gestion de la base de données
void connect_to_database();
void disconnect_from_database();  

//* Fonction utilitaires 
int     getPositiveInt(const char *message);
float   getValidFloat(const char *message);
void    printSeparator();

//* Fonction pour charger le fichier .env
void load_env_file(const char *filename, char **db_name, char **db_user, char **db_password);


#endif