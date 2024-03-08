#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

void containerLoader(int items[], int numItems, int containers[], int numContainers) {
    int containerIndex = 0;

    for (int i = 0; i < numItems; i++) {
        if (containers[containerIndex] >= items[i]) {
            // Pack the item into the current container
            containers[containerIndex] -= items[i];
            printf("Item %d fits into Container %d\n", i + 1, containerIndex + 1);
        } else {
            // Move to the next container if the current one is full
            containerIndex++;
            if (containerIndex >= numContainers) {
                printf("Not enough containers to pack all items.\n");
                return;
            }
            // Pack the item into the new container
            containers[containerIndex] -= items[i];
            printf("Item %d fits into Container %d\n", i + 1, containerIndex + 1);
        }
    }

    printf("All items are packed successfully.\n");
}

int main() {
    int numItems, numContainers;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    int items[MAX_ITEMS];

    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    int containers[MAX_CONTAINERS];

    printf("Enter the sizes of the containers:\n");
    for (int i = 0; i < numContainers; i++) {
        scanf("%d", &containers[i]);
    }

    containerLoader(items, numItems, containers, numContainers);

    return 0;
}

