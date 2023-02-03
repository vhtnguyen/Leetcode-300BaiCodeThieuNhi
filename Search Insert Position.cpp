#include<vector>
using namespace std;

// https://leetcode.com/problems/search-insert-position/

class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
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

        if (left > right) {
            return left;
        }
        else {
            return right;
        }

    }
};



