#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int>& arr, int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }

    }
    return arr;
}

vector<int> selectionSort(vector<int>& arr, int n){
    for(int i = 0; i<n-1; i++){
        int smallIndx = i;
        for(int j = i + 1; j < n; j++){
           if(arr[j] < arr[smallIndx]){
            smallIndx  = j;
        }
}
swap(arr[i] , arr[smallIndx]);
    }
    return arr;
}
vector<int> insertionSort(vector<int>& arr, int n){
    for(int i = 0; i<n-1; i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;

    }
    return arr;
}

int main() {

    vector<int> arr = {4,3, 2, 1, 5};
    vector<int> result = insertionSort(arr, 5);
    for(int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
}

    
}