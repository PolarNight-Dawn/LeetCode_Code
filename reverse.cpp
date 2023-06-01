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
        int num = 0;
        int res = 0;
        double virRes = 0.0;
        bool jud = false;
        if (x > 0) {
            num = x;
        } else if (x == 0 | x == -2147483648) {
            return res;
        } else {
            num = abs(x);
            jud = true;
        }

        vector<int> digits;
        while (num > 0) {
            int digit = num % 10;
            digits.insert(digits.begin(), digit);
            num /= 10;
        }

        int len = digits.size();
        if (digits[len - 1] == 0) {
            for (int i = len - 2; i >= 0; i--) {
                double result = pow(10, i);
                virRes += digits[i] * result;
                if (virRes > 2147483647) {
                    return 0;
                }
                res = static_cast<int>(virRes);
            }
        } else {
            for (int i = len - 1; i >= 0; i--) {
                double result = pow(10, i);
                virRes += digits[i] * result;
                if (virRes > 2147483647) {
                    return 0;
                }
                res = static_cast<int>(virRes);
            }
        }

        if (res > 2147483647 | res < -2147483648) {
            return 0;
        } else {
            if (jud) {
                return -res;
            }
            return res;
        }
    }
};

int main07 () {
    int x = 1534236469;

    Solution sol;
    cout << sol.reverse(x);
    
    return 0;
}
