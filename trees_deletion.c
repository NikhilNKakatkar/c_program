#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int key, FILE* insertFile) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key, insertFile);
    else if (key > root->key)
        root->right = insert(root->right, key, insertFile);

    fprintf(insertFile, "%d ", key); // Write inserted elements to file
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key, FILE* deleteFile) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key, deleteFile);
    else if (key > root->key)
        root->right = deleteNode(root->right, key, deleteFile);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            fprintf(deleteFile, "%d ", key); // Write deleted elements to file
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            fprintf(deleteFile, "%d ", key); // Write deleted elements to file
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key, deleteFile);
    }
    return root;
}

// Function to perform inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    FILE* insertFile = fopen("inserted_elements.txt", "w");
    FILE* deleteFile = fopen("deleted_elements.txt", "w");

    // Inserting elements
    root = insert(root, 50, insertFile);
    root = insert(root, 30, insertFile);
    root = insert(root, 20, insertFile);
    root = insert(root, 40, insertFile);
    root = insert(root, 70, insertFile);
    root = insert(root, 60, insertFile);
    root = insert(root, 80, insertFile);

    // Deleting elements
    root = deleteNode(root, 20, deleteFile);
    root = deleteNode(root, 30, deleteFile);
    root = deleteNode(root, 50, deleteFile);

    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    fclose(insertFile);
    fclose(deleteFile);
    return 0;
}
