#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>

void reverseString(vector<char>& s){
    int st = 0, end = s.size() - 1;
    while(st<end){
        swap(s[st],s[end]);
        st++,end--;
    }
}
void reversestring(string &str){
    int st = 0, end = str.size() - 1;
    while(st<end){
        swap(str[st] , str[end]);
        st++ ,end--;
    }
    
}

int main() {
    vector<char> s = {'h','e','l','l','o','\0'};
    string str = "racecar";

   reverseString(s);
     for(char c : s){
        cout << c <<endl;
       
    }
 
      reversestring(str);
      cout<<str<<endl;
   
}


