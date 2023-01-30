class Solution {
    public:
    int res[38];
    Solution() {
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
    }
    int tribonacci(int n) {
        if (n >= 3) {

            for (int i = 3;i < n;++i) {
                res[i] = res[i - 3] + res[i - 2] + res[i - 1];
            }
        }
        return res[n];
    }
};