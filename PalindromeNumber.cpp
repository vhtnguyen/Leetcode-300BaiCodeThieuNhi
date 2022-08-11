// class Solution {
//     public:
//     bool isPalindrome(int x) {
//         if (x < 0)
//             return false;
//         long long y = 0, z = x; // using integer may causes overflow
//         while (z) {
//             y *= 10;
//             y += z % 10;
//             z /= 10;
//         }
//         return x == y;
//     }
// };