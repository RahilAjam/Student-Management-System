
#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(void) {

    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent limit reached!\n");
        return;
    }

    int id;

    printf("\nEnter Student ID: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");

        while (getchar() != '\n');

        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < studentCount; i++) {

        if (students[i].id == id) {
            printf("\nStudent ID already exists!\n");
            return;
        }
    }

    students[studentCount].id = id;

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter Student Name: ");

    if (fgets(students[studentCount].name,
              sizeof(students[studentCount].name), stdin) == NULL) {
        printf("Unable to read name!\n");
        return;
    }

    students[studentCount].name[
        strcspn(students[studentCount].name, "\n")
    ] = '\0';

    if (strlen(students[studentCount].name) == 0) {
        printf("Name cannot be empty!\n");
        return;
    }

    printf("Enter Student Marks: ");

    if (scanf("%f", &students[studentCount].marks) != 1) {
        printf("Invalid marks!\n");

        while (getchar() != '\n');

        return;
    }

    if (students[studentCount].marks < 0 ||
        students[studentCount].marks > 100) {

        printf("Marks must be between 0 and 100!\n");
        return;
    }

    studentCount++;

    printf("\nStudent added successfully!\n");
}
