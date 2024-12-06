#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "utils.h"


Student *students = NULL;
int studentCount  = 0;

void createStudent(){
    students = realloc(students, (studentCount + 1) * sizeof(Student));
    if (!students){
        printf("Erreur d'allocation mémoire.\n");
        return;
    }

    printf("Nom et Prénom: ");
    //! %[^\n] Permet de  lit une ligne de texte entrée par l'utilisateur et la stocke dans students[studentCount].name jusqu'a l'utilisateur clique sur entrée
    scanf(" %[^\n]", students[studentCount].name);
    students[studentCount].age      = getPositiveInt("Âge: ");
    students[studentCount].eval1    = getValidFloat("Note 1: ");
    students[studentCount].eval2    = getValidFloat("Note 2: ");
    studentCount++;
    printf("Dossier crée avec succés !\n");
}


void displayStudents() {
    if (studentCount == 0) {
        printf("Aucun dossier à afficher.\n");
        return;
    }

    //? En-tête du tableau
    printf("================================================================================\n");
    printf("| %-3s | %-25s | %-3s | %-10s | %-10s |\n", 
           "N°", "Nom et Prénom", "Âge", "Eval Num 1", "Eval Num 2");
    printf("================================================================================\n");

    //? Contenu du tableau
    for (int i = 0; i < studentCount; i++) {
        printf("| %-2d | %-24s | %-3d | %-10.2f | %-10.2f |\n", 
               i + 1, students[i].name, students[i].age, students[i].eval1, students[i].eval2);
    }
    printf("================================================================================\n");
}



void calculateAverages(){
    if (studentCount == 0){
        printf("Acun dossier à traiter. \n");
        return;
    }
    for (int i = 0; i < studentCount; i++){
        float moyenne = (students[i].eval1 * 0.4) + (students[i].eval2 * 0.6);
        printf("Moyenne générale de l'apprenant %d (%s): %.2f\n", i + 1, students[i].name, moyenne);
    }  
}

void searchStudent() {
    if (studentCount == 0) {
        printf("Aucun dossier disponible.\n");
        return;
    }

    char searchName[100];
    printf("Saisissez le nom de l'apprenant à rechercher: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    //? Affichage de l'en-tête uniquement si un résultat est trouvé
    for (int i = 0; i < studentCount; i++) {
        if (strstr(students[i].name, searchName) != NULL) {
            if (!found) {
                //? Affichage de l'en-tête avec des bordures alignées
                printf("\n==========================================================================\n");
                printf("| %-3s | %-25s | %-3s | %-10s | %-10s |\n", 
                       "N°", "Nom et Prénom", "Âge", "Eval Num 1", "Eval Num 2");
                printf("==========================================================================\n");
            }
            //? Ajustez les tailles des colonnes pour bien aligner les données
            printf("| %-2d | %-24s | %-3d | %-10.2f | %-10.2f |\n", 
                   i + 1, students[i].name, students[i].age, students[i].eval1, students[i].eval2);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé pour le nom '%s'.\n", searchName);
    }
    printf("==========================================================================\n");
}


void deleteStudent(){
    if (studentCount == 0){
        printf("Aucun dossier disponible à supprimer. \n");
        return;
    }
    int studentId = getPositiveInt("Saisissez le numéro du dossier à supprimer: ");
    if (studentId < 1 || studentId > studentCount){
        printf("Erreur: Aucun dossier portant ce numéro.\n");
        return;
    }
    for (int i = studentId - 1; i < studentCount - 1; i++){
        students[i] = students[i + 1];
    }
    studentCount--;
    students = realloc(students, studentCount * sizeof(Student));
    printf("Dossier supprimer avec succés.\n");
}