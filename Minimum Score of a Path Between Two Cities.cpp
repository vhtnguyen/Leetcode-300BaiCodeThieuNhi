//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
class Solution {
    public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>>g(100001);
        bool visited[100001];
        int min_edge[100001];
        int ans = INT_MAX;
        queue<int>q;
        for (int i = 1;i <= n;++i) {
            visited[i] = false;
            min_edge[i] = INT_MAX;
        }
        for (auto& p : roads) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
            if (min_edge[p[0]] > p[2]) {
                min_edge[p[0]] = p[2];
            }
            if (min_edge[p[1]] > p[2]) {
                min_edge[p[1]] = p[2];
            }
        }
        visited[1] = true;
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    if (min_edge[v] < ans) {
                        ans = min_edge[v];
                    }
                }
            }
        }
        return ans;
    }
};

