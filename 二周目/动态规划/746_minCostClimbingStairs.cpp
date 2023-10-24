#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-24, 下午3:44.
//

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp(cost.size() + 1, 0);
        dp[0] = dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};

int main746() {
    std::vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    Solution sol;
    std::cout << sol.minCostClimbingStairs(cost);

    return 0;
}