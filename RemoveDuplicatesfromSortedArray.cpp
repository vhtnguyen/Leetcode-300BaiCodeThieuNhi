// class Solution {
//     public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0, j = 1, n = nums.size();
//         while (true) {
//             while (j < n && nums[j] <= nums[i]) {
//                 j++;
//             }
//             if (j < n) {
//                 nums[++i] = nums[j];
//             }
//             else {
//                 return i + 1;
//             }
//         }
//     }
// };