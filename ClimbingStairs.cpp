#include<bits/stdc++.h>
using namespace std;

//analysis:
// f_1 = 1,f_2=2
// f_i= n_(i-1) + f_(i-2)
//same concept with fibonacci number


//dp top-down solution

// class Solution {
//     int f[46]{ 0};
//     public:
//     Solution() {
//         f[1] = 1;
//         f[2]= 2;
//     }
//     int climbStairs(int n) {
//         if(n<3)
//             return f[n];
//         if (!f[n - 1])
//             f[n - 1] = climbStairs(n - 1);
//         f[n] = f[n - 1] + f[n - 2];
//         return f[n];
//     }
// };

//non-recursive solution bottom-up

// class Solution {
//     int f[46];
//     public:
//     Solution() {
//         f[1] = 1;
//         f[2]= 2;
//     }
//     int climbStairs(int n) {
//         if (n >= 3){
//              for (int i = 3;i <= n;++i)
//                  f[i] = f[i - 1] + f[i - 2];
//          }
//         return f[n];
//     }

// };

//more optimize solution

class Solution {
    public:
    int climbStairs(int n) {
        if (n <3)
            return n;
        int sum = 0, first = 1, second = 2;
        for (int i = 3;i <= n;++i) {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }

};