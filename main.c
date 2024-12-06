#include <stdio.h>
#include "student.h"
#include "utils.h"


int main(){
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
    
    freeStudentMemory(&students, &studentCount);
    return 0;
}