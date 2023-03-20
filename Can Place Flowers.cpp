//https://leetcode.com/problems/can-place-flowers/

#include<vector>
using namespace std;

class Solution {
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i)
        {
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0)
            {
                --n;
                ++i;
            }

        }
        return n <= 0;
    }
};
// 0 0 0 0 1 0

//0 0 0 0 1 0 n =2
//1 0 0 0 0 0 n =3