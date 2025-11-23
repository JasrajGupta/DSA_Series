#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int st, int end, int tar ){
    int mid = st + (end - st)/2;
    if(arr[mid] == tar){
        return arr[mid];
    }
    else if(st<=end){
     if(arr[mid] <= tar){
        return binarySearch(arr, mid+1, end , tar );
    }
    else{
        return binarySearch(arr, st , mid - 1, tar);
    }
}
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4, 5};
    cout<<binarySearch(arr, 0, arr.size() - 1, 3)<<endl;
}