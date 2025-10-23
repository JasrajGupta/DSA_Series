#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextPermutation(vector<int>& A, int n){
    int pivot = -1;
    for(int i = n - 2; i>=0; i--){
        if(A[i] < A[i+1]){
            pivot = i;
            break;
        }
}
if(pivot == -1){
    reverse(A.begin(), A.end());
    return A;
}
for(int i = n - 1; i>pivot; i--){
    if(A[i] > A[pivot]){
        swap(A[i], A[pivot]);
        break;
    }
}
int i = pivot+1 , j = n-1;
while(i<=j){
    swap(A[i++], A[j--]);
   
}
return A;
}

int main(){
    vector<int> A = {1,2,3};
    vector<int> result = nextPermutation(A ,3);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<ends;
    }
}