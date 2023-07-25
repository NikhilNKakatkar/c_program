#include <stdio.h>
#include <stdlib.h>

// Structure for a node in AVL tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to calculate the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return the new root
    return x;
}

// Function to left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in AVL tree
        return node;

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Check the balance factor and balance the tree if needed
    int balance = getBalance(node);

    // Left Left case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to find the minimum value node in a given AVL tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Find the leftmost leaf node
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
struct Node* deleteNode(struct Node* root, int data) {
    // Perform the normal BST deletion
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found
        // Case 1: No child or only one child
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp;

            free(temp);
        } else {
            // Case 2: Two children
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Check the balance factor and balance the tree if needed
    int balance = getBalance(root);

    // Left Left case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree and write to a file
void inorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

// Function to perform a pre-order traversal of the AVL tree and write to a file
void preorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

// Function to perform a post-order traversal of the AVL tree and write to a file
void postorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

// Function to create and write the output file for a traversal
void createOutputFile(struct Node* root, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating output file!\n");
        return;
    }

    if (root == NULL) {
        fclose(file);
        return;
    }

    if (filename[0] == 'i') {
        fprintf(file, "In-order traversal: ");
        inorderTraversal(root, file);
    } else if (filename[0] == 'p') {
        fprintf(file, "Pre-order traversal: ");
        preorderTraversal(root, file);
    } else if (filename[0] == 'o') {
        fprintf(file, "Post-order traversal: ");
        postorderTraversal(root, file);
    } else {
        printf("Invalid filename provided!\n");
        fclose(file);
        return;
    }

    fprintf(file, "\n");
    fclose(file);
}

int main() {
    struct Node* root = NULL;

    // Example usage
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Create output files for traversals
    createOutputFile(root, "inorder.txt");
    createOutputFile(root, "preorder.txt");
    createOutputFile(root, "postorder.txt");

    // Delete a node
    root = deleteNode(root, 30);

    // Create output files for traversals after deletion
    createOutputFile(root, "inorder_after_deletion.txt");


    return 0;
}

