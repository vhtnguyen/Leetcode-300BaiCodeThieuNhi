#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.length(), m = b.length(), i = 0, carry = 0;
        while (i < n || i < m || carry) {
            int sum = 0;
            i < n ? sum += (a[n - i - 1] - '0') : sum += 0;
            i < m ? sum+= (b[m-i-1] -'0'): sum+= 0;
            sum += carry;
            carry = sum > 1;
            res += char(sum % 2 + '0'); /// don't use res=char()+res it takes O(n) to replicate the res string cause the solution costs O(n^2)
            ++i;
        }
        reverse(res.begin(), res.end()); // this function takes O(n) so total costs O(n)
        return res;
    }
};

