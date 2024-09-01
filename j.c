#include <stdio.h>
#include <limits.h>

#define V 5

void dijkstra(int graph[V][V], int start) {
    int distances[V];
    int visited[V];
    int i, j, min, next;

    for(i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    distances[start - 1] = 0;

    for(i = 0; i < V - 1; i++) {
        min = INT_MAX;

        for(j = 0; j < V; j++) {
            if(!visited[j] && distances[j] < min) {
                min = distances[j];
                next = j;
            }
        }

        visited[next] = 1;

        for(j = 0; j < V; j++) {
            if(!visited[j] && graph[next][j] && distances[next] != INT_MAX && 
               distances[next] + graph[next][j] < distances[j]) {
                distances[j] = distances[next] + graph[next][j];
            }
        }
    }

    printf("Source Destination Cost Path\n");
    for(i = 0; i < V; i++) {
        if(i == start - 1) {
            printf("%d %d 0 -\n", start, i + 1);
        } else {
            printf("%d %d %d %d->%d\n", start, i + 1, distances[i], start, i + 1);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {3, 0, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int numVertices, startVertex;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the Source Vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, startVertex);

    return 0;
}
