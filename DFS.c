#include <stdio.h>

#define MAX 6
//dfs//
void dfs(int start, int adj[MAX][MAX], int visited[MAX]) {
  int stack[MAX];
  int top = -1;
	int neighbor;
  visited[start] = 1;
  stack[++top] = start;

  while (top != -1) {
    int current = stack[top--];
    printf("%c ", current + 65); 

    // Iterate through neighbors and push unvisited ones onto the stack
    for ( neighbor = 0; neighbor < MAX; neighbor++) {
      if (adj[current][neighbor] && visited[neighbor] == 0) {
        visited[neighbor] = 1; // Mark as visited
        stack[++top] = neighbor;
      }
    }
  }
}
//main//
int main() {
  int adj[MAX][MAX],i,j;
  int visited[MAX] = {0}; // Initialize visited array with all 0s (unvisited)

  printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
  for ( i = 0; i < MAX; i++) {
    for ( j = 0; j < MAX; j++) {
      scanf("%d", &adj[i][j]);
    }
  }

  dfs(0, adj, visited); // Start DFS from node 0

  return 0;
}


