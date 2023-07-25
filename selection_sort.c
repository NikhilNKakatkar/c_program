#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void selection_sort(int arr[], int n);
void read_file(int arr[], int* n, char* filename);
void write_file(int arr[], int n, char* filename);

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    read_file(arr, &n, "Input.txt");

    // sort the first X numbers in the array
    selection_sort(arr, n);

    write_file(arr, n, "Output.txt");

    return 0;
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;

    // iterate over the array
    for (i = 0; i < n - 1; i++) {
        // find the minimum element in the unsorted part of the array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // swap the minimum element with the current element
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void read_file(int arr[], int* n, char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // read the numbers into the array
    while (fscanf(fp, "%d", &arr[*n]) != EOF) {
        (*n)++;
    }

    fclose(fp);
}

void write_file(int arr[], int n, char* filename) {
    FILE* fp;
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // write the sorted numbers to the file
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}
