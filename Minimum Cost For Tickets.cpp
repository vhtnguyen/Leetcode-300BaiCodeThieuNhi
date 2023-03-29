//https://leetcode.com/problems/minimum-cost-for-tickets/
#include<bits/stdc++.h>
using namespace std;


// class Solution {
//     public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.size();
//         int dp[366];
//         memset(dp, 0, sizeof(dp));
//         for (auto day : days)
//             dp[day] = costs[0];
//         for (int i = 1; i <= days[n - 1]; i++) {
//             if (!dp[i])
//                 dp[i] = dp[i - 1];
//             else {
//                 dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
//             }
//         }

//         return dp[days[n - 1]];
//     }
// };

//https://leetcode.com/problems/minimum-cost-for-tickets/solutions/226659/two-dp-solutions-with-pictures/?orderBy=most_votes
class Solution {
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs, int cost = 0) {
        queue<pair<int, int>> last7, last30;
        for (auto d : days) {
            while (!last7.empty() && last7.front().first + 7 <= d) last7.pop();
            while (!last30.empty() && last30.front().first + 30 <= d) last30.pop();
            last7.push({ d, cost + costs[1] });
            last30.push({ d, cost + costs[2] });
            cost = min({ cost + costs[0], last7.front().second, last30.front().second });
        }
        return cost;
    }
};