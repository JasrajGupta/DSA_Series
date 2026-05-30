#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
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
int maxWidth(Node* root){
    queue<pair<Node*, int>>q;
    int k = 0;
    if(root == NULL) return 0;

    q.push({root , 0});
    while(q.size() > 0){
        Node* curr = q.front().first;
        int currWD = q.front().second;

        q.pop();

        k = max(k, currWD);
        
        if(curr->left != NULL){
            q.push({curr->left, currWD + 1});
        }
        if(curr->right != NULL){
            q.push({curr->right, currWD + 1});
        }
    }
    return pow(2, k);

}


int main(){
    vector<int> preorder = {1, 2, 4,-1, -1, 5,-1, -1, 3, 6, -1, -1, 7, 8, -1, -1, 9, -1, -1};

    Node* root = preorderTree(preorder);
    cout<<maxWidth(root)<<endl;
    return 0;
}