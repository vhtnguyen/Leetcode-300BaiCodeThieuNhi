#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int dr[5] = { -1,0,1,0,-1 };
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n&& j < m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int org = 0, res = 0, cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < m;++j) {
                if (grid[i][j])
                    org++;
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                    cnt++;
                }
            }
        }
        while (!q.empty()) {
            int k = q.size();
            bool speard = false;
            for (int i = 0;i < k;++i) {
                auto [r, c] = q.front();
                q.pop();
                for (int j = 0;j < 4;++j) {
                    int nr = r + dr[j];
                    int nc = c + dr[j + 1];
                    if (isValid(nr, nc, n, m) && grid[nr][nc] != 0) {
                        q.emplace(nr, nc);
                        grid[nr][nc] = 0;
                        cnt++;
                        speard = true;
                    }
                }
            }
            if (speard)
                res++;
        }
        if (cnt != org)
            return -1;
        return res;

    }
};
// int main() {
//     vector <vector<int>> v;
//     v.push_back(vector<int>{2, 1, 1});
//     v.push_back(vector<int>{1, 1, 0});
//     v.push_back(vector<int>{0, 1, 1});
//     Solution x;
//     x.orangesRotting(v);

//     return 0;
// }


