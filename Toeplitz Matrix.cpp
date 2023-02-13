//https://leetcode.com/problems/toeplitz-matrix/
#include<vector>
using namespace std;
class Solution {
    public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = m - 2;i >= 1;--i) {
            int j = i, k = 0;
            int val = matrix[j++][k++];
            while (j < m && k < n) {
                if (matrix[j++][k++] != val) {
                    return false;
                }
            }
        }
        for (int i = n - 2;i >= 0;--i) {
            int j = 0, k = i;
            int val = matrix[j++][k++];
            while (j < m && k < n) {
                if (matrix[j++][k++] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};