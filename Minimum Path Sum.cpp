//https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        stack<pair<int, int>>st;
        function<bool(int, int)> isValid = [&](int row, int col) {
            if (row < 0 || row >= n) {
                return false;
            }
            if (col < 0 || col >= m) {
                return false;
            }
            return true;
        };
        st.push(make_pair(0, 0));
        dp[0][0] = grid[0][0];
        while (!st.empty()) {
            auto [i, j] = st.top();
            st.pop();
            int u = dp[i][j];
            if (isValid(i, j + 1) && (u + grid[i][j + 1]) < dp[i][j + 1]) {
                dp[i][j + 1] = u + grid[i][j + 1];
                st.push(make_pair(i, j + 1));
            }
            if (isValid(i + 1, j) && (u + grid[i + 1][j]) < dp[i + 1][j]) {
                dp[i + 1][j] = u + grid[i + 1][j];
                st.push(make_pair(i + 1, j));
            }
        }
        return dp[n - 1][m - 1];
    }
};

// int main() {
//     vector<vector<int>>g = { {1, 3, 1},{1, 5, 1 }, { 4, 2, 1 } };
//     Solution a;
//     a.minPathSum(g);
// }