//https://leetcode.com/problems/minimize-maximum-of-array/description/

#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution {
    public:
    int minimizeArrayValue(vector<int>& nums) {
        fio;
        long long total = nums[0], ans = nums[0];
        for (int i = 1;i < nums.size();i++) {
            total += nums[i];
            ans = max(ans, (total + i) / (i + 1));
        }
        return ans;
    }
};