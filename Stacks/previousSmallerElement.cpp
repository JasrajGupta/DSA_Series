#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr = {5, 4, 3, 2,1};
    stack<int> st;
    
    for(int i = 0; i<arr.size(); i++){
        while(st.size() > 0 && arr[i] <= st.top()){
            st.pop();
        }
        if(st.empty()){
            cout<<"-1"<<" ";
        }
        else{
            cout<<st.top()<<" ";
        }
        st.push(arr[i]);
    }
    return 0;
}