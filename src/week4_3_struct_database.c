/*
 * week4_3_struct_database.c
 * Author: Gajendra Singh
 * Student ID: 241ADB084
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student data
    for (int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%49s", students[i].name);
        printf("Enter id for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }

    // Display all student records
    printf("\n%-20s %-10s %-10s\n", "Name", "ID", "Grade");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].id, students[i].grade);
    }

    // Free allocated memory
    free(students);
    return 0;
}
