#include <stdio.h>
#include <stdbool.h>
#define V 4 // Number of vertices in the graph
#define COLORS 3 // Number of colors available
void printSolution(int color[], int n) {
    printf("Vertex colors:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    }
}
bool isSafe(int graph[V][V], int v, int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}
bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize colors to 0 (unassigned)
    }
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }
    printSolution(color, V);
    return true;
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int numColors = COLORS;
    if (!graphColoring(graph, numColors)) {
        printf("Graph coloring is not possible with %d colors.\n", numColors);
    }
    return 0;
}

