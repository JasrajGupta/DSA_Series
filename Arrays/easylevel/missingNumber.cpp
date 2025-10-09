#include<iostream>              
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>


int missingNumber(vector<int>& nums) {
    int ans;
    ans = nums.size();
    for(int i=0; i<nums.size(); i++){
        ans = ans + (i - nums[i]);
    }
    return ans;
}

int main() {
  vector<int>nums = {9,6,4,2,3,5,7,0,1};

  cout<<missingNumber(nums)<<endl;
};
