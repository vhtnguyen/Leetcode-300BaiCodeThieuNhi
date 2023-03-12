//https://leetcode.com/problems/merge-k-sorted-lists/


#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};
class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = 0, r = lists.size() - 1;
        return mergeSort(lists, l, r);
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (r - l < 1) {
            return nullptr;
        }
        if (r - l == 1) {
            return merge(lists[l], lists[r]);
        }
        int mid = l + (r - l) / 2;
        return merge(mergeSort(lists, l, mid), mergeSort(lists, mid + 1, r));
    }


    // Function to merge two linked lists 
    ListNode* merge(ListNode* first, ListNode* second) {
        // If first linked list is empty 
        if (!first) {
            return second;
        }
        // If second linked list is empty 
        if (!second) {
            return first;
        }
        // Pick the smaller value 
        if (first->val < second->val) {
            first->next = merge(first->next, second);
            return first;
        }
        else {
            second->next = merge(first, second->next);
            return second;
        }
    }


};

/*

The time complexity of the mergeKLists method can be analyzed by looking at the time complexity of its helper function, mergeSort, which is the main algorithm that is used to merge the lists.

The mergeSort function is a recursive algorithm that splits the input lists into halves until they are reduced to individual elements. Then it merges them back together in a sorted manner.

The time complexity of mergeSort function can be expressed as follows:

T(n) = 2T(n/2) + O(kn)

where n is the total number of elements in all the lists, k is the number of lists, and O(kn) is the time complexity of merging two lists.

The recursive formula above is a result of the divide-and-conquer algorithm used in mergeSort. Each recursive call divides the input into two halves, and the merge operation takes O(kn) time to merge the two halves. Therefore, the total time complexity of mergeSort is O(kn log n).

The mergeKLists method simply calls the mergeSort function and returns the sorted linked list. Therefore, its time complexity is also O(kn log n).

In summary, the time complexity of the mergeKLists method is O(kn log n), where n is the total number of elements in all the lists, and k is the number of lists.

*/