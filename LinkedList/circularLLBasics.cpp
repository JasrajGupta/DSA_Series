#include<iostream>
using namespace std;

class Node{
public: 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head = tail = NULL;
    }
    void push_front(int val){
    Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            newNode->next = head; 
            head = newNode;
            tail->next = head;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                tail->next = head;
            }
            else{
                tail->next = NULL;
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            }
        }
    void pop_front(){
        Node* temp = head;
        if(head == NULL)return;
        else{
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back(){
        Node* temp = tail;
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
         tail = prev;
            tail->next = head;
            temp ->next = NULL;
            delete temp;
    }

    void printCl(){
        if(head == NULL) return;
        cout<<head->data<<"->";
        Node* temp = head->next;
        while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
};


int main(){
    CircularList cl;
    cl.push_front(2);
    cl.push_front(1);
    cl.push_back(3);
    cl.push_back(4);
    // cl.pop_front();
    cl.pop_back();
    cl.printCl();
    return 0;
}