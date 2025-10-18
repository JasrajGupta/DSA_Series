#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

bool isValid(vector<int> &arr, int n, int m, int maxAllowedTime){
    int painter = 1, time = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > maxAllowedTime){
            return false;
        }
        if(time + arr[i] <= maxAllowedTime){
            time+= arr[i];
        }
        else{
            painter++;
            time = arr[i];
        }
}
return painter > m ? false : true;
}

int paintersPartition(vector<int> &arr, int n, int m ){
    if(m > n){
        return -1;
    }
    int sum; 
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    int st = 0, end = sum, mid;
    int ans = 0;
    while(st<=end){                                       //O(nlogn) overall time complexity
        mid = st + (end - st)/2;
        if(isValid(arr, n , m , mid)){
            
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
     
    vector<int> arr = {10, 10, 10, 10};
    cout<<paintersPartition(arr , 4, 2)<<endl;
}