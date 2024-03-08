#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compareItems(const void *a, const void *b) {
    double ratioA = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratioB = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    if (ratioA > ratioB) return -1;
    if (ratioA < ratioB) return 1;
    return 0;
}
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compareItems);
    int currentWeight = 0;
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double remainingWeight = capacity - currentWeight;
            totalValue += (remainingWeight / items[i].weight) * items[i].value;
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);
    return 0;
}

