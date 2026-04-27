#include<iostream>
using namespace std;

class Node {    //syntax
    public: 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{           //head and tail nodes 
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){  //logic
        
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return; 
        }
        else{
            newNode -> next = head; 
            head = newNode;
        }
    }
    void push_back(int val){

        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            cout<<temp->next<<" ";
            temp = temp->next;
        }
        cout<<" "<<"NULL"<<endl;
    }
};




int main(){
    List li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_back(4);
    li.printLL();
    return 0;

}