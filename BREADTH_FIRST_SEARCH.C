#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear)
        return -1;
    vertex = queue[front];
    front++;
    return vertex;
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int i, vertex;
    
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal starting from vertex %d: ", start);
    while ((vertex = dequeue()) != -1) {
        printf("%d ", vertex);

        for (i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int graph[MAX][MAX], n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(graph, n, start);
    return 0;
}

OUTPUT :
Enter number of vertices: 4
Enter adjacency matrix (4 x 4):
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex (0 to 3): 0
BFS Traversal starting from vertex 0: 0 1 2 3 
