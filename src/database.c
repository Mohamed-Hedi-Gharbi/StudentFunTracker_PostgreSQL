#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/database.h"



//? Connexion global à PostgreSQL
PGconn *conn = NULL;

//TODO: Fonction pour charger les variables d'environnement depuis un fichier .env
void load_env_file(const char *filename, char **db_name, char **db_user, char **db_password) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier .env");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;  //! Supprimer le caractère de nouvelle ligne

        if (strncmp(line, "DB_NAME=", 8) == 0) {
            *db_name = strdup(line + 8);
        } else if (strncmp(line, "DB_USER=", 8) == 0) {
            *db_user = strdup(line + 8);
        } else if (strncmp(line, "DB_PASSWORD=", 12) == 0) {
            *db_password = strdup(line + 12);
        }
    }

    fclose(file);
}

//TODO: Fonction pour se connecter à la base de données
void connect_to_database() {
    char *db_name = NULL, *db_user = NULL, *db_password = NULL;

    //? Charger les variables d'environnement
    load_env_file(".env", &db_name, &db_user, &db_password);

    //? Construire la chaîne de connexion
    char conninfo[256];
    snprintf(conninfo, sizeof(conninfo), "dbname=%s user=%s password=%s", db_name, db_user, db_password);

    //? Initialiser la connexion
    conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erreur de connexion à la base de données : %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        conn = NULL; //* Marquer la connexion comme nulle
    } else {
        printf("Connexion réussie à la base de données.\n");
    }

    //? Libérer les variables allouées dynamiquement
    free(db_name);
    free(db_user);
    free(db_password);
}


//TODO: Fonction pour fermer la connexion à la base de données PostgreSQL
void disconnect_from_database(){
    if (conn != NULL){
        PQfinish(conn);
        printf("Déconnexion de la base de données PostgreSQL réussie.\n");
    }
} 
