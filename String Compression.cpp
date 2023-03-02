//https://leetcode.com/problems/string-compression/

#include<vector>
#include<algorithm>
using namespace std;



class Solution {
    public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) {
            return 1;
        }
        int i = 0, j = 0;
        //["a","a","b","b","c","c","c"]
        while (j < chars.size()) {
            int k = 0, m = 0;
            chars[i] = chars[j];
            while (j + k < chars.size() && chars[j + k] == chars[j]) {
                ++k;
            }
            j += k;
            if (k > 1) {
                while (k) {
                    chars[++i] = '0' + (k % 10);
                    k /= 10;
                    m++;
                }
                reverse(chars.begin() + i - m + 1, chars.begin() + i + 1);
            }

            i++;
        }
        return i + 1;
    }
};


