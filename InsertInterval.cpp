#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int bgn = newInterval[0], end = newInterval[1];
        if (intervals[0][0] > end)
            intervals.insert(intervals.begin(), newInterval);
        else if (intervals[intervals.size() - 1][1] < bgn)
            intervals.push_back(newInterval);
        else {
            int a = lower_bound(intervals.begin(), intervals.end(), bgn, [](const vector<int>& a, const int& b) {return a[1] >= b || a[0] >= b;}) - intervals.begin();
            int b = lower_bound(intervals.begin(), intervals.end(), end, [](const vector<int>& a, const int& b) {return a[0] >= b || a[1] >= b;}) - intervals.begin();
            //[[1,3],[6,9]], newInterval = [4,5] | [1,5] [6,9] } 0 0
            //[[1,3],[6,9]], newInterval = [-1,0]| [-1,0] [1,3] [6,9] 3 3
            //[[1,3],[6,9]], newInterval = [0,2]| [0,3] [6,9]


        }


        int a = lower_bound(intervals.begin(), intervals.end(), bgn, [](const vector<int>& a, const int& b) {return a[1] >= b || a[0] >= b;}) - intervals.begin();

        int b = lower_bound(intervals.begin(), intervals.end(), end, [](const vector<int>& a, const int& b) {return a[1] >= b || a[0] >= b;}) - intervals.begin();














    }
};