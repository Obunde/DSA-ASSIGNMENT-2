#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* previous = NULL;
    struct Node* current_node = head;
    struct Node* next_node = NULL;

    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous;
        previous = current_node;
        current_node = next_node;
    }

    return previous;
}

int main() {
    // Creating an empty list
    struct Node* head = NULL;

    // Inserting nodes at the beginning of the list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Printing original list
    printf("Original List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    // Reversing the list
    head = reverseList(head);

    // Printing reversed list
    printf("Reversed List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    // Freeing memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
