#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;
    while (j != high) {
        if (j->data < pivot) {
            swapData(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swapData(i, high);
    return i;
}

void quickSort(Node* low, Node* high) {
    if (low != high && high != nullptr && low != nullptr) {
        Node* pivot = partition(low, high);
        Node* temp = low;

        if (temp != pivot) {
            while (temp->next != pivot)
                temp = temp->next;
            quickSort(low, temp);
        }
        if (pivot->next != nullptr)
            quickSort(pivot->next, high);
    }
}

Node* getTail(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

int main() {
    Node* head = nullptr;
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 10);

    cout << "Original list: ";
    printList(head);

    Node* tail = getTail(head);
    quickSort(head, tail);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
