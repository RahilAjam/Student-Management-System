#include <stdio.h>
#include <string.h>
#include "student.h"

void updateStudent(void) {
    int id, i, found = 0;

    if (studentCount == 0) {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nEnter Student ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        while (getchar() != '\n');
        return;
    }

    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;

            while (getchar() != '\n');

            printf("Enter New Name: ");
            if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
                printf("Unable to read name!\n");
                return;
            }

            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            if (strlen(students[i].name) == 0) {
                printf("Name cannot be empty!\n");
                return;
            }

            printf("Enter New Marks: ");
            if (scanf("%f", &students[i].marks) != 1) {
                printf("Invalid marks!\n");
                while (getchar() != '\n');
                return;
            }

            if (students[i].marks < 0 || students[i].marks > 100) {
                printf("Marks must be between 0 and 100!\n");
                return;
            }

            printf("\nStudent details updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found!\n", id);
    }
}