//
// Created by polarnight on 24-3-8, 下午4:17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        int m = target / 2;
        if (n <= m) return (int) ((long long) (1 + n) * n / 2 % mod);
        return (int) (((long long) (1 + m) * m / 2 +
                       ((long long) target + target + (n - m) - 1) * (n - m) / 2) % mod);
    }
};

int main2403082834() {
    int n = 16, target = 6;

    Solution sol;
    cout << sol.minimumPossibleSum(n, target);

    return 0;
}