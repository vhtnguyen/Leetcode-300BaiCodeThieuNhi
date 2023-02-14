//https://leetcode.com/problems/happy-number/
#include<unordered_map>
using namespace std;
// class Solution {
//     public:
//     unordered_map<int, bool> check;
//     bool isHappy(int n) {
//         int sumSquares = 0;
//         while (true) {
//             sumSquares = 0;
//             while (n > 0) {
//                 sumSquares += (n % 10) * (n % 10);
//                 n /= 10;
//             }
//             if (sumSquares == 1) {
//                 return true;
//             }
//             else if (check.find(sumSquares) != check.end()) {
//                 return false;
//             }
//             check[sumSquares] = true;
//             n = sumSquares;
//         }
//     }
// };


//**********Floyd Cycle Detection

class Solution {
    public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while (slow != 1 && fast != 1 && slow != fast);
        return slow == 1 || fast == 1;
    }
};
