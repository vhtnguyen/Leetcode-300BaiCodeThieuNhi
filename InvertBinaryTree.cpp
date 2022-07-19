class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
        TreeNode *l = nullptr, *r = nullptr;
        l = invertTree(root->left);
        r = invertTree(root->right);
        root->left = r;
        root->right = l;
        }
        return root;
    }
};