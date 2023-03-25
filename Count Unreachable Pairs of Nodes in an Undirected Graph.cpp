//https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include<bits/stdc++.h>
using namespace std;
// a + b + c=n
// a(n-a) 

/*
1(7-1)=6
2*(7-2)=10
4(7-4)=12
7*7-1-4-16=49-21=28 = n*n-(sum(sque))

*/
class Solution {
    public:
    bool visited[100001];
    int bfs(vector<vector<int>>& g, int src) {
        int ans = 0;
        queue<int>q;
        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            ans++;
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        long long ans = 0, total_component = 0, sum_squ = 0;
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0;i < n;++i) {
            if (!visited[i]) {
                long long n_node = bfs(g, i);
                total_component += n_node;
                sum_squ += n_node * n_node;
            }
        }
        return (total_component * total_component - sum_squ) / 2;
    }
};