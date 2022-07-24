#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 //analys:
 // at any node r the diameter dr = height(r->left)+ height(r->right );
 // the diameter of whole tree is dr_max
 // ideal: find left height and right height and update diameter at whole node

 
 class Solution {

     public:
     int diameterOfBinaryTree(TreeNode* root) {
         int d = 0;
         height(root, d);
         return d;

     }

     int height(TreeNode* r,int&d) {
         if (!r)
             return 0;
         int lh = height(r->left,d);
         int rh = height(r->right,d);
         d = max(d, lh + rh);
         return max(lh, rh) + 1;
     }
 };