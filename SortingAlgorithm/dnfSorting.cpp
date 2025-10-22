#include<iostream>
#include<vector>
using namespace std;

vector<int> dnfSorting(vector<int> arr, int n){
    int low = 0, mid = 0 , high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
           low++, mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }

}
return arr;
}


int main() {
    vector<int> arr = {1, 2, 0};
    vector<int> result = dnfSorting(arr,3);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
}