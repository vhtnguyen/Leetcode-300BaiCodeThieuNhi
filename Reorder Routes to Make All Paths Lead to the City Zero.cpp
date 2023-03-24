//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/


#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool visited[100001];
    int ans = 0;

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>g1(n);
        vector<vector<int>>g2(n);
        for (auto c : connections) {
            g1[c[0]].push_back(c[1]);
            g2[c[1]].push_back(c[0]);
        }
        queue<int>q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g2[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
            for (auto v : g1[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};