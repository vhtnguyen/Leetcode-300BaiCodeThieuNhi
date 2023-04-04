//https://leetcode.com/problems/optimal-partition-of-string/

#include<bits/stdc++.h>
using namespace std;

//"yzubfsiypfrepcfftiov"

class Solution {
    public:
    int arr[26];
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        memset(arr, 0, sizeof(arr));
    }
    int partitionString(string& s, int start = 0) {
        int n = s.length();
        if (start == n - 1) {
            return 1 + arr[s[start] - 'a'];
        }
        if (arr[s[start] - 'a']) {
            memset(arr, 0, sizeof(arr));
            arr[s[start] - 'a']++;
            return 1 + partitionString(s, start + 1);
        }
        else {
            arr[s[start] - 'a']++;
            return partitionString(s, start + 1);
        }
    }
};