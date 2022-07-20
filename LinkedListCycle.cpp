#include<bits/stdc++.h>
using namespace std;



  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  //tricky solution using the range limited of node's value
  
//   class Solution {
//       const int maxVal = 100000 + 1;
//       public:
//     bool hasCycle(ListNode *head) {
//         ListNode *curr = head;
//         while (curr) {
//             if (curr->val > maxVal)
//                 return true;
//             else {
//                 curr->val = maxVal;
//                 curr = curr->next;
//             }
//         }
//         return false;
//     }
//   };

  //Floyd’s cycle finding algorithm/Hare-Tortoise algorithm
  //https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/

  class Solution {
      public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode* sp = head, * fp = sp->next;
        while (sp &&fp&&fp->next) {
            if (sp==fp)
                return true;
            else {
                sp = sp->next;
                fp=fp->next->next;
            }
        }
        return false;
    }
  };