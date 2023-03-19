//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
//https://www.youtube.com/watch?v=s5XRtcud35E
#include<bits/stdc++.h>
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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int np, int li, int ri) {
        if (li < ri) {
            return nullptr;
        }
        if (li == ri) {
            return new TreeNode(inorder[li]);
        }
        TreeNode* root = new TreeNode(postorder[np]);
        int mid = ri;
        while (inorder[mid] != root->val) {
            mid--;
        }

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    }
};