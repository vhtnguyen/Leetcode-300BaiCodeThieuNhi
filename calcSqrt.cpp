#include<iostream>
using namespace std;
//Secant method
class Solution {
    public:
    double mySqrt(int x, double epsilon) {
        double a = binarySearchLast(0, x, x);
        double b = binarySearchFirst(0, x, x);
        double res;
        if (a == b) {
            return a;
        }
        while (true) {
            double fa = myFunc(a, x);
            double fb = myFunc(b, x);
            res = a - ((b - a) / (fb - fa)) * fa;
            double fx = myFunc(res, x);
            if (abs(fx) < epsilon) {
                return res;
            }
            if (fx * fa < 0) {
                b = res;
            }
            else {
                a = res;
            }
        }


    }
    double myFunc(double x, double y) {
        return (x * x) - y;
    }
    double abs(double x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }
    double binarySearchLast(int left, int right, int x) {
        if (left <= right) {
            double mid = left + (right - left) / 2;
            if ((mid == right || (myFunc(mid + 1, x) > 0)) && (myFunc(mid, x) <= 0)) {
                return mid;
            }
            else if (myFunc(mid, x) < 0) {
                return binarySearchLast(mid + 1, right, x);
            }
            return binarySearchLast(left, mid - 1, x);
        }
        return -1;
    }
    double binarySearchFirst(int left, int right, int x) {
        if (left <= right) {
            double mid = left + (right - left) / 2;
            if ((mid == left || (((mid - 1) * (mid - 1) - x) < 0)) && (mid * mid - x) >= 0) {
                return mid;
            }
            else if (((mid * mid) - x) < 0) {
                return binarySearchFirst(mid + 1, right, x);
            }
            return binarySearchFirst(left, mid - 1, x);
        }
        return -1;
    }
};

int main() {
    Solution a;
    cout << a.mySqrt(2, 0.00001);
}