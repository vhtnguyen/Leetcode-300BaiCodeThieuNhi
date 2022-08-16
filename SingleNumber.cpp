#include<bits/stdc++.h>
using namespace std;

//basic sorting solution

// class Solution {
//     public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int i = 0;
//         for (;i < n - 1;++i) {
//             if (nums[i] == nums[i + 1])
//                 ++i;
//             else
//                 break;
//         }
//         return nums[i];
//     }
// };

//hash map solution


// class Solution {
//     public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int>dict;
//         for (auto i : nums)
//             dict[i]++;
//         for (auto x : dict)
//             if (x.second == 1)
//                 return x.first;
//         return -1;
//     }
// };

// bitwise XOR 

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0], n = nums.size();
        for (int i = 1;i < n;++i)
            x ^= nums[i];
        return x;
    }
};
