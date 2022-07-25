#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//recursive solution

class Solution {
    int Depth;
    public:
    int maxDepth(TreeNode* r) {
        if (!r)
            return 0;
        int ld = maxDepth(r->left);
        int rd = maxDepth(r->right);
        return max(ld, rd) + 1;
    }
};



