#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_PATTERN_LENGTH 20

int main() {
    char lines[MAX_LINES][100];
    char pattern[MAX_PATTERN_LENGTH];
    char outputFileName[50];
    int numLines = 0;
    int patternLength = 0;
    int i, j, k;
    int found;

    while (numLines < MAX_LINES) {
        printf("Enter line %d (or 'quit' to stop): ", numLines+1);
        fgets(lines[numLines], 100, stdin);
        if (strcmp(lines[numLines], "quit\n") == 0) {
            break;
        }
        numLines++;
    }

    printf("Enter pattern to search for: ");
    fgets(pattern, MAX_PATTERN_LENGTH, stdin);
    patternLength = strlen(pattern);
    if (pattern[patternLength-1] == '\n') {
        pattern[patternLength-1] = '\0';
        patternLength--;
    }

    printf("Enter name of output file: ");
    fgets(outputFileName, 50, stdin);
    outputFileName[strlen(outputFileName)-1] = '\0';
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (i = 0; i < numLines; i++) {
        found = 0;
        for (j = 0; j < strlen(lines[i])-patternLength+1; j++) {
            for (k = 0; k < patternLength; k++) {
                if (lines[i][j+k] != pattern[k]) {
                    break;
                }
            }
            if (k == patternLength) {
                found = 1;
                break;
            }
        }
        if (found) {
            fputs(lines[i], outputFile);
        }
    }

    return 0;
}
