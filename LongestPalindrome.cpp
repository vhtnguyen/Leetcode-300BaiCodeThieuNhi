#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//     map<char,int> freq;
//     int longestPalindrome(string s) {
//         int res = 0;
//         for (auto c : s) 
//             freq[c]++;
//         for(auto f:freq)
//              res += (f.second/2)*2;  
//         if (res < s.length())
//             res++;
//         return res;
//     }
// };

class Solution {
    public:
    int freq[128];
    int longestPalindrome(string s) {
        int res = 0;
        for (auto c : s) 
            freq[c]++;
        for (int i = 'A';i <= 'Z';++i) 
             res += (freq[i]/2)*2;  
         for (int i = 'a';i <= 'z';++i) 
             res += (freq[i]/2)*2;    
        return res+(res<s.length());
    }
};

