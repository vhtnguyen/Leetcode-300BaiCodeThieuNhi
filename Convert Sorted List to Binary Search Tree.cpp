//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}

};

//T(1)=1, T(2)=2, T(n)=n/2+2*T(n/2-1) ~ (nlogn)/2 ~ nlogn

// class Solution {
//     public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         if (!head) {
//             return nullptr;
//         }
//         ListNode* l1 = nullptr, * l2 = nullptr;
//         TreeNode* root = helper(head, l1, l2);
//         root->left = sortedListToBST(l1);
//         root->right = sortedListToBST(l2);
//         return root;
//     }

//     TreeNode* helper(ListNode* head, ListNode*& l1, ListNode*& l2) {
//         ListNode* slow = head, * fast = head, * preSlow = nullptr;
//         while (fast && fast->next) {
//             preSlow = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         if (preSlow) {
//             preSlow->next = nullptr;
//         }
//         l2 = slow->next;
//         if (slow != head) {
//             l1 = head;
//         }
//         TreeNode* newNode = new TreeNode(slow->val);
//         return newNode;
//     }
// };


class Solution {
    public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>array;
        while (head) {
            array.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = array.size() - 1;
        return helper(array, l, r);
    }
    TreeNode* helper(vector<int>& array, int l, int r) {
        if (r < l)
            return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(array[m]);
        //TreeNode* root = new TreeNode(nums[m], solve(l, m - 1, nums), solve(m + 1, r, nums));
        root->left = helper(array, l, m - 1);
        root->right = helper(array, m + 1, r);
        return root;
    }
};