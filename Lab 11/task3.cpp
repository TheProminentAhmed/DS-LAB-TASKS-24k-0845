#include <iostream>
using namespace std;

struct Node {
    int key;
    string value;
    Node* next;
    Node(int k,string v) {
        key=k;
        value=v;
        next=NULL;
    }
};

class Hash {
    Node* table[10];
public:
    Hash() {
        for(int i=0;i<10;i++) table[i]=NULL;
    }

    int hashFunc(int k) { return k%10; }

    void insertKey(int k,string v) {
        int idx = hashFunc(k);
        Node* n = new Node(k,v);
        n->next = table[idx];
        table[idx] = n;
    }

    void deleteKey(int k) {
        int idx = hashFunc(k);
        Node* t = table[idx];
        Node* p = NULL;
        while(t) {
            if(t->key==k) {
                if(p) p->next = t->next;
                else table[idx] = t->next;
                delete t;
                return;
            }
            p = t;
            t = t->next;
        }
    }

    void searchKey(int k) {
        int idx = hashFunc(k);
        Node* t = table[idx];
        while(t) {
            if(t->key==k) {
                cout<<t->value<<endl;
                return;
            }
            t=t->next;
        }
        cout<<"Not found"<<endl;
    }

    void display() {
        for(int i=0;i<10;i++) {
            Node* t = table[i];
            while(t) {
                cout<<"("<<t->key<<","<<t->value<<") ";
                t=t->next;
            }
            cout<<endl;
        }
    }
};

int main() {
    Hash h;
    h.insertKey(1,"A");
    h.insertKey(2,"B");
    h.insertKey(12,"C");
    h.searchKey(12);
    h.deleteKey(2);
    h.display();
}
