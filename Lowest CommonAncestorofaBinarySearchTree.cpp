
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
    stack<TreeNode*> s;
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* a, TreeNode* b) {
        BinarySearch(r, a,true);
        while(!s.empty()){
            if(BinarySearch(s.top(), b,false))
                return s.top();
            else s.pop();
        }
    }
    bool BinarySearch(TreeNode* r, TreeNode* x,bool mem) {
        if(r==nullptr)
            return false;
        if(mem)
            s.push(r);
        if (r->val == x->val)
            return true;
        if (r->val > x->val)
            return BinarySearch(r->left, x,mem);
        else
            return BinarySearch(r->right, x,mem);
    }
};
