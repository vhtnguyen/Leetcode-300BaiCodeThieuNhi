//https://leetcode.com/problems/koko-eating-bananas/

//https://math.stackexchange.com/questions/4361332/is-there-a-function-that-is-the-envelope-of-the-sum-of-ceilings-of-reciprocal-fu

#include<bits/stdc++.h>
using namespace std;
/*
Input: piles = [3,6,7,11], h = 8, = [3,6,7,11]
Output: 4
*/
// class Solution {
//     public:
//     int eat(vector<int>& piles, int k) {
//         int sum = 0;
//         for (int& pile : piles) {
//             sum += ceil(pile * 1.0 / k);
//         }
//         return sum;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         sort(piles.begin(), piles.end());

//         int l = 1, r = piles[piles.size() - 1];

//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             int canEat = eat(piles, mid);
//             if ((mid == l || eat(piles, mid - 1) > h) && canEat <= h) {
//                 return mid;
//             }
//             if (canEat > h) {
//                 l = mid + 1;
//             }
//             else {

//                 r = mid - 1;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
    public:
    int eat(vector<int>& piles, int k) {
        int sum = 0;
        for (int& pile : piles) {
            sum += (pile + k - 1) / k;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int maxP = piles[0];
        for (int& pile : piles) {
            sum += pile;
            if (pile > maxP) {
                maxP = pile;
            }
        }
        int l = (sum + h - 1) / h, r = maxP;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int canEat = eat(piles, mid);
            if (canEat <= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }

        }
        return l;
    }
};
