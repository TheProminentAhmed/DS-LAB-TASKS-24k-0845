#include <iostream>
#include <string>

using namespace std;

struct Order {
    int id;
    string item;
    int quantity;
};

#define QUEUE_MAX_SIZE 10

class Queue {
private:
    Order arr[QUEUE_MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == QUEUE_MAX_SIZE - 1) || (rear == (front - 1) % (QUEUE_MAX_SIZE -1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(Order order) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == QUEUE_MAX_SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = order;
        cout << "Added Order: " << order.id << endl;
    }

    Order dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            Order empty = {-1, "EMPTY", 0};
            return empty;
        }

        Order order = arr[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == QUEUE_MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        
        cout << "Processed Order: " << order.id << endl;
        return order;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending orders" << endl;
            return;
        }
        cout << "\nPending Orders:" << endl;
        int i = front;
        while(true){
            cout << "ID: " << arr[i].id 
                 << ", Item: " << arr[i].item 
                 << ", Qty: " << arr[i].quantity << endl;
            if (i == rear) break;
            i = (i + 1) % QUEUE_MAX_SIZE;
        }
        
    }
};

int main() {
    Queue q;
    
    q.enqueue({101, "Pizza", 2});
    q.enqueue({102, "Burger", 3});
    q.enqueue({103, "Pasta", 1});
    
    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue({104, "Salad", 1});
    q.display();
    
    return 0;
}

