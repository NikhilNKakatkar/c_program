#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void randomize_list(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    srand(time(NULL)); // seed the random number generator with the current time
    for (int i = 0; i < count; i++) {
        int j = rand() % count;
        current = *head;
        for (int k = 0; k < j; k++) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *head = current->next;
        }
        current->next = NULL;
        prev = current;
        while (prev->next != NULL) {
            prev = prev->next;
        }
        prev->next = current;
    }
}

int main() {
    Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }
    printf("Reversed list: ");
    print_list(head);



    return 0;
}
