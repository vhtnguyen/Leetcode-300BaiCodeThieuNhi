#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    public:
    stack<int> in,out;
    bool onTop; //when the front value of queue on top of stack using in otherwise using out
    MyQueue() {
        onTop = false;
    }
    void push(int x) {
        if (onTop) {
            while (!out.empty()) {
                in.push(out.top());
                out.pop();
            }
            onTop = false;
        }
        in.push(x);
    }
    int pop() {
        int front = peek();
        out.pop();
        return front;
    }
    
    int peek() {
        if (empty())
            return -1;
        if (!onTop) {
            while (!in.empty()) {
                out.push(in.top());
               in.pop();
            }
            onTop = true;
        }
        return out.top();
    }
    
    bool empty() {
        return in.size() + out.size() == 0;
    }
};
