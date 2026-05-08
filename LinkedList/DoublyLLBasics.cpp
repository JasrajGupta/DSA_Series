#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class DoublyList{
    Node* head; 
    Node* tail;
public: 
      DoublyList(){
        head = tail = NULL;
      }
      void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
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
            if(head != NULL){
            head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head == NULL){
            return;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
                temp->next = NULL;
                tail->prev = NULL;
                delete tail;
                tail = temp;
            }
        }
    }
    void printDl(){
        Node* temp = head;
        if(head == NULL){
            return;
        }
        while(temp != NULL){
            cout<<temp->data<<" "<<temp->prev<<" "<<temp->next<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    };

int main(){
    DoublyList li;
    li.push_front(1);
    li.push_back(2);
    li.push_back(3);
    li.pop_back();

    li.printDl();

    return 0;
    
}