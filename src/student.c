#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

#include "../include/student.h"
#include "../include/utils.h"
#include "../include/database.h"


//TODO: Ajouter un étudiant dans la base de données PostgreSQL
void createStudent(){
    char name[100];
    int age;
    float evale1, evale2;

    printf("Nom et Prénom: ");
    scanf(" %[^\n]", name);
    age     = getPositiveInt("Âge: ");
    evale1  = getValidFloat("Note 1: ");
    evale2  = getValidFloat("Note 2: ");

    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO students (name, age, evale1, evale2) VALUES ('%s', %d, %.2f, %.2f)",
             name, age, evale1, evale2);
    
    PGresult *res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Erreur lors de l'ajout: %s\n", PQerrorMessage(conn));
    } else{
        printf("Dossier créé avec succée !\n");
    }
    PQclear(res);
}


//TODO: Afficher les étudiants depuis la base de données PostgreSQL
void displayStudents() {
    PGresult *res = PQexec(conn, "SELECT * FROM students");

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        fprintf(stderr, "Erreur d'affichage: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    

    //? En-tête du tableau
    printf("================================================================================\n");
    printf("| %-3s | %-25s | %-3s | %-10s | %-10s |\n", 
           "N°", "Nom et Prénom", "Âge", "Eval Num 1", "Eval Num 2");
    printf("================================================================================\n");

    //? Contenu du tableau
    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++){
        printf("| %-2s | %-24s | %-3s | %-10s | %-10s |\n",
                PQgetvalue(res, i, 0),      //* id
                PQgetvalue(res, i, 1),      //* name
                PQgetvalue(res, i, 2),      //* age
                PQgetvalue(res, i, 3),      //* note 1 
                PQgetvalue(res, i, 4));      //* note 2
    }
    printf("================================================================================\n");

    PQclear(res);
}



//TODO: Calculer la moyenne des étudiants 
void calculateAverages(){
    PGresult *res = PQexec(conn, "SELECT name, evale1, evale2 FROM students");

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        fprintf(stderr, "Erreur lors du calcul des moyennes: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    
    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++){
        const char *name    = PQgetvalue(res, i, 0);
        float note1         = atof(PQgetvalue(res, i, 1));
        float note2         = atof(PQgetvalue(res, i, 2));
        float moyenne       = (note1 * 0.4) + (note2 * 0.6);
        printf("Moyenne générale de l'apprenant (%s): %.2f\n", name, moyenne);
    }
    PQclear(res);
}


//TODO: Rechercher un étudiant par nom dans la base de données PostgreSQL
void searchStudent() {
    char searchName[100];
    printf("Saisissez le nom de l'apprenant à rechercher: ");
    scanf(" %[^\n]", searchName);

    char query[256];
    snprintf(query, sizeof(query),
             "SELECT * FROM students WHERE name ILIKE '%%%s%%'", searchName);


    PGresult *res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        fprintf(stderr, "Erreur lors de la recherche: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    
    int rows = PQntuples(res);
    if (rows == 0){
        printf("Aucun apparenant trouvé pour le nom '%s'.\n", searchName);
    } else{
        //? Affichage des résultats
        printf("==========================================================================\n");
        printf("| %-2s | %-25s | %-3s | %-10s | %-10s |\n",
               "ID", "Nom et Prénom", "Âge", "Eval Num 1", "Eval Num 2");
        printf("==========================================================================\n");

        for (int i = 0; i < rows; i++){
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



//TODO: Supprimer un étudiant de la base de données PostgreSQL
void deleteStudent(){
    int studentId = getPositiveInt("Saisissez le numéro du dossier à supprimer: ");
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM students WHERE id = %d", studentId);

    PGresult *res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        fprintf(stderr, "Erreur lors de la suppression : %s\n", PQerrorMessage(conn));
    } else{
        printf("Dossier supprimer avec succées.\n");
    }
    PQclear(res);
}