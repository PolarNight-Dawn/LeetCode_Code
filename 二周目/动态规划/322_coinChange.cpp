#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-31, 下午3:03.
//

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<long long> dp(amount + 1, INT32_MAX);

        dp[0] = 0;
        for (auto &coin : coins)
            for (int j = coin; j <= amount; j++)
                    dp[j] = std::min(dp[j], dp[j - coin] + 1);
        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution sol;
    std::cout << sol.coinChange(coins, amount);

    return 0;
}