#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

//container with most of water problem

int containerWithMostWater(vector<int>& height){
    
    int maxWater = 0 , rp = height.size() - 1 , lp = 0;
    while(lp<rp){
        int w = rp -lp;
        int ht = min(height[lp], height[rp]);
        int currWater = w * ht;
        maxWater = max(currWater, maxWater);
    
        height[lp]<height[rp] ? lp++ : rp--;
    }
return maxWater;
}

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<containerWithMostWater(height)<<endl;
}