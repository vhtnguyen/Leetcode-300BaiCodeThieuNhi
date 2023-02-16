//https://leetcode.com/problems/minimum-depth-of-binary-tree/
#include<limits.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}

};
class Solution {
    public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int rmd, ans = INT_MAX;
        if (root->left) {
            ans = minDepth(root->left) + 1;
        }
        if (root->right) {
            rmd = minDepth(root->right);
            rmd < ans ? ans = rmd + 1 : ans = ans;
        }
        return ans;
    }
};

// class Solution {
//     public:
//     int minDepth(TreeNode* root) {
//         if (root == NULL) return 0;
//         if (root->left != NULL && root->right != NULL) {
//             return (1 + min(minDepth(root->left), minDepth(root->right)));
//         }
//         else {
//             return (1 + max(minDepth(root->left), minDepth(root->right)));
//         }
//     }
// };