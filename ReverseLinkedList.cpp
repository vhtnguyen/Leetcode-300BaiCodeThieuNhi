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
//         else
//             head = reverseSubList(head, nullptr);
//          return head;

//     }
//     ListNode* reverseSubList(ListNode* current, ListNode* pre) {
//         ListNode* newHead = current;
//         if (current&&current->next)
//             newHead = reverseSubList(current->next, current);
//         current->next = pre;
//         return newHead;
//     }
// };

  