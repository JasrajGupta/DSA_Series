#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void recurPermute(int index, vector<int> &nums){
    if(index == nums.size()){
            for(int val : nums){
            cout<<val<<" ";
        }
        cout<<endl;
         return;
    }
    for(int i = index; i<nums.size(); i++){
        swap(nums[index], nums[i]);
        recurPermute(index+1, nums);
        swap(nums[index], nums[i]);

}
}
int main(){
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    recurPermute(0, nums);
    return 0;
}