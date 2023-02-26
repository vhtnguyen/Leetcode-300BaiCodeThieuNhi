#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0, low = 0;
        int n = prices.size();
        for (int high = 1; high < n;++high) {
            if (prices[high] < prices[low])
                low = high;
            else {
                int sellNow = prices[high] - prices[low];
                if (sellNow > maxProf)
                    maxProf = sellNow;
            }
        }
        return maxProf;
    }
};