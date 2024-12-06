#ifndef STUDENT_H
#define STUDENT_H

typedef struct{
    char name[100];
    int age;
    float eval1;
    float eval2;
} Student;


//* Tableau dynamique et compteur d'étudiants
extern Student *students;
extern int studentCount;

//* Prototypes des fonctions
void createStudent();
void displayStudents();
void calculateAverages();
void searchStudent();
void deleteStudent();
void saveToFile();
void loadFromFile(); 


#endif