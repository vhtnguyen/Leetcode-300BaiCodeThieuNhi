#include<bits/stdc++.h>
using namespace std;

// dp approach

// class Solution {
//     public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int dp[n];
//         dp[0] = nums[0];
//         int maximumSumSubarray = nums[0];
//         for (int i = 1; i < n; i++) {
//             dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
//             maximumSumSubarray = max(maximumSumSubarray, dp[i]);
//         }
//         return maximumSumSubarray;
//     }
// };

//Kadane’s Algorithm
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0, maximumSumSubarray = INT_MIN;
        for (auto num : nums) {
            currSum += num;
            if (currSum > maximumSumSubarray) {
                maximumSumSubarray = currSum;
            }
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maximumSumSubarray;
    }
};
