#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        
        while(l<r){
            if(!isalpha(s[l])&&!isdigit(s[l]))
                l++;
            else if(!isalpha(s[r])&&!isdigit(s[r]))
                r--;
            else{
                if(isupper(s[l]))
                    s[l] += 32;
                if(isupper(s[r]))
                    s[r] += 32;
                if(s[l]==s[r]){
                    l++;
                    r--;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
