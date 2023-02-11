//https://leetcode.com/problems/shortest-path-with-alternating-colors/
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        //build the graph with adjacency lists
        vector<vector<pair<int, int>>>graph(n);
        for (int i = 0;i < redEdges.size();++i) {
            graph[redEdges[i][0]].push_back({ redEdges[i][1],1 });
        }
        for (int i = 0;i < blueEdges.size();++i) {
            graph[blueEdges[i][0]].push_back({ blueEdges[i][1],2 });
        }
        return bfs(graph, n);
    }
    vector<int> bfs(vector<vector<pair<int, int>>>& graph, int n) {
        vector<int>res(n, -1);
        queue<pair<int, int>>q; // pair<v,c> : current at vetex V with pre-color c
        for (int i = 0;i < graph[0].size();++i) {
            q.push(graph[0][i]);
            res[graph[0][i].first] = 1;
            graph[0][i].first = -1;
        }
        res[0] = 0;
        int step = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                auto u = q.front();
                q.pop();
                int szu = graph[u.first].size();
                for (int j = szu - 1;j >= 0;--j) {
                    auto v = graph[u.first][j];
                    if (v.first != -1 && v.second != u.second) {
                        q.push(v);
                        graph[u.first][j].first = -1;
                        if (res[v.first] == -1) {
                            res[v.first] = step + 1;
                        }
                    }
                }
            }
            step++;
        }
        return res;

    }
};

int main() {
    //[[2,2],[0,1],[0,3],[0,0],[0,4],[2,1],[2,0],[1,4],[3,4]]
    //[[1,3],[0,0],[0,3],[4,2],[1,0]]
    vector<vector<int>>red = { {2, 2}, {0, 1}, {0, 3}, {0, 0}, {0, 4}, {2, 1}, {2, 0}, {1, 4}, {3, 4} };
    vector<vector<int>>blue = { {1, 3}, {0, 0}, {0, 3}, {4, 2}, {1, 0} };
    Solution a;
    int n = 5;
    a.shortestAlternatingPaths(n, red, blue);
    return 0;
}
