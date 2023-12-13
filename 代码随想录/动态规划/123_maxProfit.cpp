#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-6, 下午2:58.
//

class Solution {
public:
    int maxProfit123(std::vector<int>& prices) {
        int len = prices.size();
        std::vector<std::vector<int>> dp(len, std::vector(5, 0));

        dp[0][1] = -prices[0], dp[0][3] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][1] = std::max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            dp[i][2] = std::max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
            dp[i][3] = std::max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
            dp[i][4] = std::max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
        }
        return dp[len - 1][4];
    }
};

int main123() {
    std::vector<int> prices = {3,3,5,0,0,3,1,4};

    Solution sol;
    std::cout << sol.maxProfit123(prices);

    return 0;
}