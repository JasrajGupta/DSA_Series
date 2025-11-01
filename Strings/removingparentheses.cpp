#include<iostream>
#include<string>
using namespace std;

string removeparentheses(string s){
    int count = 0;
    string result = "";
    for(char c : s){
        if(c == '('){
            if(count > 0)
            result += c;
            count++;
        }
        else{
            count--;
            if(count>0)
            result += c;
        }
    }
    return result;
}


int main(){
    string s = "(()())(())";
    cout<<removeparentheses(s)<<" ";
}
