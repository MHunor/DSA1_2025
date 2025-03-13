#include <stdio.h>
#include "student.h"

int main() {
    Student_t student1 = {
        "John Doe",
        "ABC12345",
        "Budapest",
        {1998},
        MALE,
        4.5
    };


    printStudent(student1);

    //Student_t student2;
    //readStudentDetails(&student2);
    //printStudent(student2);


    Student_t *students = NULL;
    int numberOfStudents;
    readAllStudentsDetails(&students, &numberOfStudents, "./be.txt");
    printAllStudents(students, numberOfStudents, "output.txt");

    calculatePercentageBoysGirls(&students, numberOfStudents);

    char city[50];
    printf("Enter the city name: ");
    fgets(city, sizeof(city), stdin);

    printStudentsFromSpecificCity(&students, numberOfStudents, city);

    return 0;
}
