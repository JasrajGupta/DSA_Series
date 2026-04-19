#include<iostream>
using namespace std;
#include<vector>

void printSubsets(vector<int> &arr, vector<int> ans, int i){
    if(i == arr.size()){
        for(int val : ans){
            cout<<val<<" ";
            // cout<<i<<" ";
        }
        cout<<endl;
         return;
    }
   
    //include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);
    
    //bactrack
    ans.pop_back();

    //include
    printSubsets(arr, ans, i+1);
}

int main(){
    vector<int> arr = {1, 2, 2};
    vector<int> ans;

    printSubsets(arr, ans, 0);
    return 0;
}