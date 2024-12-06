#ifndef UTILS_H
#define UTILS_H

#include "student.h"

int     getPositiveInt(const char *message);
float   getValidFloat(const char *message);
void    freeStudentMemory(Student **students, int *studentCount);
void    printSeparator();

#endif