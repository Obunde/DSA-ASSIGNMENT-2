#include <iostream>
#include <set>

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

Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}

void createCycle(Node* head) {
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head->next->next;
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    createCycle(head);

    Node* cycleStart = detectCycle(head);
    if (cycleStart != nullptr) {
        cout << "The cycle begins at node with value: " << cycleStart->data << endl;
    } else {
        cout << "There is no cycle in the linked list." << endl;
    }

    return 0;
}
