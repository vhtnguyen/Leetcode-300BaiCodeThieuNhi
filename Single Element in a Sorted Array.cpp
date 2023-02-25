//https://leetcode.com/problems/single-element-in-a-sorted-array/
#include<vector>
using namespace std;


class Solution {
    public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (!(mid & 1)) { // the key here
                mid--;
            }
            if (l == r) {
                return nums[l];
            }
            if (nums[mid] == nums[mid - 1]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};