#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    int st = 0, end = n - 1, mid;
    while(st<=end){
        mid = st + (end - st)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid]<target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
}
return st;
}

int main() {

    vector<int> nums = {1, 3, 5, 6};
    cout<<searchInsert(nums, 0)<<endl;
}