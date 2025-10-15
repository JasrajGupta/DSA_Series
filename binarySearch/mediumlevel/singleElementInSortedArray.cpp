#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>
#include <unordered_map>

int singleElementInSortedArray(vector<int>& A){
  int n = A.size() - 1;
  int st = 0, end = n - 1, mid;
  while(st<end){
    mid = st + (end - st)/2;
    if(A[mid] != A[mid - 1] && A[mid] != A[mid + 1]){
        return A[mid];
    }
    if( mid % 2 == 0){
    if(A[mid] == A[mid - 1]){
          end = mid - 1;
    }
    else{
      
        st = mid + 1;
    }
   
}
else{
    if(A[mid] == A[mid - 1]){
        st = mid + 1;
}
else{
    end = mid - 1;
}
}
}
}

int main() {
    vector<int> A = {3,3,7,7,10,11,11};
    cout<<singleElementInSortedArray(A)<<endl;
}