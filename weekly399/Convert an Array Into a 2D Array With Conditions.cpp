#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
class Solution {
    public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>> ans;
        unordered_map<int, int>m;

        for (int i : nums) {
            if (m.find(i) == m.end()) {
                m[i] = 1;
            }
            else {
                m[i]++;
            }

        }
        while (true) {
            vector<int>r;
            for (auto& it : m) {
                if (it.second > 0) {
                    r.push_back(it.first);
                    it.second--;
                }
                // if (it.second == 0) {
                //     m.erase(it.first);
                // }
            }
            if (!r.empty()) {
                ans.push_back(r);
            }
            else {
                break;
            }

        }

        return ans;

    }
};
int main() {
    return 0;
}