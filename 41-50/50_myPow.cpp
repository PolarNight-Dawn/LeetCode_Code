#include <iostream>

//
// Created by polarnight on 23-7-26.
//

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) return 0.0;
        long tmp = n;
        if (tmp < 0) {
            x = 1 / x;
            tmp = -tmp;
        }

        double res = 1.0;
        while (tmp) {
            if ((tmp & 1) == 1) res *= x;
            x *= x;
            tmp >>= 1;
        }
        return res;
    }
};

int main50() {
    double x = 2.0;
    int n = 10;

    Solution sol;
    std::cout << sol.myPow(x, n);

    return 0;
}