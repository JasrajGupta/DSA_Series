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
int static idx = -1;
Node* preorderTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    
    root->left = preorderTree(preorder);
    root->right = preorderTree(preorder);

    return root;

}
void preorderBefore(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorderBefore(root->left);
    preorderBefore(root->right);
}
int transformSum(Node* root){
    
    if(root == NULL) return 0;
    
    int lt = transformSum(root->left);
    int rt = transformSum(root->right);
    root->data += lt + rt;
    
    return root->data;
    
    
}

void preorderAfter(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorderAfter(root->left);
    preorderAfter(root->right);
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4 , -1, -1, 5, -1, -1};

    Node* root = preorderTree(preorder);
       
    preorderBefore(root);
    transformSum(root);
    preorderAfter(root);
    
    return 0;
}