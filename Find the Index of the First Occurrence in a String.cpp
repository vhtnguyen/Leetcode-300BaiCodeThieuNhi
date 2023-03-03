//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include<string>
#include<iostream>
using namespace std;
class Solution {
    public:
    int strStr(string haystack, string needle) {
        int k = needle.length();
        int i = 0;
        if (haystack.length() < k) {
            return -1;
        }
        while (i + k - 1 < haystack.length() && (haystack[i] != needle[0] || haystack[i + k - 1] != needle[k - 1])) {
            i++;
        }
        while (i + k - 1 < haystack.length()) {
            if (haystack[i] == needle[0] && haystack[i + k - 1] == needle[k - 1]) {
                bool flag = true;
                int nearest = i + 1;
                for (int m = 1;m < (k + 1) / 2;) {

                    if (haystack[i + m] == needle[m] && haystack[i + k - 1 - m] == needle[k - 1 - m]) {
                        if (nearest == i + k && haystack[i + m] == needle[0]) {
                            nearest = i + m;
                        }
                        m++;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
                else if (nearest != i + k) {
                    i = nearest;
                }
            }
            while (i + k - 1 < haystack.length() && (haystack[i] != needle[0] || haystack[i + k - 1] != needle[k - 1])) {
                i++;
            }

        }

        return -1;

    }
};

int main() {
    cout << "hello world!";
    string a = "mississippi";
    string b = "sipp";
    Solution x;
    x.strStr(a, b);

    return 0;
}