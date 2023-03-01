//https://leetcode.com/problems/sort-an-array/

#include<vector>
using namespace std;


class Solution {
    public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void swap(int& a, int& b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    void quickSort(vector<int>& arr, int left, int right)
    {
        int pivot = arr[left + (right - left) / 2]; // pivot
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }

        }
        if (left < j)

            quickSort(arr, left, j);

        if (right > i)

            quickSort(arr, i, right);
    }


};