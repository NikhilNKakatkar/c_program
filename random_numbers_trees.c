#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Structure for a tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the tree
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to traverse the tree in in-order and write to file
void inorderTraversal(TreeNode* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

// Function to traverse the tree in post-order and write to file
void postorderTraversal(TreeNode* root, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

// Function to traverse the tree in pre-order and write to file
void preorderTraversal(TreeNode* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

int main() {
    int i, n, num;
    TreeNode* root = NULL;

    // Get the number of random numbers to generate
    printf("Enter the number of random numbers: ");
    scanf("%d", &n);

    // Generate and display random numbers
    printf("Random numbers: ");
    srand(time(0)); // to generate every time different numbers
    for (i = 0; i < n; i++) {
        num = rand() % 1000; // Generate random number between 0 and 999

        printf("%d ", num);
        root = insert(root, num); // Insert the number into the tree
    }

    // Open files for writing
    FILE* inorderFile = fopen("inorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");

    // Check if file opening succeeded
    if (inorderFile == NULL || postorderFile == NULL || preorderFile == NULL) {
        printf("Failed to open files.\n");
        exit(1);
    }

    // Perform tree traversals and write to files

    inorderTraversal(root, inorderFile);
    postorderTraversal(root, postorderFile);
    preorderTraversal(root, preorderFile);
    // Close the files
    fclose(inorderFile);
    fclose(postorderFile);
    fclose(preorderFile);

printf("\nCheck the respective files for traversal output.\n");

    return 0;
}

