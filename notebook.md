# My notebook for some common data structures and algorithms

```cpp
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
```

## Binary search

```cpp
#include<algorithm>

vector<int>v = { 1,1, 2,2,2, 3,4,5 ,7 };
int x = 3;
bool result = binary_search(v.begin(), v.end(), x);
// true
```

### lower_bound

```cpp
#include<algorithm>

//return iterator of the first element greater or equal to the target in range [first,last)
vector<int>v = { 1, 1, 2, 2, 2, 3, 4, 5, 7};
int x = 3;
vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
int index = it - v.begin();
// 5
```

### upper_bound

```cpp
#include<algorithm>

//return iterator of the first element greater than the target in range [first,last)
vector<int>v = { 1, 1, 2, 2, 2, 3, 4, 5, 7};
int x = 3;
vector<int>::iterator it = upper_bound(v.begin(), v.end(), x);
int index = it - v.begin();
// 6
```

### Implement

```cpp
int binarySearch(const vector<int>& nums, int left, int right, int target) {

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    //not found
    return -1;

}
```

```cpp
int binarySearch(const vector<int>& nums, int left, int right, int target) {

    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, right, target);
        }
        return binarySearch(nums, left, mid - 1, target);
    }
    //not found
    return -1;

}
```

```cpp
int binarySearchFirst(const vector<int>& nums, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == left || nums[mid - 1] < target )&& nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearchFirst(nums, mid + 1, right, target);
        }
        return binarySearchFirst(nums, left, mid - 1, target);
    }
    return -1;
}
```

```cpp
int binarySearchLast(const vector<int>& nums, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == right || nums[mid + 1] > target) && nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearchLast(nums, mid + 1, right, target);
        }
        return binarySearchLast(nums, left, mid - 1, target);
    }
    return -1;
}
```

## Breadth-first search (BFS)

```cpp
// Graph with adjacency lists based
void bfs(int s){
    for(int i=0;i<V;++i){
        visited[i]=false;
        path[i]=-1;
    }
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();++i){
            int v=graph[u][i];
            if(!visited[v]){
                visited[v]=true;
                path[v]=u;
                q.push(v);
            }
        }
    }
}
```

```cpp
// Graph with matrix/grid based
int dc[5] = { -1, 0, 1, 0, -1 };;
    bool isValid(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
    }
    //BFS non-recursive solution
    int bfs(vector<vector<int>>& grid) {
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

```

## Depth-first search (DFS)

```cpp
//recursive implement
void dfs(int s){
    visited[s]=true;
    for(int i=0;i<graph[s].size();++i){
        int v=graph[s][i];
        if(!visited[v]){
           //do something here
            dfs(v);
        }
    }
}
```
