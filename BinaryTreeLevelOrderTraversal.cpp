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


// class Solution {
//     public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>res;
//         if (!root)
//             return res;
//         queue<pair<TreeNode*, int>> q;
//         q.emplace(root, 0);
//         int maxCurrentLvl = -1;
//         while (!q.empty()) {
//             auto [node, level] = q.front();
//             q.pop();
//             if (level > maxCurrentLvl) {
//                 maxCurrentLvl = level;
//                 res.push_back(vector<int>());
//             }
//             res[level].push_back(node->val);
//             if (node->left)
//                 q.emplace(node->left, level + 1);
//             if (node->right)
//                 q.emplace(node->right, level + 1);
//         }
//         return res;
//     }
// };

class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            res.push_back(vector<int>());
            int n = q.size();
            for (int i = 0;i < n;++i) {
                auto node = q.front();
                res[level].push_back(node->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return res;
    }
};