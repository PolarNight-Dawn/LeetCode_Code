#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-9.
//

class Solution {
public:
    // int climbStairs(int n) {
    //     std::vector<int> dp(n + 1, 0);
    //     dp[0] = 1, dp[1] = 2;
    //     if (n == 1 || n ==  2) return dp[n - 1];
    //
    //     for (int i = 2; i < n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //
    //     return  dp[n - 1];
    // }

    // 二周目 动态规划 完全背包问题
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= 2; j++)
                if (i - j >= 0)
                    dp[i] += dp[i - j];
        return dp[n];
    }
};

int main() {
    int n = 1;

    Solution sol;
    std::cout << sol.climbStairs(n);

    return 0;
}