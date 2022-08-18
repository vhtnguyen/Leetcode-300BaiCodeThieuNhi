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


class Solution {
    public:
    bool res;
    bool check(TreeNode* d, TreeNode* c) {
        if (!d && !c)
            return true;
        if (!(d && c) || d->val != c->val)
            return false;
        if (d->val == c->val)
            return check(d->left, c->left) && check(d->right, c->right);
        return false;
    }
    bool isSubtree(TreeNode* d, TreeNode* c) {
        if (!(d && c))
            return false;
        if (d->val == c->val)
            res = check(d, c);
        if (!res)
            res = isSubtree(d->left, c);
        if (!res)
            res = isSubtree(d->right, c);
        return res;
    }
};