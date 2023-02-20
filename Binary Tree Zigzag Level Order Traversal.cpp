// /https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include<vector>
#include<deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) {
            return ans;
        }
        deque<TreeNode*>q;
        int lr = true; // travel left to right
        q.push_front(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int>thisLvl;
            for (int j = 0;j < n;++j) {
                TreeNode* curr = nullptr;
                if (lr) {
                    curr = q.front();
                    q.pop_front();
                    if (curr->left)q.push_back(curr->left);
                    if (curr->right) q.push_back(curr->right);
                }
                else {
                    curr = q.back();
                    q.pop_back();
                    if (curr->right)q.push_front(curr->right);
                    if (curr->left) q.push_front(curr->left);
                }
                thisLvl.push_back(curr->val);
            }
            lr = !lr;
            ans.push_back(thisLvl);
        }
        return ans;
    }
};

// class Solution {
//     public:
//     TreeNode* makeNode(TreeNode* x) {
//         TreeNode* newnode = new TreeNode(x->val, x->left, x->right);
//         return newnode;
//     }
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         if (!root) {
//             return ans;
//         }
//         deque<TreeNode*>q;
//         int lr = true;
//         q.push_front(makeNode(root));
//         while (!q.empty()) {
//             int n = q.size();
//             vector<int>thisLvl;
//             for (int j = 0;j < n;++j) {
//                 TreeNode* curr = nullptr;
//                 if (lr) {
//                     curr = makeNode(q.front());
//                     q.pop_front();
//                     if (curr->left)q.push_back(makeNode(curr->left));
//                     if (curr->right) q.push_back(makeNode(curr->right));
//                 }
//                 else {
//                     curr = q.back();
//                     q.pop_back();
//                     if (curr->right)q.push_front(makeNode(curr->right));
//                     if (curr->left) q.push_front(makeNode(curr->left));
//                 }
//                 thisLvl.push_back(curr->val);
//                 delete curr;
//             }
//             lr = !lr;
//             ans.push_back(thisLvl);
//         }
//         return ans;
//     }
// };