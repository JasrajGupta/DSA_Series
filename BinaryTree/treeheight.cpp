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
int height(Node* root){
    if(root == NULL) return 0;
    
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}
int count(Node* root){
    if(root == NULL) return 0;

    int leftCt = count(root->left);
    int rightCt = count(root->right);
    return leftCt + rightCt + 1;
}
int sum(Node* root){
    if(root == NULL) return 0;

    int ltsum = sum(root->left);
    int rtsum = sum(root->right);
    return ltsum + rtsum + root->data;
    
}
int diameter(Node* root){
    if(root == NULL) return 0;

    int lt = diameter(root->left);
    int rt = diameter(root->right);
    return lt + rt;

}
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = preorderTree(preorder);
    int Sum = diameter(root);

    int Height = height(root);
    int Count = count(root);
    
    cout<<Sum<<endl;
    cout<<Count<<endl;
}
