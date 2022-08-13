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

// class Solution {
//     public:
//     bool check(TreeNode* l, TreeNode* r) {
//         if (!l || !r)
//             return l == r;
//         if (l->val != r->val)
//             return false;
//         return check(l->left, r->right) && check(l->right, r->left);
//     }
//     bool isSymmetric(TreeNode* root) {
//         return check(root->left, root->right);
//     }
// };



//DFS based stack solution

// class Solution {
//     public:
//     bool isSymmetric(TreeNode* root) {
//         TreeNode* l = root->left, * r = root->right;
//         stack<TreeNode*>s;
//         s.push(l);
//         s.push(r);
//         while (!s.empty()) {
//             l = s.top();
//             s.pop();
//             r = s.top();
//             s.pop();
//             if (!l && !r)
//                 continue;
//             if (!(l && r) || l->val != r->val)
//                 return false;
//             s.push(l->left);
//             s.push(r->right);
//             s.push(l->right);
//             s.push(r->left);
//         }
//         return true;
//     }
// };

// BFS based queue solution

class Solution {
    public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* l = root->left, * r = root->right;
        queue<TreeNode*>q;
        q.push(l);
        q.push(r);
        while (!q.empty()) {
            l = q.front();
            q.pop();
            r = q.front();
            q.pop();
            if (!l && !r)
                continue;
            if (!(l && r) || l->val != r->val)
                return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};