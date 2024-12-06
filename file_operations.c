#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

void saveToFile(){
    FILE *file = fopen("students.txt", "w");
    if (!file){
        printf("Erreur: Impossible d'ouvrir le fichier pour la sauvegarde.\n");
        return;
    }

    fprintf(file, "==========================================================================\n");
    //TODO: En-tête au fichier pour plus de clarté
    fprintf(file, "| %-3s | %-25s | %-3s | %-10s | %-8s |\n", "N°", "Nom et Prénom", "Âge", "Note Eval 1", "Note Eval 2");   
    fprintf(file, "==========================================================================\n");

    //TODO: Sauvegarde des étudiants avec des espacements pour aligner les colonnes
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "| %-2d | %-24s | %-3d | %-11.2f | %-11.2f |\n", 
                i + 1, students[i].name, students[i].age, students[i].eval1, students[i].eval2);
    }
    fprintf(file, "==========================================================================\n");

    fclose(file);
    printf("Dossiers sauvegardés avec succés.\n");
}


void loadFromFile(){
    FILE *file = fopen("students.txt", "r");
    if (!file){
        printf("Erreur: Aucun fichier à charger.\n");
        return;
    }
    students = NULL;
    studentCount = 0;

    char line[200];
    while (fgets(line, sizeof(line), file)){
        students = realloc(students, (studentCount + 1) * sizeof(Student));
        sscanf(line, "%[^;];%d;%f;%f",
                students[studentCount].name,
                &students[studentCount].age,
                &students[studentCount].eval1, 
                &students[studentCount].eval2);
        studentCount++;
    }
    fclose(file);
    printf("Dossier chargés avec succés. \n");
}