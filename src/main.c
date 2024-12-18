#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

#include "../include/student.h"
#include "../include/utils.h"
#include "../include/database.h"    


int main(){

    //? Connexion à la base de données PostgreSQL 
    connect_to_database();

    if (conn == NULL || PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Erreur: Impossible de se connecter à la base de données : %s\n", PQerrorMessage(conn));
        return EXIT_FAILURE;
    }

    char choice;

    do{
        printSeparator();
        printf("Menu: \n");
        printf("c) Créer un nouveau dossier\n");
        printf("a) Afficher les dossier\n");
        printf("m) Calculer les moyennes\n");
        printf("r) Rechercher un dossier\n");
        printf("d) Supprimer un dossier\n");
        printf("s) Sauvegarder les dossiers\n");
        printf("l) Charger les dossiers\n");
        printf("q) Quittez\n");
        printf("Votre choix: ");
        scanf(" %c", &choice);

        switch (choice){
        case 'c': createStudent(); break;
        case 'a': displayStudents(); break;
        case 'm': calculateAverages(); break;
        case 'r': searchStudent(); break;
        case 'd': deleteStudent(); break;
        case 's': saveToFile(); break;
        case 'l': loadFromFile(); break;
        case 'q': printf("Terminaison du progrmme. Au revoir! \n"); break;
        default:  printf("Choix invalide, réesayez.\n");
        }
    } while (choice != 'q');

    //!? Déconnexion de la base de données PostgreSQL
    disconnect_from_database(); 

    
    return 0;
}