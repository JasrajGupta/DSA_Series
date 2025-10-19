#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

bool isValid(vector<int>& weights ,int n , int d, int maxAllowedWeight){
    int weight = 0, days = 1;
    for(int i = 0; i<n; i++){
        if(weights[i] > maxAllowedWeight){
            return false;
        }
        if(weight + weights[i] <= maxAllowedWeight){
          weight += weights[i];
        }
        else{
            days++;
            weight = weights[i];
        }
    }
    return days > d ? false : true;
}

int shipWithinDays(vector<int>& weights ,int n , int d){
    if(d>n){
        return -1;
    }
     int sum = 0;
    for(int i = 0; i<n; i++){
        sum += weights[i];
    }
    int ans = -1;
    int st = 1, end = sum, mid;
    while(st<=end){
        mid = st + (end - st)/2;
        if(isValid(weights, n, d , mid)){
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

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout<<shipWithinDays(weights,10, 5)<<endl;
}