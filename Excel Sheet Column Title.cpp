//https://leetcode.com/problems/excel-sheet-column-title/

#include<string>
using namespace std;

//1002 = ALN = A*(26*26)+L*26+n=

class Solution {
    public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber) {
            columnNumber--;
            char ch = 'A' + (columnNumber % 26);
            res.push_back(ch);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};