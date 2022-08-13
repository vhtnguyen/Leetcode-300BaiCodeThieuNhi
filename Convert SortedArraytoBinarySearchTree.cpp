#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//recursive solution

class Solution {
    public:
    TreeNode* solve(int l, int r, vector<int>& nums) {
        if (r < l)
            return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        //TreeNode* root = new TreeNode(nums[m], solve(l, m - 1, nums), solve(m + 1, r, nums));
        root->left = solve(l, m - 1, nums);
        root->right = solve(m + 1, r, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return solve(l, r, nums);
    }
};

