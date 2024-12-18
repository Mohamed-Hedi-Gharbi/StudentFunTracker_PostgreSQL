#include <stdio.h>
#include <stdlib.h>
#include <string.h>   //! Ajouté pour strcspn, strncmp, strdup


#define MAX_LINE_LENGTH 256

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