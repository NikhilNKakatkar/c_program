#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define P 0
#define Q 1000

void generate_input()
{
    FILE *file = fopen("Input.txt", "w");
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        exit(EXIT_FAILURE);
    }\

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int num = rand() % (Q - P + 1) + P;
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void heapify(int arr[], int n, int i)
{
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
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

