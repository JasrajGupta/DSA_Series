#include<iostream>
#include<vector>
#include<queue>
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
void preorderTraversal(Node* root){
    if(root == NULL) return ;

    cout<<root->data<<endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(Node* root){
    if(root == NULL) return;
     
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}
void levelorder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        
        cout<<curr->data<<" ";

        if(curr->left != NULL){
        q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;

}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = preorderTree(preorder);

    levelorder(root);
    cout<<endl;


    return 0;
}