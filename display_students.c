#include <stdio.h>
#include "student.h"

Student students[MAX_STUDENTS] = {
    {101, "Rahil", 85.0},
    {102, "Arjun", 90.0},
    {103, "Priya", 78.0}
};

int studentCount = 3;

int main(void) {
    displayStudents();
    return 0;
}