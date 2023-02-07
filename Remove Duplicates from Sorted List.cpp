//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            if (nxt && (nxt->val == cur->val)) {
                cur->next = nxt->next;
            }
            else {
                cur = cur->next;
            }

        }
        return head;

    }
};