//https://leetcode.com/problems/contains-duplicate-ii/

#include<vector>
#include<unordered_map>
using namespace std;

//sliding window

// class Solution {
//     public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         set <int>window;
//         int n = nums.size();
//         k++;
//         window.insert(nums[0]);
//         for (int j = 1;j < n;++j) {
//             if (j >= k) {
//                 window.erase(window.find(nums[j - k]));
//             }
//             auto it = window.find(nums[j]);
//             if (it != window.end()) {
//                 return true;
//             }
//             window.insert(nums[j]);
//         }
//         return false;
//     }
// };

class Solution {
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int>m;
        int n = nums.size();
        for (int i = 0;i < n;++i) {
            if ((m.find(nums[i]) != m.end()) && abs(m[nums[i]] - i) <= k) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};