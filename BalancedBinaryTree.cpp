#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// class Solution {
// public:
//     bool isBalanced(TreeNode* r) {
//         if (!r)
//             return true;
//         int lh = height(r->left), rh = height(r->right);
//         if (isBalanced(r->left) && isBalanced(r->right) && abs(lh - rh) <= 1)
//             return true;
//         return false;
//     }
//     int height(TreeNode *r){
//         if (!r)
//             return 0;
//         else 
//             return 1 + max(height(r->left), height(r->right));
//     }
// };

  //more optimize solution
  class Solution {
      public:
      bool balanced;
      bool isBalanced(TreeNode* r) {
        balanced = true;
        height(r);
        return balanced;

      }
    int height(TreeNode *r){
        if (!r||!balanced)
            return 0;
        int lh = height(r->left);
        if (!balanced)
            return 0;
        int rh = height(r->right);
        if (!balanced)
            return 0;
        if (abs(lh - rh) > 1) {
            balanced = false;
            return 0;
        }
        return 1 + max(lh, rh);
    }
};