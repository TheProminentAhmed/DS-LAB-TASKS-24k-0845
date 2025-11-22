#include <iostream>
#include <list>
using namespace std;

class Hash {
    list<pair<int,string>> table[10];
public:
    int hashFunc(int k) { return k%10; }
    void insert(int k,string v) {
        table[hashFunc(k)].push_back({k,v});
    }
    void removeKey(int k) {
        int idx = hashFunc(k);
        for(auto it=table[idx].begin(); it!=table[idx].end(); it++) {
            if(it->first==k) {
                table[idx].erase(it);
                break;
            }
        }
    }
    void search(int k) {
        int idx = hashFunc(k);
        for(auto &p: table[idx]) {
            if(p.first==k) {
                cout<<p.second<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
    }
    void display() {
        for(int i=0;i<10;i++) {
            for(auto &p: table[i]) {
                cout<<"("<<p.first<<","<<p.second<<") ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Hash h;
    h.insert(1,"A");
    h.insert(2,"B");
    h.insert(12,"C");
    h.display();
}
