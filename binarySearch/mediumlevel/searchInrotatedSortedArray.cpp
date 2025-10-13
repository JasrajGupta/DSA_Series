#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

int searchinrotatedsortedarray(vector<int>& nums , int tar){
    int n = nums.size() ;
int st = 0, end = n -1 , mid ;

while(st<end){
    mid = st + (end - st)/2;
   if(nums[mid] == tar){
    return mid;
}
 //left sort
 if(nums[st]<=nums[mid]){
    if(nums[st]<=tar && tar<=nums[mid]){
        end = mid - 1;
    }
    else{
        st = mid + 1;
    }
}
else{
    if(nums[mid] < tar && tar <= nums[end]){
        st = mid + 1;
    }
    else{
        end = mid -1;
    }
} 
}

}
int main() {

    vector<int> nums = {4,5,6,7,0,1,2}; //target 0
     
    cout<<searchinrotatedsortedarray(nums , 2)<<endl; //output 4
}