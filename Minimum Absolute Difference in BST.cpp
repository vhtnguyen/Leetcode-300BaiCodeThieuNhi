//https://leetcode.com/problems/minimum-absolute-difference-in-bst
//This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include<vector>
using namespace std;

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
    void tree2Array(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        tree2Array(root->left, v);
        v.push_back(root->val);
        tree2Array(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
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