#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

bool isPossible(vector<int> &arr, int n, int c, int minAllowedDist){
    int cows = 1, lastStall = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i] - lastStall >= minAllowedDist){
            cows++;
            lastStall = arr[i];
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}

int aggresiveCows(vector<int> &arr, int n, int c){
    sort(arr.begin(), arr.end());
    if(c>n){
        return -1;
    }
    int ans = -1;
   int st = 1, end = arr[n-1] - arr[0], mid;
   while(st<=end){
    mid = st + (end - st)/2;
    if(isPossible(arr, n, c, mid)){//right 
        ans = mid;
        st = mid + 1;
    }
    else{ //left 
        end = mid - 1;
    }

    
}
return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout<<aggresiveCows(arr, 5, 3)<<endl;
}