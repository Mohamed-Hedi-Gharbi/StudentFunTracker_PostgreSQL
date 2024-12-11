#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

#include "../include/student.h"
#include "../include/utils.h"

//TODO: Sauvegarder les étudiants dans la base de données PostgreSQL
void saveToFile() {
    //? La sauvegarde est automatiquement gérée par la base de données.
    printf("Les données des étudiants sont déjà sauvegardées dans la base de données PostgreSQL.\n");
}


//TODO: Charger les étudiants depuis la base de données PostgreSQL
void loadFromFile() {
    PGresult *res = PQexec(conn, "SELECT * FROM students");

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Erreur lors du chargement des données : %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);
    if (rows == 0) {
        printf("Aucun dossier trouvé dans la base de données.\n");
    } else {
        printf("Dossiers chargés depuis la base de données :\n");
        //? Affichage des données chargées
        printf("==========================================================================\n");
        printf("| %-2s | %-25s | %-3s | %-10s | %-10s |\n",
               "ID", "Nom et Prénom", "Âge", "Eval Num 1", "Eval Num 2");
        printf("==========================================================================\n");

        for (int i = 0; i < rows; i++) {
            printf("| %-2s | %-24s | %-3s | %-10s | %-10s |\n",
                   PQgetvalue(res, i, 0),  //* id
                   PQgetvalue(res, i, 1),  //* name
                   PQgetvalue(res, i, 2),  //* age
                   PQgetvalue(res, i, 3),  //* note1
                   PQgetvalue(res, i, 4)); //* note2
        }
        printf("==========================================================================\n");
    }

    PQclear(res);
}