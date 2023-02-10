//https://leetcode.com/problems/as-far-from-land-as-possible/
#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
    int dc[5] = { -1, 0, 1, 0, -1 };;
    bool isValid(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
    }
    int maxDistance(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        queue <pair<int, int >> q;
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                if (grid[i][j] == 1) {
                    q.push({ i,j });
                }
            }
        }
        if (q.size() == 0 || q.size() == n * n) {
            return -1;
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (int i = 0; i < 4;++i) {
                int r = u.first + dc[i];
                int c = u.second + dc[i + 1];
                if (isValid(grid, r, c) && grid[r][c] == 0) {
                    q.push({ r, c });
                    grid[r][c] = grid[u.first][u.second] + 1;
                    if (grid[r][c] - 1 > res) {
                        res = grid[r][c] - 1;
                    }
                }
            }
        }
        return res;
    }


};

