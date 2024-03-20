//
// Created by polarnight on 24-3-20, 下午8:01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;

    long long FastPow(long long x, long long pow) {
        long long res = 1;
        for (; pow > 0; pow >>= 1) {
            if (pow & 1) {
                res = x * res % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        if (p == 1) return 1;

        long long x = FastPow(2, p) - 1;
        long long y = (long long) 1 << (p - 1);
        int res = FastPow(x - 1, y - 1) * x % mod;

        return res;
    }
};

int main240320_1969() {
    int p = 2;

    Solution sol;
    cout << sol.minNonZeroProduct(p);

    return 0;
}