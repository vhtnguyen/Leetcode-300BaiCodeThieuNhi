//https://leetcode.com/problems/linked-list-cycle-ii/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}

};
class Solution {
    public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                slow = head;
                ListNode* ps = slow, * pf = fast;
                while (slow != fast) {
                    ps = slow->next, pf = fast->next;
                    slow = slow->next->next;
                    fast = fast->next->next;
                }
                if (ps == pf) {
                    return ps;
                }
                return slow;
            }
        }
        return nullptr;
    }
};



/*
(a+b)/1=(a+K(b+c)+b)/2 => 2 * (a + b) = a + K*(b + c) + b

2 * (a + b) = a + K*(b + c) + b, where K is an integer, K is the number of full rounds runner has to run in circle before he meets walker. When circle is really small, K can be bigger than 1.

Based on this, we can simplify it to

a + b = K*(b + c)
c=(a+b-Kb)/k

a = (K - 1) * b + K*c

If we claim N = (K - 1), so N is also an integer, then

a = N * b + (N + 1)* c;

or

a = c + N (b + c)

*/

