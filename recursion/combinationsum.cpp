#include<iostream>
#include<vector>
#include<set>
using namespace std;

void combinations(vector<int> &arr, int i , int tar, set<vector<int>> &st, vector<int> &combin){
    int n = arr.size();
    
    if(i == n || tar < 0){
        return;
    }
    if(tar == 0){
        st.insert(combin);
        return;
    }
    combin.push_back(arr[i]);
    //single
    combinations(arr, i+1, tar - arr[i], st, combin);
    //multiple
    // combinations(arr, i, tar - arr[i], st, combin);
    //backtrack
    combin.pop_back();
    //exclude
    combinations(arr, i+1, tar, st, combin);

}

int main(){
    vector<int> arr = {2,5,2,1,2};
    int tar = 5;

   set<vector<int>> st;
    vector<int> combin;
    combinations(arr,0, tar, st, combin);
     for(auto vec : st){
        for(int val : vec){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;

}