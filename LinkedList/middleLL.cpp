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
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<" "<<"NULL"<<endl;
    }
    int pos(){
        Node* temp = head;
        int i = 0; 
        while(temp != NULL){
            temp = temp -> next;
            i++;
        }
        return (i/2) + 1;
    }
    void middleLL(int pos){
        Node* temp = head;
        if(pos<0){
            cout<<"invalid position";
            return ;
        }
        for(int i = 0; i<pos-1; i++){
            temp = temp -> next;
        }
        cout<<"middleLL is : "<<temp->data;
    }
    void middleLL2(){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"middle LL is : "<<slow->data<<endl;
    }

};
int main(){
    List li;
    // li.push_front(5);
    li.push_front(4);
    li.push_front(6);
    li.push_front(2);
    li.push_front(1);
    li.printLL();
    // int val = li.pos();
    // li.middleLL(val);
    li.middleLL2();
    return 0;
}