#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<climits>
#include<algorithm>


bool isValid(vector<int> &pages , int n , int m, int maxAllowedPages){
    int student = 1, Page = 0; 
    for(int i = 0; i<n; i++){
       if( pages[i] > maxAllowedPages ){
        return false;
    }
    if( Page  + pages[i] <= maxAllowedPages){
        Page += pages[i];
    }
        else{
            student++;
            Page = pages[i];
        }
        
}
return student > m ? false : true;
}


int allocateMinimumPages(vector<int> pages , int n , int m){
    if(m > n){
        return -1;
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += pages[i];
    }
    int st = 0 , end = sum , mid;
   int ans = -1;
    while(st<end){
        mid = st + (end - st)/2;
        if(isValid(pages,n, m, mid)){ //right 
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}

int main() {

    vector<int> pages = {12, 34, 67, 90};
    cout<<allocateMinimumPages(pages, 4, 2 )<<endl;
    return 0;
}