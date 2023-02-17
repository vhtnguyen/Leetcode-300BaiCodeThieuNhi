//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include<limits.h>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}

};

//lower bound and upper bound approaching
// class Solution {
//     public:
//     int ans = INT_MAX;
//     void findMinimunDiff(TreeNode* root) {
//         if (!root) {
//             return;
//         }
//         if (root->left) {
//             TreeNode* curr = root->left;
//             while (curr->right) {
//                 curr = curr->right;
//             }
//             int leftDiff = root->val - curr->val;
//             if (leftDiff < ans) {
//                 ans = leftDiff;
//             }
//         }
//         if (root->right) {
//             TreeNode* curr = root->right;
//             while (curr->left) {
//                 curr = curr->left;
//             }
//             int rightDiff = curr->val - root->val;
//             if (rightDiff < ans) {
//                 ans = rightDiff;
//             }
//         }

//     }
//     int minDiffInBST(TreeNode* root) {
//         if (!root || (!root->left && !root->right)) {
//             return ans;
//         }
//         findMinimunDiff(root);
//         minDiffInBST(root->left);
//         minDiffInBST(root->right);
//         return ans;

//     }
// };

#include<vector>
using namespace std;
class Solution {
    public:
    void tree2Array(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        if (root->left && root->right) {
            v.push_back(root->val);
            return;
        }
        tree2Array(root->left, v);
        v.push_back(root->val);
        tree2Array(root->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        tree2Array(root, v);
        int ans = INT_MAX;
        for (int i = 0;i < v.size() - 1;++i) {
            int j = i + 1;
            if (v[j] - v[i] < ans) {
                ans = v[j] - v[i];
            }
        }
        return ans;
    }
};