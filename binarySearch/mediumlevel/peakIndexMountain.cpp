#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>

int peakIndexMountainArray(vector<int>& A){
int n = A.size() - 1;
int st = 0 , end = n-1 , mid;
while(st<end){
    mid = st + (end - st)/2;
    if(A[mid]>A[mid+1] && A[mid]>A[mid-1]){
        return mid;
    }
else if(A[mid-1]<A[mid]){
    st = mid + 1;
}
else{
    end = mid - 1;
}
}
}

int main() {

    vector<int> A = {2,5, 10, 20, 30, 50, 70 , 18, 0};
    cout<<peakIndexMountainArray(A)<<endl;
}