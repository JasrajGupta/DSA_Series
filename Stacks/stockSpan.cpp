#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> prices = {5, 4, 3, 2, 1};

    vector<int> ans (prices.size(), 0);
    stack<int> st;

    for(int i = 0; i<prices.size(); i++){
        while(st.size()>0 && prices[st.top()] <= prices[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = i+1;
        }
        else{
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    for(int val : ans){
        cout<<val<<" ";
    } cout<<endl;
    return 0;
}