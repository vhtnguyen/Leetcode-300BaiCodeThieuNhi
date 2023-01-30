#include<Bits/stdc++.h>
using namespace std;

class Solution {
    public:
    unordered_map<int, int>dict;
    int solve(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        for (auto c : coins) {
            if (amount == c)
                return 1;
            else {
                int k = amount - c;
                int ans = solve(coins, k);
                if (ans < 0)
                    dict[k] = -1;
                else
                    dict[k] = dict[k] != 0 ? min(ans + 1, dict[k]) : 0;
            }
        }
        return dict[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        for (auto c : coins) {
            dict[c] = 1;
        }
        for (int i = 0;i <= amount;++i) {
            if (!dict[i])
                dict[i] = i;
        }
        sort(coins.begin(), coins.end());
        return solve(coins, amount);
    }
};


// int main() {
//     vector<int>v({ 1,2,5 });
//     Solution x;
//     x.coinChange(v, 11);


//     return 0;
// }