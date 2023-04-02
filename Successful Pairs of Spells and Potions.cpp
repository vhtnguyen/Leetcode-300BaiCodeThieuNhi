//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include<bits/stdc++.h>
using namespace std;


/*
function<bool(int, int)> calc = [&](int i, int j) {
            return spells[i]*1.0 >= success*1.0 / potions[j];
        };
*/

class Solution {
    public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(potions.begin(), potions.end());
        vector<int>ans;
        int n = spells.size(), m = potions.size();
        for (int i = 0;i < n;++i) {
            int l = 0, r = m - 1;
            double target = 1.0 * success / spells[i];
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (potions[mid] < target) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if (r < l) {
                ans.push_back(m - l);
            }
        }
        return ans;

    }
};