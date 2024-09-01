#include <stdio.h>

// Function to implement Floyd-Warshall's algorithm
void floydWarshall(int graph[][100], int n) {
    int i, j, k;

    // Apply the algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][k] != 0 && graph[k][j] != 0 && (graph[i][j] == 0 || graph[i][j] > graph[i][k] + graph[k][j])) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

// Function to display the shortest-path weight matrix
void displayShortestPathMatrix(int graph[][100], int n) {
    printf("Shortest Path Weight Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to display the intermediate vertices on the shortest path
void displayIntermediateVertices(int graph[][100], int u, int v) {
    if (graph[u][v] == 0) {
        printf("No intermediate vertices between %d and %d\n", u + 1, v + 1);
        return;
    }

    printf("Intermediate Vertices from %d to %d: %d", u + 1, v + 1, u + 1);

 while (u != v && graph[u][v] != -1) {
    printf(" -> %d", v + 1);
    v = graph[u][v];
}

    printf("\n");
}


int main() {
    int n;

    // Read the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[100][100];

    // Read the graph from the input file
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Apply Floyd-Warshall's algorithm
    floydWarshall(graph, n);

    // Display the shortest-path weight matrix
    displayShortestPathMatrix(graph, n);

    // Example: Display intermediate vertices between vertices u and v
    int u, v;
    printf("Enter the source and destination vertices (u v): ");
    scanf("%d %d", &u, &v);

    // Ensure valid vertices
    if (u < 1 || u > n || v < 1 || v > n) {
        printf("Invalid vertices.\n");
    } else {
        displayIntermediateVertices(graph, u - 1, v - 1);
    }

   // return 0;
}