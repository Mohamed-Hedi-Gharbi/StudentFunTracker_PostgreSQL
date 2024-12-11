#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>



//? Connexion global à PostgreSQL
PGconn *conn = NULL;

//TODO: Fonction pour se connecter à la base de données PostgreSQL
void connect_to_database(){
    conn = PQconnectdb("dbname=cft_db user=postgres password=postgres");

    if (PQstatus(conn) != CONNECTION_OK){
        fprintf(stderr, "Erreur de connexion: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        exit(EXIT_FAILURE);
    }

    printf("Connexion à la base de données PostgreSQL réussie.\n");
} 

//TODO: Fonction pour fermer la connexion à la base de données PostgreSQL
void disconnect_from_database(){
    if (conn != NULL){
        PQfinish(conn);
        printf("Déconnexion de la base de données PostgreSQL réussie.\n");
    }
} 

//TODO: Fonction pour obtenir un entier positif de l'utilisateur 
int getPositiveInt(const char *message){
    int value;
    do{
        printf("%s", message);
        scanf("%d", &value);
        if (value <= 0){
            printf("Erreur: veuillez entrer un entier positif.\n");
        }
    } while (value <= 0);
    return value;
}

//TODO: Fonction pour obtenir un flottant valide entre 0.0 et 20.0
float getValidFloat(const char *message){
    float value;
    do{
        printf("%s", message);
        scanf("%f", &value);
        if (value < 0.0 || value > 20.0){
            printf("Erreur: veuillez entrer une valeur entre 0.0 et 20.0.\n");
        }
        
    } while (value < 0.0 || value > 20.0);
    return value;
}




void printSeparator(){
    printf("\n--------------------------------------------------------------\n");
}