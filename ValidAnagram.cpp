#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int freq[1000];
    bool isAnagram(string s, string t) {
        int n=s.length();
        if(n!=t.length())
            return false;
        for(int i=0;i<n;++i){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(int i='a';i<='z';++i)
            if(freq[i]<0)
                return false;
        return true;
    }
};