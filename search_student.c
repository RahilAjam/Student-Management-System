#include <stdio.h>
#include "student.h"

void searchStudent(void) {

    // Check whether records exist
    if (studentCount == 0) {
        printf("\nNo student records available!\n");
        return;
    }

    int searchID;
    int found = 0;

    printf("\nEnter Student ID to search: ");

    if (scanf("%d", &searchID) != 1) {
        printf("Invalid Student ID!\n");

        while (getchar() != '\n' && !feof(stdin));

        return;
    }

    // Search for the student
    for (int i = 0; i < studentCount; i++) {

        if (students[i].id == searchID) {

            printf("\n================================\n");
            printf("         STUDENT FOUND\n");
            printf("================================\n");

            printf("Student ID    : %d\n",
                   students[i].id);

            printf("Student Name  : %s\n",
                   students[i].name);

            printf("Student Marks : %.2f\n",
                   students[i].marks);

            printf("================================\n");

            found = 1;
            break;
        }
    }

    // Display result
    if (!found) {
        printf("\nStudent with ID %d not found!\n",
               searchID);
    }
}