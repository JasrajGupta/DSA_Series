#include<iostream>
#include<vector>
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
    int searching(int key){
        int i = 0;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == key){
                cout<<"key is found at index : "<<i<<" "<<temp->data<<endl;
                return 1;
            }
            temp = temp ->next;
            i++;
        }
        cout<<"element is not found In LL"<<endl;
        return 0; 
    }

    int reverse(){
        Node* st = head;
        Node* end = tail;
        while(st<end){
            swap(st->data, end->data);
            
            st++;
            end--;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<" "<<"NULL"<<endl;
        return 0;
    }
    int isReverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* Next = NULL;
        while(curr!=NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= Next;
        }
        prev;
        cout<<"NULL"<<"<-";
        while(prev!=NULL){
            cout<<prev->data<<"<-";
            // cout<<prev->next<<" ";
            prev = prev->next;

        }
        cout<<endl;
    
    } 


};




int main(){
    List li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.printLL();
    li.isReverse();
    return 0;

}