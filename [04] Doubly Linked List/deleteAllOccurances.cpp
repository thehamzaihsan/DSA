#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void deleteAllOccurrences(Node** head, int key) {
    if (*head == nullptr) {
        return;
    }

    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr) {
        if (current->data == key) {
            next = current->next;
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            current = next;
        } else {
            current = current->next;
        }
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    // Add random nodes
    Node* node1 = new Node;
    node1->data = 5;
    node1->prev = nullptr;
    node1->next = nullptr;

    Node* node2 = new Node;
    node2->data = 2;
    node2->prev = nullptr;
    node2->next = nullptr;

    Node* node3 = new Node;
    node3->data = 5;
    node3->prev = nullptr;
    node3->next = nullptr;

    // Connect the nodes
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    // Set head to the first node
    head = node1;
    std::cout << "Original list: ";
    printList(head);

    int key = 5;
    deleteAllOccurrences(&head, key);

    std::cout << "List after deleting all occurrences of " << key << ": ";
    printList(head);

    return 0;
}