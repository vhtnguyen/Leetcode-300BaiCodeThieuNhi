//https://leetcode.com/problems/add-to-array-form-of-integer/
#include<vector>
using namespace std;

class Solution {
    public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>res;
        int sum = 0;
        int carry = 0;
        int i = num.size() - 1;
        while (i >= 0 || carry || k) {
            sum = 0;
            i >= 0 ? sum += num[i--] : sum += 0;
            k != 0 ? sum += k % 10 : sum += 0;
            sum += carry;
            carry = sum > 9;
            k /= 10;
            res.push_back(sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};