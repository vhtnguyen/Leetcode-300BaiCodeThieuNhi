#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// https://www.youtube.com/watch?v=XUx3iJVPdxA

/*
Given an array of integers and a number k, find the subarray of size k has maximum sum.
return the index of the first element of subarray. If there are more than one answer valid, return the first one.
*/

int slidingWindow1() {
    int n, k;
    cin >> n >> k;
    int a[1001];
    for (int i = 0;i < n;++i) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0;i < k;++i) {
        sum += a[i];
    }
    long long maxSum = sum;
    int idx = 0;
    for (int i = k;i < n;++i) {
        sum += a[i - 1] + a[i];
        if (sum > maxSum) {
            maxSum = sum;
            idx = i - k + 1;
        }
    }
    return idx;
}

/*
cho một array a[] số nguyên dương size n, số nguyên k. Swap các phần tử sao cho các phần tử <=k đứng cạnh nhau với số lần swap là nhỏ nhất.
- Đếm số phần tử <=k : gọi số pt là d
- sliding window size d sao cho số phần từ <=k là lớn nhất : gọi là cnt
- số lần swap nhỏ nhất cần thực hiện là d - cnt
*/

int slidingWindow2() {
    int n, k, d = 0, cnt = 0;
    cin >> n >> k;
    int a[1001];
    for (int i = 0;i < n;++i) {
        cin >> a[i];
        if (a[i] <= k) {
            d++;
        }
    }
    for (int i = 0;i < d;++i) {
        if (a[i] <= k) {
            cnt++;
        }
    }
    int ans = cnt;
    for (int i = k;i < n;++i) {
        if (a[i - 1] <= k) {
            cnt--;
        }
        if (a[i] <= k) {
            cnt++;
        }
        if (cnt > ans) {
            ans = cnt;
        }
    }
    ans = d - ans;
    return ans;
}

/*
Sửa đèn
Có n bóng đèn liên tiếp trong đó b chiếc bị hỏng, cần sửa tạm thời vài bóng sao cho có ít nhất k bóng liên tiếp sáng và số bóng cần sửa là nhỏ nhất
test case:
10 6 5
2 10 1 5 9
output: 1
*/

int slidingWindow3() {
    int n, k, b;
    cin >> n >> k >> b;
    int a[1001];
    for (int i = 0;i < b;++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int cnt = 0;
    for (int i = 0;i < k;++i) {
        cnt += a[i];
    }
    int ans = cnt;
    for (int i = k;i < n;++i) {
        cnt += a[i] - a[i - 1];
        ans = min(ans, cnt);
    }
    return ans;
}

/*
Cửa sổ trùng nhau 1
Cho mảng n pt và số nguyên dương k. Kiểm tra xem có tồn tại cửa sổ cỡ k nào chứa 2 phần tử giống nhau không.
*/

bool slidingWindow4() {
    int n, k;
    int a[1001];
    unordered_set <int>window;
    for (int i = 0;i < n;++i) {
        cin >> a[i];
    }
    for (int i = 0;i < n;++i) {
        if (i >= k) {
            window.erase(a[i - k]); // o(1) in unordered_set
        }
        if (window.count(a[i])) { // o(1) in unordered_set
            return true;
        }
        window.insert(a[i]); // o(1) in unordered_set
    }
    return false;
}

/*
Cửa sổ trùng nhau 2
Cho mảng n pt,số nguyên dương k,t. Kiểm tra xem có tồn tại cửa sổ cỡ k nào chứa 2 phần tử giống nhau không có độ lệch <=t không
abs(a[i]-a[j])<=t
or
a[j]-t<=a[i]<=a[j]+t
*/

bool slidingWindow5() {
    int n, k, t;
    cin >> n >> k >> t;
    int a[1001];
    set <int>window;
    for (int i = 0;i < n;++i) {
        cin >> a[i];
    }
    for (int j = 0;j < n;++j) {
        if (j >= k) {
            window.erase(window.find(a[j - k]));
        }
        auto it = window.lower_bound(a[j] - t);
        if (it != window.end() && (*it <= (a[j] + t))) {
            return true;
        }
        window.insert(a[j]);
    }
    return false;
}