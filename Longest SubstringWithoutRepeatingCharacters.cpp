#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int n = s.length();
        int bgn = 0;
        int res = 0;
        //abcbda

        for (int i = 0;i < n;++i) {
            dict[s[i]]++;
            if (dict[s[i]] > 1) {
                int tmp = i - bgn;
                while (bgn < i - 1 && s[bgn] != s[i]) {
                    dict[s[bgn]]--;
                    bgn++;
                }
                if (tmp > res)
                    res = tmp;
                dict[s[bgn]]--;
                bgn++;
            }

        }
        bgn = n - bgn;
        if (bgn > res)
            res = bgn;
        return res;
    }
};

