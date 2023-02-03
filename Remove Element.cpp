// class Solution {
//     public:
//     int removeElement(vector<int>& nums, int val) {
//         int n = nums.size();
//         int i = 0, j = 0;
//         for (;j < n;++j) {
//             if (nums[j] != val) {
//                 nums[i++] = nums[j];
//             }
//         }
//         return i;
//     }
// };