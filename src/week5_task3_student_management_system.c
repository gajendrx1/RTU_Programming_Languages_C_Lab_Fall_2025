// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// Author: [Your Name], [Your Student ID]
// Description: A simple student management system that loads/saves student data from a text file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing data from file
    count = load_students(students);
    printf("%d student(s) loaded from %s.\n", count, DATA_FILE);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                printf("Data saved. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// --- Load student records from file ---
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        // File may not exist yet — not an error
        printf("No existing data found. Starting with an empty list.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%49s %d %f", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }

    fclose(fp);
    return count;
}

// --- Save student records to file ---
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }

    fclose(fp);
}

// --- Add a new student ---
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Student list is full.\n");
        return;
    }

    Student s;
    printf("Enter name: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    getchar(); // clear newline

    arr[*count] = s;
    (*count)++;

    printf("Student added successfully!\n");
}

// --- List all students ---
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %-15s | ID: %d | GPA: %.2f\n",
               i + 1, arr[i].name, arr[i].id, arr[i].gpa);
    }
}