#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int calc(int a, int b, char opr) {
        switch (opr) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default:
                return a / b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for (auto c : tokens) {
            if (!isdigit(c[c.length() - 1])) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(calc(a, b, c[0]));

            }
            else
                s.push(stoi(c));

        }
        return s.top();
    }
};

