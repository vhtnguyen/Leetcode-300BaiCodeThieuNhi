#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findTheLongestBalancedSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;
        int i = 0;
        while (i < s.length()) {
            auto finder = s.find("01", i);
            if (finder == std::string::npos) {
                break;
            }
            int balance = 1;
            int k = 1;
            i = finder;
            while (i + 1 + k < s.length() && i - k >= 0 && s[i + 1 + k] == '1' && s[i - k] == '0') {
                k++;
                balance++;
            }
            i = i + k;
            ans = max(ans, balance * 2);
        }



        return ans;

    }
};

int main() {
    string s = "0010";
    // cout << s.find("01", 1);
    Solution a;
    cout << a.findTheLongestBalancedSubstring(s);
}