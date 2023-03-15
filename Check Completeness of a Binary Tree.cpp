//https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
#include<queue>
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
    bool isCompleteTree(TreeNode* root) {
        bool flag = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0;i < n;++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node->left && node->right) {
                    return false;
                }
                if (!flag && (!node->left || !node->right)) {
                    flag = true;
                }
                else if (flag && (node->left || node->right)) {
                    return false;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

            }
        }
        return true;
    }
};