#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void addNode(Node** head, string name, int score) {
    Node* newNode = new Node{name, score, nullptr};
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}


int getMax(Node* head) {
    int maxVal = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->score > maxVal)
            maxVal = temp->score;
        temp = temp->next;
    }
    return maxVal;
}


int getDigit(int number, int place) {
    int result = 0;
    for (int i = 0; i < place - 1; i++)
        number /= 10;
    result = number % 10;
    return result;
}


void radixSort(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr)
        return;

    int maxVal = getMax(*head);
    int place = 1;

    while (maxVal > 0) {
        Node* buckets[10] = {nullptr};
        Node* tails[10] = {nullptr};

        Node* curr = *head;
        while (curr != nullptr) {
            int digit = (curr->score / place) % 10;

            Node* nextNode = curr->next;
            curr->next = nullptr;

            if (buckets[digit] == nullptr) {
                buckets[digit] = curr;
                tails[digit] = curr;
            } else {
                tails[digit]->next = curr;
                tails[digit] = curr;
            }
            curr = nextNode;
        }

        Node* newHead = nullptr;
        Node* newTail = nullptr;
        for (int i = 0; i < 10; i++) {
            if (buckets[i] != nullptr) {
                if (newHead == nullptr) {
                    newHead = buckets[i];
                    newTail = tails[i];
                } else {
                    newTail->next = buckets[i];
                    newTail = tails[i];
                }
            }
        }
        *head = newHead;
        place *= 10;
        maxVal /= 10;
    }
}


void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name << " " << temp->score << endl;
        temp = temp->next;
    }
}


int linkedListToArray(Node* head, int arr[], Node* ptrs[]) {
    int count = 0;
    while (head != nullptr) {
        arr[count] = head->score;
        ptrs[count] = head;
        head = head->next;
        count++;
    }
    return count;
}


int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


void deleteRecord(Node** head, string name, int score) {
    Node* temp = *head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->name == name && temp->score == score) {
            if (prev == nullptr)
                *head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            cout << "\nRecord deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\nRecord not found.\n";
}


int main() {
    Node* head = nullptr;
    
    addNode(&head, "Ali", 90);
    addNode(&head, "Azmeer", 60);
    addNode(&head, "Sarah", 70);
    addNode(&head, "Sohnali", 30);
    addNode(&head, "Ahmed", 20);

    cout << "Before Sorting:\n";
    display(head);

    radixSort(&head);

    cout << "\nAfter Sorting (Ascending):\n";
    display(head);


    int scores[10000];
    Node* ptrs[10000];
    int size = linkedListToArray(head, scores, ptrs);

    string name;
    int score;
    cout << "\nEnter student name to delete: ";
    cin >> name;
    cout << "Enter student score: ";
    cin >> score;


    int pos = binarySearch(scores, size, score);
    if (pos != -1) {
        deleteRecord(&head, name, score);
    } else {
        cout << "\nRecord not found.\n";
    }

    cout << "\nUpdated List:\n";
    display(head);

    return 0;
}
