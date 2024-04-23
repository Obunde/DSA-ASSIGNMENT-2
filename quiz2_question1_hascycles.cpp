#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle detected
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    // Create a cycle for testing
    head->next->next->next->next->next->next = head->next->next;

    bool hasCycle = detectCycle(head);
    if (hasCycle) {
        cout << "There is a cycle in the linked list." << endl;
    } else {
        cout << "There is no cycle in the linked list." << endl;
    }

    return 0;
}
