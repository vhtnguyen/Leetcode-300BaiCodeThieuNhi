#include<bits/stdc++.h>
using namespace std;

//simplest solution using sorting
//O(nlogn)

// class Solution {
//     public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for (auto& i : nums)
//             i *= i;
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };


//merge array using sub stack solution
//o(n)

// class Solution {
//     public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size(), i = 0;
//         stack<int>s;
//         vector<int>res;
//         while (i < n && nums[i] < 0)
//             s.push(nums[i] * nums[i++]);
//         while (i < n || !s.empty()) {
//             int sqr;
//             i < n ? sqr = nums[i] * nums[i] : sqr = s.top() + 1;
//             if (s.empty() || sqr < s.top()) {
//                 res.push_back(sqr);
//                 ++i;
//             }
//             else {
//                 res.push_back(s.top());
//                 s.pop();
//             }
//         }
//         return res;
//     }
// };

//two pointer
//O(n)

class Solution {
    public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n, 0);
        int i = 0, j = --n;
        while (i <= j) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                res[n--] = a;
                i++;
            }
            else {
                res[n--] = b;
                j--;
            }
        }
        return res;
    }
};
