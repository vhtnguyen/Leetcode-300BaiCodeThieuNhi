#include<vector>
using namespace std;
// https://leetcode.com/problems/plus-one/
class Solution {
    public:
    vector<int> plusOne(vector<int>& digits) {
        int r = digits.size() - 1;
        digits[r] = digits[r] + 1;
        int rem = digits[r] / 10;
        digits[r--] = digits[r] % 10;
        for (r;(r >= 0) && rem > 0;--r) {
            if (rem) {
                digits[r] = (digits[r] + rem);
                rem = digits[r] / 10;
                if (rem) {
                    digits[r] = 0;
                }
                else {
                    return digits;
                }
            }

        }
        if (rem) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};