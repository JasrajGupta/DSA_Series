#include<iostream>
using namespace std; 
#include<vector>

int check(vector<int> &arr, int st, int mid, int end) {
    int i = st, j = mid + 1, count = 0;
    vector<int> temp;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;

            count += (mid - i + 1);   // FIXED
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return count;
}

int countInversion(vector<int> &arr, int st, int end) {
    if(st >= end) return 0;

    int mid = st + (end - st)/2;

    int left = countInversion(arr, st, mid);
    int right = countInversion(arr, mid+1, end);
    int mergeCount = check(arr, st, mid, end);

    return left + right + mergeCount;
}

int main() {
    vector<int> arr = {6,3,5,2,7};

    int ans = countInversion(arr, 0, arr.size()-1);

    cout << "Inversion count is: " << ans;
}