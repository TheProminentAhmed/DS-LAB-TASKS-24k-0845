#include <iostream>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
    Node(string k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
    Node* table[10];
public:
    HashTable() {
        for(int i=0;i<10;i++) table[i]=NULL;
    }
    int hashFunc(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++) sum+=s[i];
        return sum%10;
    }
    void insert(string k,string v) {
        int idx = hashFunc(k);
        Node* n = new Node(k,v);
        n->next = table[idx];
        table[idx] = n;
    }
    void display() {
        for(int i=0;i<10;i++) {
            Node* t=table[i];
            while(t) {
                cout<<t->key<<" "<<t->value<<endl;
                t=t->next;
            }
        }
    }
};

int main() {
    HashTable myhash;
    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");
    myhash.display();
}
