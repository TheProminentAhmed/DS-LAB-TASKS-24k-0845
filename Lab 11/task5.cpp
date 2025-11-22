#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    bool used;
    bool deleted;
    Student() {
        used=false;
        deleted=false;
        roll=-1;
        name="";
    }
};

class StudentHashTable {
    Student table[15];
public:
    int hashFunc(int r) { return r%15; }

    void InsertRecord(int roll,string name) {
        int idx = hashFunc(roll);
        for(int i=0;i<15;i++) {
            int probe = (idx + i*i)%15;
            if(!table[probe].used || table[probe].deleted) {
                table[probe].roll = roll;
                table[probe].name = name;
                table[probe].used = true;
                table[probe].deleted = false;
                return;
            }
        }
    }

    void SearchRecord(int roll) {
        int idx = hashFunc(roll);
        for(int i=0;i<15;i++) {
            int probe = (idx + i*i)%15;
            if(table[probe].used && table[probe].roll==roll) {
                cout<<table[probe].name<<endl;
                return;
            }
        }
        cout<<"Record not found"<<endl;
    }
};

int main() {
    StudentHashTable h;
    h.InsertRecord(101,"Ali");
    h.InsertRecord(116,"Sara");
    h.InsertRecord(131,"Ahmed");

    h.SearchRecord(116);
    h.SearchRecord(500);
}
