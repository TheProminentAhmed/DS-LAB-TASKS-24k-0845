#include<iostream>
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class linkedlist{
private:
    Node* head;
public:
    linkedlist(){
        head=NULL;
    }
    void insertatend(int val){
        Node* n=new Node(val);
        if(head==NULL){
            head=n;
            return;
        }
        Node* t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=n;
        n->prev=t;
    }
    void deletehead(){
        if(head==NULL) return;
        Node* t=head;
        head=head->next;
        if(head!=NULL) head->prev=NULL;
        delete t;
    }
    void deleteTail(){
        if(head==NULL) return;
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* t=head;
        while(t->next!=NULL) t=t->next;
        t->prev->next=NULL;
        delete t;
    }
    void deleteAtPosition(int pos){
        if(head==NULL) return;
        if(pos==1){
            deletehead();
            return;
        }
        Node* t=head;
        int c=1;
        while(t!=NULL && c<pos){
            t=t->next;
            c++;
        }
        if(t==NULL) return;
        if(t->next!=NULL) t->next->prev=t->prev;
        if(t->prev!=NULL) t->prev->next=t->next;
        delete t;
    }

    Node* reverseRecursive(Node* node){
        if(node==NULL) return NULL;
        Node* temp=node->next;
        node->next=node->prev;
        node->prev=temp;
        if(node->prev==NULL){
            head=node;
            return node;
        }
        return reverseRecursive(node->prev);
    }
    void reverse(){
        reverseRecursive(head);
    }
    void display(){
        Node* t=head;
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    linkedlist d;
    d.insertatend(10);
    d.insertatend(20);
    d.insertatend(30);
    d.insertatend(40);
    d.insertatend(50);

    cout<<"Original List: ";
    d.display();

    d.deletehead();
    cout<<"After deleting front: ";
    d.display();

    d.deleteTail();
    cout<<"After deleting last: ";
    d.display();

    d.deleteAtPosition(2);
    cout<<"After deleting position 2: ";
    d.display();

    d.reverse();
    cout<<"After recursive reverse: ";
    d.display();
}
