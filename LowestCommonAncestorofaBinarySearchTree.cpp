
#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* a, TreeNode* b) {
       if(r->val<a->val&&r->val<b->val)
           return lowestCommonAncestor(r->right, a, b);
        else if(r->val>a->val&&r->val>b->val)
            return lowestCommonAncestor(r->left, a, b);
        else 
            return r;
    }
    
};

