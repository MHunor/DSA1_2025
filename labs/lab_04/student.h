//
// Created by madarasz.hunor on 3/13/2025.
//
#ifndef STUDENT_H
#define STUDENT_H

typedef enum {
    MALE,
    FEMALE
} Gender_t;

typedef struct {
    int yearOfBirth;
} Date_t;

typedef struct {
    char name[50];
    char neptunCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    Gender_t gender;
    float examResult;
} Student_t;

void readStudentDetails(Student_t *pStudent);
void printStudent(Student_t student);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void calculatePercentageBoysGirls (Student_t **dpStudents, int
numberOfStudents);
void deallocate(Student_t **pStudent);
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city);
#endif // STUDENT_H
