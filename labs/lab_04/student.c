//
// Created by madarasz.hunor on 3/13/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void readStudentDetails(Student_t *pStudent) {
    printf("Enter name: ");
    fgets(pStudent->name, sizeof(pStudent->name), stdin);
    pStudent->name[strcspn(pStudent->name, "\n")] = '\0';

    printf("Enter Neptun code: ");
    fgets(pStudent->neptunCode, sizeof(pStudent->neptunCode), stdin);
    pStudent->neptunCode[strcspn(pStudent->neptunCode, "\n")] = '\0';

    printf("Enter birthplace: ");
    fgets(pStudent->birthPlace, sizeof(pStudent->birthPlace), stdin);
    pStudent->birthPlace[strcspn(pStudent->birthPlace, "\n")] = '\0';

    printf("Enter birth year: ");
    scanf("%d", &pStudent->dateOfBirth.yearOfBirth);

    printf("Enter gender (0 for Male, 1 for Female): ");
    int gender;
    scanf("%d", &gender);
    pStudent->gender = (gender == 0) ? MALE : FEMALE;

    printf("Enter exam result: ");
    scanf("%f", &pStudent->examResult);

}

void printStudent(Student_t student) {
    printf("\nName: %s\n", student.name);
    printf("Neptun Code: %s\n", student.neptunCode);
    printf("Birthplace: %s\n", student.birthPlace);
    printf("Birth Year: %d\n", student.dateOfBirth.yearOfBirth);
    printf("Gender: %s\n", (student.gender == MALE) ? "Male" : "Female");
    printf("Exam Result: %.2f\n", student.examResult);
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents = (Student_t *)malloc(numberOfStudents * sizeof(Student_t));
    if (*dpStudents == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", input);
        exit(1);
    }

    fscanf(file, "%d", numberOfStudents);  // Első sorban a diákok száma
    allocateMemoryForStudents(dpStudents, *numberOfStudents);

    for (int i = 0; i < *numberOfStudents; i++) {
        fscanf(file, " %49[^\n]", (*dpStudents)[i].name);
        fscanf(file, " %8[^\n]", (*dpStudents)[i].neptunCode);
        fscanf(file, " %25[^\n]", (*dpStudents)[i].birthPlace);
        fscanf(file, "%d", &(*dpStudents)[i].dateOfBirth.yearOfBirth);
        int gender;
        fscanf(file, "%d", &gender);
        (*dpStudents)[i].gender = (gender == 0) ? MALE : FEMALE;
        fscanf(file, "%f", &(*dpStudents)[i].examResult);
    }

    fclose(file);
}
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    FILE *file = fopen(destination, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", destination);
        exit(1);
    }

    for (int i = 0; i < numberOfStudents; i++) {
        fprintf(file, "Name: %s\n", pStudents[i].name);
        fprintf(file, "Neptun Code: %s\n", pStudents[i].neptunCode);
        fprintf(file, "Birthplace: %s\n", pStudents[i].birthPlace);
        fprintf(file, "Birth Year: %d\n", pStudents[i].dateOfBirth.yearOfBirth);
        fprintf(file, "Gender: %s\n", (pStudents[i].gender == MALE) ? "Male" : "Female");
        fprintf(file, "Exam Result: %.2f\n", pStudents[i].examResult);
    }

    fclose(file);
}

void calculatePercentageBoysGirls(Student_t **dpStudents, int numberOfStudents) {
    if (numberOfStudents == 0) {
        printf("No students available to calculate percentages.\n");
        return;
    }

    int maleCount = 0, femaleCount = 0;

    for (int i = 0; i < numberOfStudents; i++) {
        if ((*dpStudents)[i].gender == MALE) {
            maleCount++;
        } else {
            femaleCount++;
        }
    }

    float malePercentage = ((float)maleCount / numberOfStudents) * 100;
    float femalePercentage = ((float)femaleCount / numberOfStudents) * 100;

    printf("\nPercentage of Male students: %.2f%%\n", malePercentage);
    printf("Percentage of Female students: %.2f%%\n", femalePercentage);
}
void deallocate(Student_t **pStudent){
  free(*pStudent);
  *pStudent = NULL;
}
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city) {
    int found = 0;

    printf("\nStudents from %s:\n", city);
    for (int i = 0; i < numberOfStudents; i++) {
        if (strcmp(pStudents[i].birthPlace, city) == 0) {
            printStudent(pStudents[i]); // Használjuk a meglévő printStudent függvényt
            found = 1;
        }
    }

    if (!found) {
        printf("No students found from %s.\n", city);
    }
}