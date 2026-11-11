#include <stdio.h>
#include "student.h"

void deleteStudent(void) {

    int deleteID;
    int found = 0;
    int i, j;

    // Check whether student records exist
    if (studentCount == 0) {
        printf("\nNo student records available to delete!\n");
        return;
    }

    // Get Student ID
    printf("\nEnter Student ID to delete: ");

    if (scanf("%d", &deleteID) != 1) {
        printf("Invalid Student ID!\n");

        while (getchar() != '\n' && !feof(stdin));

        return;
    }

    // Search for the student
    for (i = 0; i < studentCount; i++) {

        if (students[i].id == deleteID) {

            found = 1;

            printf("\nStudent Found:\n");
            printf("Student ID   : %d\n", students[i].id);
            printf("Student Name : %s\n", students[i].name);
            printf("Student Marks: %.2f\n", students[i].marks);

            // Shift remaining records to the left
            for (j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }

            // Reduce student count
            studentCount--;

            printf("\nStudent deleted successfully!\n");

            break;
        }
    }

    // If student ID does not exist
    if (!found) {
        printf("\nStudent with ID %d not found!\n", deleteID);
    }
}
