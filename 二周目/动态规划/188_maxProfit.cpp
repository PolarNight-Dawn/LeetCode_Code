#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-6, 下午3:44.
//

class Solution {
public:
    int maxProfit188(int k, std::vector<int>& prices) {
        int len = prices.size();
        std::vector<std::vector<int>> dp(len, std::vector<int>(2 * k + 1, 0));

        for (int i = 1; i < 2 * k + 1; i += 2) dp[0][i] -= prices[0];
        for (int i = 1; i < len; i++) {
            for (int j = 1; j < 2 * k + 1; j += 2) dp[i][j] = std::max(dp[i - 1][j - 1] - prices[i], dp[i - 1][j]);
            for (int j = 2; j < 2 * k + 1; j += 2) dp[i][j] = std::max(dp[i - 1][j - 1] + prices[i], dp[i - 1][j]);
        }
        return dp[len - 1][2 * k];
    }
};

int main188() {
    std::vector<int> prices = {2,4,1};
    int k = 2;

    Solution sol;
    std::cout << sol.maxProfit188(k, prices);

    return 0;
}