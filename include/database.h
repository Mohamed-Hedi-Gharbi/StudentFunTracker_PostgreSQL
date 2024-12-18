#ifndef DATABASE_H
#define DATABASE_H


//? Bibliothèque pour PostgreSQL 
#include <libpq-fe.h>

//* Connexion global PostgreSQL
extern PGconn *conn;


//* Fonction pour la gestion de la base de données
void load_env_file(const char *filename, char **db_name, char **db_user, char **db_password);
void connect_to_database();
void disconnect_from_database();  


#endif