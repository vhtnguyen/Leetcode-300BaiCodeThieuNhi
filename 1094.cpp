#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[2] > b[2];
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        int cap = capacity;
        for (auto i : trips) {

            while (!pq.empty() && i[1] >= pq.top()[2]) {
                cap += pq.top()[0];
                pq.pop();
            }

            cap -= i[0];
            if (cap < 0)
                return false;
            pq.push(i);
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> t;

    t.push_back({3, 2, 8});
    t.push_back({4, 4, 6});
    t.push_back({10, 8, 9});
    int cap = 11;
    cout << s.carPooling(t, cap);
    //testing
    return 0;
}