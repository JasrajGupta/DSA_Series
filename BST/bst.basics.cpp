#include<iostream>
#include<vector>
using namespace std;

class Node{
public: 
      int data;
      Node* left;
      Node* right;
 
      Node(int val){
        data = val;
        left = right = NULL;
      }
};
Node* insert(Node* root, int val){
    if(root == NULL){
       return new Node(val);
    }
    if(val < root->data){
    root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* bstTree(vector<int> arr){
    Node* root = NULL;
    for(int idx : arr){
       root =  insert(root, idx);
    }
    return root;
}
void preorderTraversal(Node* root){
    if(root == NULL) return;
    
    preorderTraversal(root->left);
    cout<<root->data<<" ";
    preorderTraversal(root->right);
    
}
int search(Node* root, int key){
    if(root == NULL){
        cout<<"not found"<<endl;
         return 0;
    }
    if(root->data == key){
        cout<<"key found"<<endl;
         return root->data;
    }
    if(root->data > key){
       return search(root->left, key);
    }
    else{
       return search(root->right, key);
    }
}
int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
      
    Node* root = bstTree(arr);
    int ans = search(root, 7);
    cout<<ans<<endl;
    // preorderTraversal(root);
return 0;
}
