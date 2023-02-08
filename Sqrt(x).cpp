//https://leetcode.com/problems/sqrtx/
#include<iostream>
using namespace std;
class Solution {
    public:
    int mySqrt(int x) {
        return binarySearch(0, x, x);
    }
    int binarySearch(int left, int right, int x) {
        if (left <= right) {
            long long mid = left + (right - left) / 2;
            if ((mid == right || (mid + 1) > x / (mid + 1)) && (mid <= x / mid)) {
                return mid;
            }
            else if (mid < x / mid) {
                return binarySearch(mid + 1, right, x);
            }
            return binarySearch(left, mid - 1, x);
        }
        return -1;
    }

};


// class Solution {
//     public:
//     int mySqrt(int x) {
//         if (x == 0) return 0;
//         int i = 1;
//         for (;i <= x / i;i++) //using division instead of multiplication to avoid integer overflow
//             if (x / i == i)  return i;
//         return i - 1; //returning (i-1) because at some point (i*i) became greater than x and loop stopped!!!
//     }
// };
