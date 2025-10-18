// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// Author: [Your Name], [Your Student ID]
// Description: Demonstrates saving and loading a struct (Student) to/from a text file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    printf("Saving student to file...\n");
    save_student(s1, filename);  // Save student data

    printf("Loading student from file...\n");
    Student loaded = load_student(filename);  // Load student data

    printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age, loaded.gpa);

    return 0;
}

// --- Function to save a student to a file ---
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }

    // Save in the format: name age gpa
    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.gpa);

    fclose(fp);
}

// --- Function to load a student from a file ---
Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }

    // Read in the same order they were written
    if (fscanf(fp, "%s %d %f", s.name, &s.age, &s.gpa) != 3) {
        fprintf(stderr, "Error: invalid file format or missing data.\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return s;
}