#include <stdio.h>
#include <limits.h>
#define N 4 
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int graph[N][N], int mask, int pos, int dp[N][1 << N]) {
    if (mask == (1 << N) - 1) {
        return graph[pos][0];
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int result = INT_MAX;
    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) == 0) {
            result = min(result, graph[pos][i] + tsp(graph, mask | (1 << i), i, dp));
        }
    }
    return dp[pos][mask] = result;
}
int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[N][1 << N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }
    int result = tsp(graph, 1, 0, dp);
    printf("Minimum cost for Travelling Salesman Problem: %d\n", result);
    return 0;
}

