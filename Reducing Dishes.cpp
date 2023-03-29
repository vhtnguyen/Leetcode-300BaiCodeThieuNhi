//https://leetcode.com/problems/reducing-dishes/
#include<bits/stdc++.h>
using namespace std;

/*
(i)=f(i+1)+cumulativeSum(i)
*/

class Solution {
    public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int dp = max(0, satisfaction[n - 1]);
        int cumulativeSum = satisfaction[n - 1];
        int ans = dp;
        for (int i = n - 2;i >= 0;--i) {
            cumulativeSum = cumulativeSum + satisfaction[i];
            dp = dp + cumulativeSum;
            if (dp > ans) {
                ans = dp;
            }
            else {
                return ans;
            }
        }
        return ans;
    }
};