#include <iostream>
//#include <cmath>

//
// Created by polarnight on 23-6-26.
//

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (std::abs(static_cast<long long >(dividend)) < std::abs(static_cast<long long>(divisor)) || divisor == 0) return 0;

        long cnt = 0;
        int left = dividend, right = divisor;
        if (dividend >= 0 && divisor > 0) {
            while (left >= right) {
                left -= right;
                cnt++;
            }
        }
        if (dividend < 0 && divisor < 0) {
            while (left <= right) {
                left -= right;
                cnt++;
            }
        }
        if (dividend < 0 && divisor > 0) {
            while (left <= -right) {
                left += right;
                cnt++;
            }
            cnt = -cnt;
        }
        if (dividend >= 0 && divisor < 0) {
            while (left >= -right) {
                left += right;
                cnt++;
            }
            cnt = -cnt;
        }

        if (cnt > INT32_MAX) return INT32_MAX;
        if (cnt < INT32_MIN) return INT32_MIN;
        int res = cnt;
        return res;
    }
};

int main() {
    int dividend = -2147483648;
    int divisor = -1;

    Solution sol;
    std::cout << sol.divide(dividend, divisor);

    return 0;
}