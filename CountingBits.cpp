#include<bits/stdc++.h>
using namespace std;

//shift bits and dp solution

//idea: find a smaller related number
//let the number of bit "1" of i =a_i
//n>>1 = n/2 -> a_n= a_(n/2) + value of lowest bit (rightmost bit)
// to check if bit b  is "0" or "1" : b&1
//e.g: x=6= 110 -> x>>1 = 11 and lowest bit of x is 0
//a_x = a_(x>>1) + (x&1)= a_3+0=2
//for short: 
//the dp alg : a_0=0 ; a_i = a_(i/2)+ i&1

// class Solution {
//     public:
//     vector<int> countBits(int n) {
//         vector<int>ans;
//         ans.push_back(0);
//         for (int i = 1;i <= n;++i) {
//             ans.push_back(ans[i >> 1] + (i & 1));
//         }
//         return ans;
//     }
// };


//an other solution with same idea: find a smaller related number
//i & (i - 1) =j -> to remove the rightmost non-zero bit and return a new value j (j<i)
//the number bits "1" of j : a_j = a_i - 1 because we removed one bit "1" of i by "&"
// so the result a_i = a_j +1

class Solution {
    public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        for (int i = 1;i <= n;++i) {
            ans.push_back(ans[i & (i - 1)] + 1);
        }
        return ans;
    }
};