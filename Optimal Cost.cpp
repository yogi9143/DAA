#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function prototype
int compare(const void *a, const void *b);

int findOptimalCost(int values[], int n);

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    int values[n];
    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    int optimalCost = findOptimalCost(values, n);
    printf("Optimal Cost: %d\n", optimalCost);
    return 0;
}

int findOptimalCost(int values[], int n) {
    qsort(values, n, sizeof(int), compare);
    int optimalCost = 0;
    for (int i = 0; i < n - 1; i++) {
        int pairSum = values[i] + values[i + 1];
        optimalCost += pairSum;
        values[i + 1] = pairSum;
    }
    return optimalCost;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

