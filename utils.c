#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


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


void freeStudentMemory(Student **students, int *studentCount){
    //! Libère la mémoire allouée pour le tableau de étudiants
    free(*students);                    
    *students       = NULL;
    *studentCount   = 0;
    printf("Mémoire librée avec succés.\n");   
}


void printSeparator(){
    printf("\n--------------------------------------------------------------\n");
}