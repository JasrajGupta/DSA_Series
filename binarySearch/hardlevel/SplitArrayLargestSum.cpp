#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& nums, int n, int k, int maxAllowedSum){
    int Sum = 0, subarray = 1;
    for(int i = 0; i<n; i++){
        if( nums[i] > maxAllowedSum){
            return false;
        }
        if(Sum + nums[i] <= maxAllowedSum){
            Sum += nums[i];
        }
        else{
            subarray++;
            Sum = nums[i];
        }
}
return subarray > k ? false : true;
}
int SplitArrayLargestSum(vector<int>& nums, int n, int k){
    if(k>n){
        return -1;
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];
    }
    if(sum == 0){
        return 0;
    }
    int ans = -1;
    int st = 1 /* *max_element(nums.begin(), nums.end())*/, end = sum , mid;
    while(st<=end){
        mid = st + (end - st)/2;
        if(isValid(nums, n, k, mid)){
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
    vector<int> nums = {7,2,5,10,8};
    cout<<SplitArrayLargestSum(nums, 5, 2)<<endl;
}