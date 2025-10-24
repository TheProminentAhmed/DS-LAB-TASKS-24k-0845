#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char val) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = val;
    }

    char pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    
    Stack s;
    string original = "BORROWROB";
    string reversed = "";

    for (int i = 0; i < original.length(); i++) {
        s.push(original[i]);
    }

    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    cout << "Original String: " << original << endl;
    cout << "Reversed String: " << reversed << endl;

    if (original== reversed) {
        cout << "is a palindrome" << endl;
    } else {
        cout << " not a palindrome" << endl;
    }
    

    return 0;
}

