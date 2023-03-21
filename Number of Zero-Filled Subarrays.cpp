//https://leetcode.com/problems/number-of-zero-filled-subarrays/
//https://math.stackexchange.com/questions/1194584/the-total-number-of-subarrays
#include<vector>
using namespace std;

class Solution {
    public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        while (i < nums.size()) {
            if (!nums[i]) {
                int j = i + 1;
                while (j < nums.size() && !nums[j]) {
                    j++;
                }
                long long n = j - i;
                ans += n * (n + 1) / 2;
                i = j;
            }
            i++;
        }
        return ans;
    }
};