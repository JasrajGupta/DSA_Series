#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void topView(Node* root){
    queue<pair<Node* , int>>q;
    map<int, int>m;

    q.push({root, 0});

    while(q.size()>0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }
        if(curr->left != NULL){
            q.push({curr->left, currHD - 1});
        }
        if(curr->right != NULL){
            q.push({curr->right, currHD + 1});
        }

} 
        for(auto it : m){
            cout<<it.second<<" ";
        }
        cout<<endl;
}

void bottomView(Node* root){
    queue<pair<Node* , int>>q;
    map<int, int>m;

    q.push({root, 0});
    while(q.size()>0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }
        else if(m.find(currHD) != m.end()){
            m[currHD] = curr->data;
        }
       
        if(curr->left != NULL){
            q.push({curr->left, currHD - 1});
        }
        if(curr->right != NULL){
            q.push({curr->right, currHD + 1});
        }
    
}
        for(auto it : m){
            cout<<it.second<<" ";
        }
}
void kLevel(Node* root, int k){
    queue<pair<Node*, int>>q;

    q.push({root, 1});
    while(q.size() > 0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(currHD == k){
            cout<<curr->data<<" ";
        }
        if(curr->left != NULL){
            q.push({curr->left, currHD + 1});
        }
        if(curr->right != NULL){
            q.push({curr->right, currHD + 1});
        }
    }
}
void KthLevel(Node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
    cout<<root->data<<" ";
   }
   KthLevel(root->left, k-1);
   KthLevel(root->right, k-1);
   

}
int main(){
    vector<int> preorder = {1, 2, 4,-1, -1, 5,-1, -1, 3, 6, -1, -1, 7, -1, -1};
    
    Node* root = preorderTree(preorder);
    KthLevel(root, 1);
    return 0;
}