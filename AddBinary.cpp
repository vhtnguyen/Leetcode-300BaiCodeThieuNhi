//https://leetcode.com/problems/add-binary/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.length(), m = b.length(), i = 0, carry = 0;
        while (i < n || i < m || carry) {
            int sum = 0;
            i < n ? sum += (a[n - i - 1] - '0') : sum += 0;
            i < m ? sum += (b[m - i - 1] - '0') : sum += 0;
            sum += carry;
            carry = sum > 1;
            res.push_back(char(sum % 2 + '0')); /// don't use res=char()+res it takes O(n) to replicate the res string cause the solution costs O(n^2)
            ++i;
        }
        reverse(res.begin(), res.end()); // this function takes O(n) so total costs O(n)
        return res;
    }
};

// class Solution {
//     public:
//     string addBinary(string a, string b) {
//         int mem = 0;
//         int i, j;
//         string res;
//         i = a.length() - 1;
//         j = b.length() - 1;
//         while (i >= 0 && j >= 0) {
//             int diff = (a[i--] - '0') + (b[j--] - '0') + mem;
//             char ch = diff % 2 + '0';
//             mem = diff > 1;
//             res.push_back(ch);
//         }

//         while (i >= 0) {
//             int diff = mem + (a[i--] - '0');
//             char ch = diff % 2 + '0';
//             mem = diff > 1;
//             res.push_back(ch);
//         }
//         while (j >= 0) {
//             int diff = mem + (b[j--] - '0');
//             char ch = diff % 2 + '0';
//             mem = diff > 1;
//             res.push_back(ch);
//         }
//         if (mem) {
//             res.push_back('1');
//         }
//         reverse(res.begin(), res.end());
//         return res;

//     }
// };