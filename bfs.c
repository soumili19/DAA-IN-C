#include <stdio.h>
#include <stdbool.h>

#define MAX 6

void dfs(int startVertex, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    int stack[MAX];
    int top = -1;
    stack[++top] = startVertex;

    while (top != -1) {
        int vertex = stack[top--];

        if (!visited[vertex]) {
            printf("Visited %d\n", vertex);
            visited[vertex] = true;
        }

        for (int adjVertex = MAX - 1; adjVertex >= 0; --adjVertex) {
            if (adj[vertex][adjVertex] && !visited[adjVertex]) {
                stack[++top] = adjVertex;
            }
        }
    }
}

int main() {
    int adj[MAX][MAX];
    
    printf("Enter the adjacency matrix (%dx%d):\n", MAX, MAX);
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("DFS starting from vertex 0:\n");
    dfs(0, adj);

    return 0;
}
