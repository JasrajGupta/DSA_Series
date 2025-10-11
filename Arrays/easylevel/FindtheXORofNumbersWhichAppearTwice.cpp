// #include<iostream>              
// #include<string>
// #include<vector>
// using namespace std;
// #include<climits>
// #include<algorithm>
// #include <unordered_map>


// int FindtheXORofNumbersWhichAppearTwice(vector<int>& nums){
//     unordered_map<int, int>freq;
//     int ans = 0;
//     for(int val : nums){
//         freq[val]++;
//     }
//     for(auto[num, count] : freq){
//         if(count == 2){
//         ans ^= num;
//     }
// } 
// return ans;
// }

// int main() {

//     vector<int> nums = {1,2,1,3};

//     cout<<FindtheXORofNumbersWhichAppearTwice(nums)<<endl;
// };

//Above code is for new compiler ans the below is for old compiler
//i have old that why above code is commented 

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

int FindtheXORofNumbersWhichAppearTwice(vector<int>& nums) {
    unordered_map<int, int> freq;
    int ans = 0;

    for (int val : nums) {
        freq[val]++;
    }

    // 👇 Old-style loop instead of structured bindings
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if (it->second == 2) {
            ans ^= it->first;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << FindtheXORofNumbersWhichAppearTwice(nums) << endl;
    return 0;
}
