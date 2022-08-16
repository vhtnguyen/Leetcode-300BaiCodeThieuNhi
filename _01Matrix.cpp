#include<bits/stdc++.h>
using namespace std;


//BFS non-recursive approach

class Solution {
    public:
    int dc[5] = { -1, 0, 1, 0, -1 };
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n&& c < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c)
                if (mat[r][c] == 0)
                    q.push(make_pair(r, c));
                else
                    mat[r][c] = -1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dc[i];
                int nc = c + dc[i + 1];
                if (!isValid(nr, nc, n, m) || mat[nr][nc] != -1)
                    continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.push(make_pair(nr, nc));
            }
        }
        return mat;
    }
};

