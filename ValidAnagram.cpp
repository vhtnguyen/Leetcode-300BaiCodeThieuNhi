#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fre[1000];
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        for(auto c:s)
            fre[c]++;
        for(auto c:t){
            fre[c]--;
            if(fre[c]<0)
                return false;
        }
        return true;
    }
};