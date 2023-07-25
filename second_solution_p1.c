#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000 // Maximum number of integers to sort

// Function to perform bubble sort on an array of integers
/*void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}*/

// Main function
int main() {
    FILE *input_file, *output_file;
    int numbers[MAX_NUMBERS], n, i, x;

    // Open input file
    input_file = fopen("Input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read in numbers from input file
    i = 0;
    while (fscanf(input_file, "%d", &numbers[i]) != EOF) {
        i++;
        if (i >= MAX_NUMBERS) {
            break;
        }
    }
    n = i; // Save number of integers read

    // Prompt user for X value
    printf("Enter the number of integers to sort: ");
    scanf("%d", &x);
    if (x > n) {
        printf("Error: X is greater than the number of integers in the file\n");
        return 1;
    }

    // Sort the first X numbers using bubble sort
   // bubble_sort(numbers, x);

    // Open output file
    output_file = fopen("Output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write sorted numbers to output file
    for (i = 0; i < x; i++) {
        fprintf(output_file, "%d\n", numbers[i]);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Sorted numbers written to Output.txt\n");
    return 0;
}
