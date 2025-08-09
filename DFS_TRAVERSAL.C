#include <stdio.h>
#define MAX 100
int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int vertex) {
    int i;
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}
int main() {
    int graph[MAX][MAX];
    int n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex %d: ", start);
    dfs(graph, n, start);
    printf("\n");
    return 0;
}

OUTPUT :
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter starting vertex: 0
DFS Traversal starting from vertex 0: 0 1 3 4 2
