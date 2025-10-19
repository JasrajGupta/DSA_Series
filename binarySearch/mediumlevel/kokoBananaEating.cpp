#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>
#include <cmath>

bool isPossible(vector<int>& pile, int n, int h, int k){
   int totalhours = 0;
   for(int i = 0; i<n; i++){
    totalhours += ceil((double)pile[i] / k);
    if(totalhours > h){
        return false;
    }
    
}
return totalhours <=h;
}
int minEatingSpeed(vector<int>& pile, int n, int h){
    sort(pile.begin(), pile.end());
    if(n>h){
        return false;
    }
   int st = 1, end = pile[n], mid;
   int ans = -1;
   while(st<=end){
    mid = st + (end - st)/2;
    if(isPossible(pile, n, h, mid)){
        ans = mid;
        end = mid - 1; 
    }
    else{
        st = mid + 1;
    }


}
return ans;
}
int main() {
    vector<int> pile = {3, 6 , 7, 11};
    cout<<minEatingSpeed(pile, 4, 8)<<endl;
}