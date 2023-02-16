//https://leetcode.com/problems/backspace-string-compare/
#include<string>
#include<stack>
using namespace std;
class Solution {
    public:
    bool backspaceCompare(string s, string t) {
        int i = 0, j = 0, m = s.length(), n = t.length();
        stack<char>s1, s2;
        while (i < m || j < n) {
            if (i < m) {
                if (s[i] != '#') {
                    s1.push(s[i]);
                }
                else {
                    if (!s1.empty()) {
                        s1.pop();
                    }
                }

                i++;

            }
            if (j < n) {
                if (t[j] != '#') {
                    s2.push(t[j]);
                }
                else {
                    if (!s2.empty()) {
                        s2.pop();
                    }
                }

                j++;

            }

        }
        while (!s1.empty() || !s2.empty()) {
            if (s1.size() != s2.size() || s1.top() != s2.top()) {
                return false;

            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};