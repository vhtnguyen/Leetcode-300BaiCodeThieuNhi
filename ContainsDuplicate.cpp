#include<bits/stdc++.h>
using namespace std;


//hashmap solution O(N^2)

// class Solution {
//     public:
//     unordered_map<int, bool>freq;
//     bool containsDuplicate(vector<int>& nums) {
//         for (auto i : nums) {
//             if (freq[i]) // O(N) when collision happen
//                 return true;
//             freq[i] = true;
//         }
//         return false;
//     }
// };



//sorting solution O(NlogN)
class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());// O(NlogN)
        int n = nums.size();
        for (int i = 0;i < n - 1;++i) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};