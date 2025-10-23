#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeSortedArray(vector<int>& A, int m, vector<int>B, int n){
    int indx = m+n-1 , i = m-1, j = n - 1;
    while(i>=0, j>=0){
        if(A[i] > B[j]){
            A[indx] = A[i];
            indx--, i--;
        }
        else{
            A[indx] = B[j];
            indx--, j--;
        }
}
while(j>=0){
    A[indx] = B[j];
    indx--, j--;
}
return A;
}

int main(){
    vector<int> A = {1,2,3,0,0,0};
    vector<int> B = {2,5,6};
    vector<int> result = mergeSortedArray(A, 3, B, 3);
   for(int i = 0; i<result.size(); i++){
    cout<<result[i]<<ends;
   }
}
