#include<iostream>
using namespace std;

class Node{
public:    
    Node* next;
    int data;

    Node(int val){
        data = val;
        next = NULL;
    }

};
class List{
    Node* head;
    Node* tail;
public: 
    List(){
        head = tail = NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
           head = tail = newNode;
           return ;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == NULL){
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void printQueue(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<" "<<"NULL"<<endl;
    }


};

int main(){
    List li;
    li.push(1);
    li.push(2);
    li.push(3);
     li.printQueue();
    li.pop_front();
     li.pop_front();
      li.pop_front();
       li.printQueue();
      li.push(4);
    li.printQueue();
}