#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

void find_pattern(char **lines, int num_lines);

int main() {
    char *lines[MAX_LINES];
    int num_lines = 0;
    char input[MAX_LENGTH];

    printf("Enter up to %d lines of text (type 'done' to finish):\n", MAX_LINES);

    while (num_lines < MAX_LINES) {
        printf("> ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "done") == 0) {
            break;
        }

        lines[num_lines] = (char*) malloc(strlen(input) + 1);
        strcpy(lines[num_lines], input);
        num_lines++;
    }

    find_pattern(lines, num_lines);
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return 0;
}

void find_pattern(char **lines, int num_lines) {
    int pattern_length = 0;
    char *pattern = NULL;
    for (int length = 1; length <= MAX_LENGTH; length++) {
        for (int start = 0; start <= MAX_LENGTH - length; start++) {
            int pattern_found = 1;
            for (int i = 0; i < num_lines; i++) {
                if (strstr(lines[i] + start, pattern) == NULL) {
                    pattern_found = 0;
                    break;
                }
            }
            if (pattern_found) {
                pattern_length = length;
                pattern = lines[0] + start;
                break;
            }
        }
        if (pattern != NULL) {
            break;
        }
    }

    if (pattern_length == 0) {
        printf("No pattern found.\n");
    } else {
        printf("Pattern found: %.*s\n", pattern_length, pattern);
    }
}
