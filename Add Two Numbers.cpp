//https://leetcode.com/problems/add-two-numbers/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};
class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, * ptr2 = l2;
        int carry = 0;
        while (ptr1 || ptr2 || carry) {
            int sum = 0;
            sum += carry;
            sum += ptr1->val;
            if (ptr2) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            carry = sum > 9;
            ptr1->val = sum % 10;
            if (!ptr1->next && (carry || ptr2)) {
                ptr1->next = new ListNode();
            }
            ptr1 = ptr1->next;
        }
        return l1;
    }
};