#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& n, int t) {
        vector<int>::iterator i = lower_bound(n.begin(), n.end(), t);
        if(i!=n.end()&&*i==t)
            return i - n.begin();
        return -1;
    }
};
