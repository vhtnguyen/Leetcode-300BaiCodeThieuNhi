#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        char x, y;
        bool hasBS;
        while (i > -1 || j > -1) {
            i > -1 ? x = s[i] : x = ' ';
            j > -1 ? y = t[j] : y = ' ';
            hasBS = false;
            if (x == '#') {
                int cnt = 0;
                while (s[i] == '#') {
                    cnt--;
                    i--;
                }
                i += cnt;
                hasBS = true;
            }
            if (y == '#') {
                int cnt = 0;
                while (t[j] == '#') {
                    cnt--;
                    j--;
                }
                j += cnt;
                hasBS = true;
            }
            if (hasBS)
                continue;
            if (x == y) {
                i--;
                j--;
            }
            else
                return false;

        }
        return i == j;
    }
};