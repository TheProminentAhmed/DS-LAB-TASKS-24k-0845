#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Transaction {
    int id;
    double amount;
    string description;
    int flag;
};

struct Node {
    Transaction data;
    Node* next;
};

class TransactionStack {
private:
    Node* top;
    int nextId;

public:
    TransactionStack() {
        top = NULL;
        nextId = 1;
    }

    void push(Transaction item) {
        Node* newNode = new Node();
        
        item.id = nextId++;
        
        if (item.amount >= 1500) {
            item.amount *= 0.70;
        } else if (item.amount >= 1000) {
            item.amount *= 0.85;
        } else if (item.amount >= 500) {
            item.amount *= 0.95;
        }

        if (item.amount >= 0) {
            item.flag = 1;
        } else {
            item.flag = 0;
        }

        if (item.description.length() > 20) {
            string shortDesc = "";
            for(int i = 0; i < 20; i++){
                shortDesc += item.description[i];
            }
            item.description = shortDesc + "...";
        }
        
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    Transaction pop() {
        if (isEmpty()) {
            cout << "empty cannot pop." << endl;
            Transaction empty = {-1, 0.0, "EMPTY", -1};
            return empty;
        }
        Node* temp = top;
        Transaction data = temp->data;
        top = top->next;
        delete temp;

        data.amount *= -1;
        data.description += " REVERSED";
        data.flag = 2;

        return data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << " currently empty." << endl;
            return;
        }
        
        Node* current = top;
        while (current != NULL) {
            cout << "ID: " << current->data.id 
                 << ", Amount: " << current->data.amount
                 << ", Desc: \"" << current->data.description << "\""
                 << ", Flag: " << current->data.flag << endl;
            current = current->next;
        }
        
    }
};

int main() {
    
    
    TransactionStack stack;

    Transaction transactions[7];
    transactions[0] = {-1, 1200, "Sale: Blue Jacket", -1};
    transactions[1] = {-1, 450, "Sale: Cotton Socks", -1};
    transactions[2] = {-1, -300, "Refund: Defective Shirt", -1};
    transactions[3] = {-1, 1700, "Sale: Leather Jacket", -1};
    transactions[4] = {-1, 800, "Sale: Nice T-Shirt", -1};
    transactions[5] = {-1, -150, "Refund: Wrong Size Shoes", -1};
    transactions[6] = {-1, 2200, "Sale: Premium Quality Handbag for Ladies", -1};

    srand(time(0)); 

    for (int i = 0; i < 4; i++) {
        int idx = rand() % 7;
        stack.push(transactions[idx]);
    }

    stack.display();
    
    Transaction popped = stack.pop();
    if (popped.id != -1) {
        cout << "\nPopped and Reversed Transaction Details:" << endl;
        cout << " > ID: " << popped.id << ", New Amount: " << popped.amount 
             << ", Desc \"" << popped.description << "\""
             << ", New Flag: " << popped.flag << endl;
    }

    cout << "\nFinal stack state:" << endl;
    stack.display();
    
    
    
    return 0;
}

