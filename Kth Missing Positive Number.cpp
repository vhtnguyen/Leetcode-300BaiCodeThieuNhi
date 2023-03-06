//https://leetcode.com/problems/kth-missing-positive-number/

#include<vector>
using namespace std;

/*
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,11,13,...]. The 5th missing positive integer is 9.

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

class Solution {
    public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        int mid = left + (right - left) / 2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] - (mid + 1) < k) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }

        }
        return left + k;
    }
};