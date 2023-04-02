#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = reward1.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + reward2[i - 1];
            for (int j = 0; j < k; j++) {
                dp[i][j] = max(dp[i - 1][j] + reward1[i - 1], dp[i - 1][j - 1] + reward2[i - 1]);
            }
        }
        return dp[n][k];

    }
};
