//https://leetcode.com/problems/jump-game-iv/


#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
    public:
    bool visited[100000];
    unordered_map<int, pair<bool, vector<int>>>om;
    void buidMap(vector<int>& arr) {
        for (int i = arr.size() - 1;i >= 0;--i) {
            visited[i] = 0;
            om[arr[i]].first = false;
            om[arr[i]].second.push_back(i);
        }
    }

    int minJumps(vector<int>& arr) {
        buidMap(arr);
        int target = arr.size() - 1;
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int k = 0;k < n;++k) {
                int i = q.front();
                q.pop();
                if (i == target) {
                    return ans;
                }
                if (!om[arr[i]].first) {
                    for (int m : om[arr[i]].second) {
                        if (m != i && !visited[m]) {
                            q.push(m);
                            visited[m] = true;
                        }
                    }
                    om[arr[i]].first = true;
                }

                if ((i + 1 <= target) && !visited[i + 1]) {
                    q.push(i + 1);
                    visited[i + 1] = true;
                }
                if ((i - 1 >= 0) && !visited[i - 1]) {
                    q.push(i - 1);
                    visited[i - 1] = true;
                }
            }
            ans++;
        }
        return -1;
    }
};



