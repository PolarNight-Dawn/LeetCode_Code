#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//
// Created by polarnight on 23-4-14.
//
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int digit = 0;

        while (x != 0) {
            if (rev < INT32_MIN / 10 || rev > INT32_MAX / 10) {
                return 0;
            }
            digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }

        return rev;
    }
};

int main07() {
    int x = 1534236469;

    Solution sol;
    cout << sol.reverse(x);

    return 0;
}
