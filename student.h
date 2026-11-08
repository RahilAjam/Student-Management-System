#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

extern Student students[MAX_STUDENTS];
extern int studentCount;

void addStudent(void);
void displayStudents(void);
void searchStudent(void);
void deleteStudent(void);

#endif