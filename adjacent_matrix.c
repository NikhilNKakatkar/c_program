#include <stdio.h>

#define MAX_NODES 100

int adjacencyMatrix[MAX_NODES][MAX_NODES];

// Function to initialize the adjacency matrix
void initializeMatrix(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge between two nodes
void addEdge(int start, int end) {
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1; // If it's an undirected graph
}

// Function to display the adjacency matrix
void displayMatrix(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numNodes, numEdges, i;
    int startNode, endNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    initializeMatrix(numNodes);

    for (i = 0; i < numEdges; i++) {
        printf("Enter the start and end node of edge %d: ", i + 1);
        scanf("%d %d", &startNode, &endNode);
        addEdge(startNode, endNode);
    }

    printf("\nAdjacency Matrix:\n");
    displayMatrix(numNodes);

    return 0;
}

