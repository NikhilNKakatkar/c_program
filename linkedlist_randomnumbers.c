#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node* *head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void writeToFile(struct node* head, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error %s.\n", filename);
        return;
    }
    while (head != NULL) {
        fprintf(fp, "%d\n", head->data);
        head = head->next;
    }
    fclose(fp);
}

void bubbleSort(struct node** head_ref) {
    int swapped, i;
    struct node* ptr1;
    struct node* lptr = NULL;

    if (*head_ref == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct Node* root = NULL;
    int numNodes, i, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

     // Generating 10 random numbers and inserting them into the tree
    printf("Random Numbers: ");
    for (i = 0; i < 10; i++) {
        num = rand() % 100;
        printf("%d ", num);
        root = insertNode(root, num);
    }
    printf("\n");


    // Open files for writing
    FILE* inorderFile = fopen("inorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");

    // Perform traversals and write output to respective files
    inorderTraversal(root, inorderFile);
    postorderTraversal(root, postorderFile);
    preorderTraversal(root, preorderFile);

    // Close files
    fclose(inorderFile);
    fclose(postorderFile);
    fclose(preorderFile);

    printf("Traversal output is written to files.\n");

    return 0;
}
