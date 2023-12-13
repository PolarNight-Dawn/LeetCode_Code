#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-6, 下午5:21.
//

class Solution {
public:
    int maxProfit309(std::vector<int>& prices) {
        int len = prices.size();
        std::vector<std::vector<int>> dp(len, std::vector<int>(3, 0));

        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1]);
        }
        return std::max(dp[len - 1][1], dp[len - 1][2]);
    }
};

int main309() {
    std::vector<int> prices = {1,2,3,0,2};

    Solution sol;
    std:: cout << sol.maxProfit309(prices);

    return 0;
}