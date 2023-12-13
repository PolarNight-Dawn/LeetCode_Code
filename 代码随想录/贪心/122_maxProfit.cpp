#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-17, 下午2:27.
//

class Solution {
public:
    // dp 时间复杂度O(n) 空间复杂度O(n)
    // int maxProfit(std::vector<int>& prices) {
    //     std::vector<std::vector<int>> dp(prices.size(), std::vector(2, 0));
    //
    //     for (int i = 0; i < prices.size(); i++) {
    //         for (int j = 0; j < 2; j++) {
    //             if (i == 0) {
    //                 if (j == 0) dp[i][j] = 0;
    //                 if (j == 1) dp[i][1] -= prices[0];
    //             }
    //             if (i > 0 && j == 0) dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j + 1] + prices[i]);
    //             if (i > 0 && j == 1) dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
    //         }
    //     }
    //
    //     return std::max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    // }

    // 贪心 时间复杂度O(n) 空间复杂度O(1)
    int maxProfit122(std::vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            sum += std::max(prices[i] - prices[i - 1], 0);
        }
        return sum;
    }
};

int main122() {
    std::vector<int> price = {1,2,3,4,5};

    Solution sol;
    std::cout << sol.maxProfit122(price);

    return 0;
}