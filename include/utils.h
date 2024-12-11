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

#endif