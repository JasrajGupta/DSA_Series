#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>


int majorityElement(vector<int>& nums) {
    int ans = 0, freq= 0; 

    for(int i = 0; i<nums.size(); i++){
        if(freq == 0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            freq++ ;
        }
        else{
            freq-- ;
        }
         
    }
    return ans;
}
            
  
int main() {
    vector<int>nums = {3, 2, 3};

    cout<<majorityElement(nums)<<endl;

    return 0; 
};