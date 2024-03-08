#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a number into the list
void insertNumber(struct Node** head, int num) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Set the data of the new node
    newNode->data = num;

    // Link the new node to the existing list
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to print the elements of the list
void printList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Insert numbers into the list
    insertNumber(&head, 5);
    insertNumber(&head, 3);
    insertNumber(&head, 8);

    // Print the list
    printList(head);

    return 0;
}

