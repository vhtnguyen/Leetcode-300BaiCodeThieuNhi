#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            if (!nums[i]) {
                while (j < n && !nums[j])++j;
                if (j < n)
                    swap(nums[i], nums[j]);
            }
            ++i;
            ++j;
        }
    }
};