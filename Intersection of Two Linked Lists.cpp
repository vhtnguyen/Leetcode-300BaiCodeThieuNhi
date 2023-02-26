//https://leetcode.com/problems/intersection-of-two-linked-lists/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}

};
// #include<stack>
// using namespace std;
// class Solution {
//     public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         stack<ListNode*>s1, s2;
//         ListNode* h1 = headA, * h2 = headB;
//         while (h1 || h2) {
//             if (h1) {
//                 s1.push(h1);
//                 h1 = h1->next;
//             }
//             if (h2) {
//                 s2.push(h2);
//                 h2 = h2->next;
//             }
//         }
//         ListNode* ans = nullptr;
//         while (!s1.empty() && !s2.empty()) {
//             if (s1.top() == s2.top()) {
//                 ans = s1.top();
//             }
//             s1.pop();
//             s2.pop();
//         }
//         return ans;
//     }

// };

////https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/49785/java-solution-without-knowing-the-difference-in-len/

class Solution {
    public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* h1 = headA, * h2 = headB;
        while (h1 != h2) {
            h1 == nullptr ? h1 = headB : h1 = h1->next;
            h2 == nullptr ? h2 = headA : h2 = h2->next;
        }
        return h1;
    }
};