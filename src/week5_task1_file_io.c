// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// Author: [Your Name], [Your Student ID]
// Description: Demonstrates basic file writing and reading using fprintf() and fgets().

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    // --- Writing to file ---
    printf("Writing lines to %s...\n", filename);

    fp = fopen(filename, "w"); // 1. Open file for writing
    if (fp == NULL) {          // 2. Check if file opened successfully
        perror("Error opening file for writing");
        return 1;
    }

    // 3. Write lines of text
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "File handling is fun!\n");

    fclose(fp); // 4. Close the file

    // --- Reading from file ---
    printf("Reading contents:\n");

    fp = fopen(filename, "r"); // 5. Open file again for reading
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    int line_count = 0;
    // 6. Read and print each line using fgets()
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    fclose(fp); // 7. Close the file
    printf("\nTotal lines read: %d\n", line_count);

    return 0;
}