//https://leetcode.com/problems/n-ary-tree-postorder-traversal/
#include<vector>
using namespace std;

// Definition for a Node.
class Node {
    public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
    public:
    vector<int>res;
    vector<int> postorder(Node* root) {
        if (!root) {
            return res;
        }
        for (auto child : root->children) {
            postorder(child);
        }
        res.push_back(root->val);
        return res;

    }
};