#include<bits/stdc++.h>
using namespace std;

//sum

// class Solution {
//     public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         long long sum = 0; // using int may causes overflow
//         for (auto i : nums)
//             sum += i;
//         return (n * (n - 1)) / 2 - sum;
//     }
// };


//bitwise XOR
//BASE : a^a=0 ; a^a^b=b

class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = n;
        for (int i = 0;i < n;++i)
            res ^= i ^ nums[i];
        return res;
    }
};