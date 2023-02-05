#include<iostream>
using namespace std;
//https://leetcode.com/problems/length-of-last-word/
class Solution {
    public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1, start;
        while (s[end] == ' ') {
            end--;
        }
        start = end;
        while (start > 0 && s[start] != ' ') {
            start--;
        }
        return end - start + (s[start] != ' ');
    }
};