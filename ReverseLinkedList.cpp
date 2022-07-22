#include<bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//iterator solution
  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head&&head->next) {
            ListNode* current = head;
            head = head->next;
            current->next = pre;
            pre = current;
        }
        if (head) 
            head->next = pre;
        return head;
    }
  };

  
//recursive solution

  
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next)
//             return head;
//         ListNode* newHead = reverseList(head->next);
//         head->next->next=head;
//         head->next=nullptr;
//         return newHead;
//     }
// };

  
//using stack solution (slow)

  
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<ListNode*>s;
//         if (head && head->next) {
//             while (head->next) {
//                 s.push(head);
//                 head = head->next;
//             }
//             ListNode* current = head;
//             while (!s.empty()) {
//                 current->next = s.top();
//                 current = current->next;
//                 s.pop();
//             }
//             current->next = nullptr;
//         }
//         return head;

//     }
// };