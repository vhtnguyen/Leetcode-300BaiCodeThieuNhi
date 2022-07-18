#include<bits/stdc++.h>
using namespace std;
unordered_map<char, char> dict = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for(auto c:s){
           if(dict.find(c)!=dict.end())
               x.push(dict[c]);
            else if(x.empty()||x.top()!=c)
                return false;
            else
                 x.pop();
        }
        return x.empty();
    }
};
