#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx = st - 1, piv = arr[end];
    for(int i = st; i<end; i++){
        if(arr[i] < piv){
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}
void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int piv = partition(arr, st, end);
        quickSort(arr, st, piv - 1);  //left
        quickSort(arr, piv+1, end);   //right
        
    }
}
int main(){
    vector<int> arr = {5, 2, 6, 4, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    for(int val : arr){
        cout<<val<<" "; 
    }
    cout<<endl;
    return 0;
}
