#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>


int maximumSubarray(vector<int>& nums){
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i<nums.size(); i++){
        currSum = currSum + nums[i];
        maxSum = max(currSum, maxSum);
        if(currSum<0){
            currSum = 0;
        }
       
    }
     return maxSum;
}


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maximumSubarray(nums)<<endl;
};
