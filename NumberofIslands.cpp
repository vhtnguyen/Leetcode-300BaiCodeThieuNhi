#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int dr[5] = { -1, 0, 1, 0, -1 };
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n&& c < m;
    }
    void BFS(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        q.emplace(i, j);
        grid[i][j] = '0';
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0;k < 4;++k) {
                int nr = r + dr[k];
                int nc = c + dr[k + 1];
                if (isValid(nr, nc, n, m) && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    q.emplace(nr, nc);
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < m;++j) {
                if (grid[i][j] == '1') {
                    res++;
                    BFS(i, j, grid);
                }
            }
        }
        return res;
    }
};

