//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

// class Solution {
//     public:
//     int countOdds(int low, int high) {
//         int res = 0, num = high - low + 1;
//         res += (low & 1) + (high & 1);
//         num -= res;
//         res += (num / 2) - (res > 0 && low == high);
//         return res;
//     }
// };

class Solution {
    public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - (low / 2);
    }
};