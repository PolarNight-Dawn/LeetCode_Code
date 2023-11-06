#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-6, 下午2:39.
//

class Solution {
public:
    int maxProfit121(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector(2, 0));

        dp[0][0] = -7, dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = std::max(-prices[i], dp[i - 1][0]);
            dp[i][1] = std::max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};

int main() {
    std::vector<int> prices = {7,1,5,3,6,4};

    Solution sol;
    std::cout << sol.maxProfit121(prices);

    return 0;
}