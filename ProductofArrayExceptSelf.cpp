#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    unordered_map<int, int>dict;
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prt = 1;
        int zero = 0;
        for (auto x : nums) {
            if (x)
                prt *= x;
            else
                zero++;
        }
        int n = nums.size();
        for (int i = 0;i < n;++i) {
            if (!nums[i])
                nums[i] = prt * !(zero > 1);
            else
                nums[i] = (prt * !zero) / nums[i];
        }
        return nums;
    }
};
