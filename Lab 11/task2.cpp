#include <iostream>
using namespace std;

struct DictNode {
    string key;
    string value;
    DictNode* next;
    DictNode(string k,string v) {
        key=k;
        value=v;
        next=NULL;
    }
};

class Dictionary {
    DictNode* table[100];
public:
    Dictionary() {
        for(int i=0;i<100;i++) table[i]=NULL;
    }
    int hashFunc(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++) sum+=s[i];
        return sum%100;
    }
    void Add_Record(string k,string v) {
        int idx = hashFunc(k);
        DictNode* n = new DictNode(k,v);
        n->next = table[idx];
        table[idx] = n;
    }
    void Word_Search(string k) {
        int idx = hashFunc(k);
        DictNode* t = table[idx];
        while(t) {
            if(t->key==k) {
                cout<<"search key "<<k<<": "<<t->value<<endl;
                return;
            }
            t=t->next;
        }
        cout<<"Error: Word Not Found"<<endl;
    }
    void Delete_Record(string k) {
        int idx = hashFunc(k);
        DictNode* t = table[idx];
        DictNode* p = NULL;
        while(t) {
            if(t->key==k) {
                if(p) p->next=t->next;
                else table[idx]=t->next;
                delete t;
                cout<<"key "<<k<<" deleted successfully !"<<endl;
                return;
            }
            p=t;
            t=t->next;
        }
    }
    void Print_Dictionary() {
        for(int i=0;i<100;i++) {
            DictNode* t=table[i];
            if(t) {
                cout<<"index "<<i<<": ";
                while(t) {
                    cout<<"("<<t->key<<", "<<t->value<<") ";
                    t=t->next;
                }
                cout<<endl;
            }
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("AB","FASTNU");
    d.Add_Record("CD","CS");
    d.Word_Search("AB");
    d.Delete_Record("EF");
    d.Print_Dictionary();
}
