#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
// solution approached stack 

class Solution {
    public:
    bool isPalindrome(ListNode* head) {
        ListNode* f = head, * s = head;
        stack<ListNode*>tmp;
        while (f && f->next) {
            tmp.push(s);
            s = s->next;
            f = f->next->next;
        }
        if (f)
            s = s->next;
        while (s) {
            if (s->val != tmp.top()->val)
                return false;
            s = s->next;
            tmp.pop();
        }
        return true;
    }
};

