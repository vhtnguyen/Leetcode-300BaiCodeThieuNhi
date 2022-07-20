#include<bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                if (l == mid || !isBadVersion(mid - 1))
                    return mid;
                r = mid - 1;
            }
            else if (!isBadVersion(r))
                    return -1;
             else
                    l = mid + 1;
        }
        return -1;
    } 
};