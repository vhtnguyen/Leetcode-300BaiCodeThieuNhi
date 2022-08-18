#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    struct Node_char {
        char element;
        Node_char* next;
    };
    struct Stack_Operator {
        Node_char* top;
        int size;
        void init() {
            top = nullptr;
            size = 0;
        }
        void push(char element) {
            Node_char* newnode = new Node_char{ element, top };
            if (!newnode)
                return;
            top = newnode;
            size++;
        }
        void pop() {
            if (top == nullptr)
                return;
            Node_char* pDel = top;
            top = top->next;
            delete pDel;
            size--;
        }
    };
    struct Node_double {
        double element;
        Node_double* next;
    };
    struct Stack_double {
        Node_double* top;
        int size;
        void init() {
            top = nullptr;
            size = 0;
        }
        void push(double element) {
            Node_double* newnode = new Node_double{ element, top };
            if (!newnode)
                return;
            top = newnode;
            size++;
        }
        void pop() {
            if (top == nullptr)
                return;
            Node_double* pDel = top;
            top = top->next;
            delete pDel;
            size--;
        }
    };
    int calculate(string s) {
        Stack_Operator sto; //stack operator
        Stack_double stdb;  //stack double
        sto.init();
        stdb.init();
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            bool flag = false; //check if a new element pushed into stack double
            if (s[i] == ' ')
                continue;
            if (isdigit(s[i])) {
                string oprd = ""; //operand
                while (isdigit(s[i]) || s[i] == '.') {
                    oprd += s[i++];
                }
                stdb.push(strtod(oprd.c_str(), nullptr));
                i--;
                flag = true;
            }
            else if (s[i] != '(' && s[i] != ')') {
                if (s[i] == '-' && (i == 0 || !isdigit(s[i - 1])))
                    stdb.push(0);
                sto.push(s[i]);
            }
            if (s[i] == ')' || i == n - 1) {
                double op2 = stdb.top->element;
                stdb.pop();
                double op1 = stdb.top->element;
                stdb.pop();
                char opr = sto.top->element;
                sto.pop();
                switch (opr) {
                    case '+':
                        stdb.push(op1 + op2);
                        break;
                    default:
                        stdb.push(op1 - op2);
                        break;
                }
                flag = true;
            }
            if (flag) {
                if (sto.size > 0 && (sto.top->element == '*' || sto.top->element == '/')) {
                    double op2 = stdb.top->element;
                    stdb.pop();
                    double op1 = stdb.top->element;
                    stdb.pop();
                    char opr = sto.top->element;
                    sto.pop();
                    switch (opr) {
                        case '/': //asume input always valid
                            stdb.push(op1 / op2);
                            break;
                        default:
                            stdb.push(op1 * op2);
                            break;
                    }
                }
            }
        }
        return stdb.top->element;

    }
};