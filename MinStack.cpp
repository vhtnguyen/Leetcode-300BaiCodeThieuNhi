#include<bits/stdc++.h>
using namespace std;

class MinStack {
    public:
    stack<int>s;
    priority_queue<int, vector<int>, greater<int>>q;
    MinStack() {
    }

    void push(int val) {
        s.push(val);
        q.push(val);
    }
    void pop() {
        int x = s.top(), cnt = 0;
        s.pop();

        while (q.top() != x) {
            s.push(q.top());
            q.pop();
            cnt++;
        }
        q.pop();
        while (cnt--) {
            q.push(s.top());
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return q.top();
    }
};