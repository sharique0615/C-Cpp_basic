#include <stdio.h>
#define INF 99999
void readGraph(char *filename, int graph[100][100], int n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
}
void floydWarshall(int graph[100][100], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
void findShortestPath(int graph[100][100], int source, int destination)
{
    printf("\nShortest Path from vertex %d to vertex %d: %d", source, destination, source);
    int current = source;
    while (current != destination)
    {
        int next = graph[current - 1][destination - 1];
        printf(" --> %d", next);
        current = next;
    }
    printf("\n");
}
void printShortestPathMatrix(int graph[100][100], int n)
{
    printf("Shortest Path Weight Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int graph[100][100];
    int n, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &source, &destination);
    readGraph("fle.txt", graph, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }
    floydWarshall(graph, n);
    printShortestPathMatrix(graph, n);
    findShortestPath(graph, source, destination);
    return 0;
}
