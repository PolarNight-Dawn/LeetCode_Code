#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-30, 下午3:40.
//

class Solution {
public:
    // 经典的完全背包问题 物品可以多次添加  target 已知为 amount
    int change(int amount, std::vector<int>& coins) {
        std::vector<int> dp(amount + 1, 0);

        dp[0] = 1;
        for (auto &vec : coins) {
            for (int j = vec; j <= amount; j++) {
                dp[j] += dp[j - vec];
            }
        }

        return dp[amount];
    }
};

int main() {
    int amount = 5;
    std::vector<int> coins = {1, 2, 5};

    Solution sol;
    std::cout << sol.change(amount, coins);

    return 0;
}