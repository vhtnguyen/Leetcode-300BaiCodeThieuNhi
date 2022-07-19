#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dc[5] = {-1, 0, 1, 0, -1};
struct cell {
    int r, c;
    cell(int x, int y) : r(x), c(y){};
};
    bool isValid(int r, int c,int m,int n) {
    return r >= 0 && c >= 0 && r < m && c < n;
    }    
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int oldCol = img[sr][sc];
        if(oldCol!=color){
            int m = img.size();
            int n = img[0].size();
            queue<cell> q;
            q.push({sr, sc});
            img[sr][sc] = color;
            while(!q.empty()){
                cell u = q.front();
                q.pop();
                for (int i = 0; i < 4;++i){
                    int r = u.r + dc[i];
                    int c = u.c + dc[i+1];
                    if(isValid(r,c,m,n)&&img[r][c]==oldCol){
                        q.push({r, c});
                        img[r][c]=color;
                    }   
                }
            }
        }
        return img;
    }   
};


