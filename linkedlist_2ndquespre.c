#include <stdio.h>
#include <stdlib.h>

/* Define the node struct */
struct Node {
    int data;
    struct Node* next;
};
void insert(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to add a new node to the list */
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to swap two nodes */
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/* Bubble sort algorithm */
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/* Function to print the list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Function to write the list to a file */
void writeListToFile(struct Node* node) {
    FILE *file = fopen("Output.txt", "w");
    while (node != NULL) {
        fprintf(file, "%d ", node->data);
        node = node->next;
    }
    fclose(file);
}


void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
/* Main function */
int main() {
        int n, p, q, i, num;
    struct node* head = NULL;
    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the range (P, Q): ");
    scanf("%d %d", &p, &q);

    for (i = 0; i < n; i++) {
        num = rand() % (q - p + 1) + p;
        insert(&head, num);
    }

    printf("Randomly generated numbers: ");
    printList(head);

    FILE *file = fopen("input.txt", "r");
    int x;
    while (fscanf(file, "%d", &x) != EOF) {
        push(&head, x);
    }
    fclose(file);

    bubbleSort(head);

    printf("Sorted list: ");
    printList(head);
    printf("\n");

    writeListToFile(head);

    return 0;
}
