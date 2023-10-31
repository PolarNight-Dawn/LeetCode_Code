#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//
// Created by polarnight on 23-10-31, 下午7:40.
//

class Solution {
public:
    // std::vector<int> ConstructArray(int n) {
    //     std::vector<int> ans;
    //     int val = 0;
    //     for (int i = 1; i <= INT32_MAX; i++) {
    //         val = pow(i, 2);
    //         if (val <= n) ans.push_back(val);
    //         else break;
    //     }
    //     return ans;
    // }
    //
    // int numSquares(int n) {
    //     std::vector<long long> dp(n + 1, INT32_MAX);
    //     std::vector<int> nums = ConstructArray(n);
    //
    //     dp[0] = 0;
    //     for (auto &num : nums)
    //         for (int j = num; j <= n; j++)
    //             dp[j] = std::min(dp[j] ,dp[j - num] + 1);
    //     return dp[n];
    // }

    // 简化代码
    int numSquares(int n) {
        std::vector<long long> dp(n + 1, INT32_MAX);

        dp[0] = 0;
        for (int i = 1; i * i<= n; i++)
            for (int j = i * i; j <= n; j++)
                dp[j] = std::min(dp[j], dp[j - i * i] + 1);
        return dp[n];
    }
};

int main() {
    int n = 12;

    Solution sol;
    std::cout << sol.numSquares(n);

    return 0;
}