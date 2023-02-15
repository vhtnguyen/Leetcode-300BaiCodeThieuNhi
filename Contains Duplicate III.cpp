//https://leetcode.com/problems/contains-duplicate-iii/
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

/*
abs(nums[i]-nums[j])<=valueDiff
nums[j]-valueDiff<=nums[i]<=nums[j]+valueDiff
*/

// class Solution {
//     public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
//         set <int>window;
//         int n = nums.size();
//         indexDiff++;
//         window.insert(nums[0]);
//         for (int j = 1;j < n;++j) {
//             if (j >= indexDiff) {
//                 window.erase(window.find(nums[j - indexDiff]));
//             }
//             auto it = window.lower_bound(nums[j] - valueDiff);
//             if (it != window.end() && (*it <= nums[j] + valueDiff)) {
//                 return true;
//             }
//             window.insert(nums[j]);
//         }
//         return false;

//     }
// };


//https://leetcode.com/problems/contains-duplicate-iii/solutions/824578/c-o-n-time-complexity-explained-buckets-o-k-space-complexity/

class Solution {
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();

        if (n == 0 || k < 0 || t < 0) return false;

        unordered_map<int, int> buckets;

        for (int i = 0; i < n; ++i) {
            int bucket = nums[i] / ((long)t + 1);

            // For negative numbers, we need to decrement bucket by 1
            // to ensure floor division.
            // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
            // Therefore, decrement by 1.
            if (nums[i] < 0) --bucket;

            if (buckets.find(bucket) != buckets.end()) return true;
            else {
                buckets[bucket] = nums[i];
                if (buckets.find(bucket - 1) != buckets.end() && (long)nums[i] - buckets[bucket - 1] <= t) return true;
                if (buckets.find(bucket + 1) != buckets.end() && (long)buckets[bucket + 1] - nums[i] <= t) return true;

                if (buckets.size() > k) {
                    int key_to_remove = nums[i - k] / ((long)t + 1);

                    if (nums[i - k] < 0) --key_to_remove;

                    buckets.erase(key_to_remove);
                }
            }
        }

        return false;
    }
};