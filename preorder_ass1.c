#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform pre-order traversal of the binary tree
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Process the current node
    printf("%d ", root->data);

    // Traverse the left subtree
    preOrderTraversal(root->left);

    // Traverse the right subtree
    preOrderTraversal(root->right);
}
// Function to count the number of nodes in the binary tree
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // Count the current node and nodes in its left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
        // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform pre-order traversal and display the elements
    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Count the number of nodes and display the result
    int nodeCount = countNodes(root);
    printf("Number of nodes in the binary tree: %d\n", nodeCount);

    return 0;
}
