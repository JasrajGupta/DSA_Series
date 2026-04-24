#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalin(string s){
    string s1 = s;
    reverse(s1.begin(), s1.end());

    return s1 == s;
}


void getAllParts(string s,vector<string> &partitions){
    if(s.size() == 0){
        for(string val : partitions){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 0; i<s.size(); i++){
        string part = s.substr(0, i+1);
        if(isPalin(part)){
            partitions.push_back(part);
            getAllParts(s.substr(i+1), partitions);
            partitions.pop_back();
        }
    }
}

int main(){
    string s = {"aab"};

    vector<string> partitions;

    getAllParts(s, partitions);

    return 0;
}
