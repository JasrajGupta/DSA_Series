#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    
    stack<int> st;

    for(int i = arr.size() - 1; i>=0; i--){
        while(st.size()>0 && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            cout<<"-1"<< " ";
            
        }
        else{
            cout<<st.top()<<" ";
        }
        st.push(arr[i]);
    }


    return 0;
}