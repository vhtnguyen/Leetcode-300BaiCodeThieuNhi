#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0, low = 0, high = 0;
        for (int i = 1; i < prices.size();++i){
            int today = prices[i];
            if(today<prices[low]){
                low = i;
                high = low;
            }
            else{
                high = i;
                int sellNow = prices[high] - prices[low];
                if (sellNow> maxProf)
                    maxProf = sellNow;
            }  
        }
        return maxProf;
    }
};