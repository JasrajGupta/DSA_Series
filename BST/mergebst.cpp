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
Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int val : arr){
        root = insert(root, val);
    }
    return root;
}
void inorder(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);

}
Node* buildBstFromSorted(vector<int> ans, int st, int end){
    if(st>end){
        return NULL;
    }
    
    int mid = st + (end - st)/2;
    Node* root = new Node(ans[mid]);
    root->left = buildBstFromSorted(ans, st, mid - 1);
    root->right = buildBstFromSorted(ans, mid + 1, end);

    return root;
}
Node* merge(Node* root1, Node* root2){
    vector<int> arr1, arr2;

   
    inorder(root1,arr1);
    inorder(root2,arr2);

    vector<int> ans;

    int i = 0, j = 0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }
    return buildBstFromSorted(ans, 0, ans.size() - 1);
}

int main(){
    vector<int> arr1 = {1, 3, 5, 8, 10};
    vector<int> arr2 = {0, 2, 4};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = merge(root1, root2);

    vector<int> seq;
    inorder(root, seq);
    for(int val : seq){
        cout<<val<<" ";
    }
    cout<<endl;



    return 0;
}