#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-9.
//

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 2;
        if (n == 1 || n ==  2) return dp[n - 1];

        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return  dp[n - 1];
    }
};

int main() {
    int n = 1;

    Solution sol;
    std::cout << sol.climbStairs(n);

    return 0;
}