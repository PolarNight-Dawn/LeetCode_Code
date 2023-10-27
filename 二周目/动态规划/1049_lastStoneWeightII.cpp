#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//
// Created by polarnight on 23-10-26, 下午3:34.
//

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        std::vector<int> dp(target + 1, 0);

        for (auto &stone : stones) {
            for (int j = target; j >= stone; j--) {
                dp[j] = std::max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - 2 * dp[target];
    }
};

int main1049() {
    std::vector<int> stones = {2,7,4,1,8,1};

    Solution sol;
    std::cout << sol.lastStoneWeightII(stones);

    return 0;
}