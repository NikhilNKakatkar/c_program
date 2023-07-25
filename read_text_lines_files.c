#include <stdio.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

void readLines(char lines[MAX_LINES][MAX_LENGTH]);
void writeLines(char lines[MAX_LINES][MAX_LENGTH]);
int getLength(char line[MAX_LENGTH]);

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    readLines(lines);
    writeLines(lines);

    FILE *file = fopen("lines.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    int max_length = 0, max_index = -1;
    char line[MAX_LENGTH];
    int line_count = 0;
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        int length = getLength(line);
        if (length > max_length) {
            max_length = length;
            max_index = line_count;
        }
        line_count++;
    }

    fclose(file);

    if (max_index != -1) {
        printf("The longest line is: %s\n", lines[max_index]);
    } else {
        printf("No lines were entered.\n");
    }

    return 0;
}

void readLines(char lines[MAX_LINES][MAX_LENGTH]) {
    printf("Enter up to %d lines (maximum length %d characters per line):\n", MAX_LINES, MAX_LENGTH - 1);
    for (int i = 0; i < MAX_LINES; i++) {
        fgets(lines[i], MAX_LENGTH, stdin);
    }
}

void writeLines(char lines[MAX_LINES][MAX_LENGTH]) {
    FILE *file = fopen("lines.txt", "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i < MAX_LINES; i++) {
        fprintf(file, "%s", lines[i]);
    }

    fclose(file);
}

int getLength(char line[MAX_LENGTH]) {
    int length = 0;
    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
        length++;
    }
    return length;
}
