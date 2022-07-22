#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int freq[26];
    bool canConstruct(string r, string m) {
        int ml = m.length(), rl = r.length();
        for (int i = 0;i < ml;++i) {
            freq[m[i] - 'a']++;
        }
        for (int i = 0;i < rl;++i) {
            freq[r[i] - 'a']--;
            if (freq[r[i] - 'a'] < 0)
                return false;
        }
        return true;
    }

    
};