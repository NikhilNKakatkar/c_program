#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function prototypes
void heapSort(int arr[], int n);
void buildMaxHeap(int arr[], int n);
void maxHeapify(int arr[], int n, int i);
void swap(int *a, int *b);
void readInputFile(char *filename, int arr[], int *n);
void writeOutputFile(char *filename, int arr[], int n);

int main() {
    int arr[MAX_SIZE], n;
    char *input_file = "Input.txt";
    char *output_file = "Output.txt";
    int x = 10; // change x to the number of elements you want to sort

    // Read input file into the array
    readInputFile(input_file, arr, &n);

    // Sort the first x elements of the array using Heap Sort
    if (x > n) x = n;
    heapSort(arr, x);

    // Write the sorted array to the output file
    writeOutputFile(output_file, arr, x);

    return 0;
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void readInputFile(char *filename, int arr[], int *n) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%d", &arr[i]) == 1) {
        i++;
    }
    *n = i;
    fclose(fp);
}

void writeOutputFile(char *filename, int arr[], int n) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

