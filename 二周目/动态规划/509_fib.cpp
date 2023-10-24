#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-24, 下午3:16.
//

class Solution {
public:
    // 时间复杂度O(n) 空间复杂度O(n)
    // int fib(int n) {
    //     if (n <= 1) return n;
    //     std::vector<int> dp(n + 1, 0);
    //     dp[1] = 1;
    //
    //     for (int i = 2; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //
    //     return dp[n];
    // }

    // 优化代码 时间复杂度O(n) 空间复杂度O(1)
    int fib(int n) {
        if (n <= 1) return n;
        std::vector<int> dp(2, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int tmp = dp[0];
            dp[0] = dp[1];
            dp[1] = dp[1] + tmp;
        }
        return dp[1];
    }
};

int main() {
    int n = 2;

    Solution sol;
    std::cout << sol.fib(n);

    return 0;
}