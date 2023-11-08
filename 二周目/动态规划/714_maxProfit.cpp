#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-8, 下午1:59.
//

class Solution {
public:
    int maxProfit714(std::vector<int>& prices, int fee) {
        int len = prices.size();
        std::vector<std::vector<int>> dp(len, std::vector<int>(2, 0));

        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return std::max(dp[len - 1][0], dp[len - 1][1]);
    }
};

int main() {
    int fee = 2;
    std::vector<int> prices = {1, 3, 2, 8, 4, 9};

    Solution sol;
    std::cout << sol.maxProfit714(prices, fee);

    return 0;
}