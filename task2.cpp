#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int v){
        data=v;
        next=NULL;
    }
};

class List{
public:
    Node* head;
    List(){
        head=NULL;
    }
    void add(int v){
        Node* n=new Node(v);
        if(head==NULL){
            head=n;
            return;
        }
        Node* t=head;
        while(t->next!=NULL) t=t->next;
        t->next=n;
    }
    void show(){
        Node* t=head;
        while(t!=NULL){
            cout<<t->data;
            if(t->next!=NULL) cout<<"->";
            t=t->next;
        }
        cout<<endl;
    }
    void sort(){
        if(head==NULL) return;
        bool sw;
        Node* p;
        Node* last=NULL;
        do{
            sw=false;
            p=head;
            while(p->next!=last){
                if(p->data > p->next->data){
                    int tmp=p->data;
                    p->data=p->next->data;
                    p->next->data=tmp;
                    sw=true;
                }
                p=p->next;
            }
            last=p;
        }while(sw);
    }
    void mix(List& l2){
        Node* p1=head;
        Node* p2=l2.head;
        Node* n1,*n2;
        while(p1!=NULL && p2!=NULL){
            n1=p1->next;
            n2=p2->next;
            p1->next=p2;
            p2->next=n1;
            p1=n1;
            p2=n2;
        }
        l2.head=p2;
    }
};

int main(){
    List l1,l2;

    l1.add(1);
    l1.add(3);
    l1.add(2);

    l2.add(4);
    l2.add(5);
    l2.add(6);
    l2.add(7);
    l2.add(8);

    cout<<"Before sort L1: ";
    l1.show();
    l1.sort();
    cout<<"After sort L1: ";
    l1.show();

    cout<<"Before mix L1: ";
    l1.show();
    cout<<"Before mix L2: ";
    l2.show();

    l1.mix(l2);

    cout<<"After mix L1: ";
    l1.show();
    cout<<"Left L2: ";
    l2.show();
}
