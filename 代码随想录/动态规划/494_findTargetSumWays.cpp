#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//
// Created by polarnight on 23-10-28, 上午2:04.
//

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (target > sum || (sum - target) % 2 == 1) return 0;
        int capacity = (sum - target) / 2;

        std::vector<int> dp(capacity + 1, 0);
        dp[0] = 1;
        for (auto &num : nums) {
            for (int j = capacity; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        return dp[capacity];
    }
};

int main494() {
    int target = 3;
    std::vector<int> nums = {1,1,1,1,1};

    Solution sol;
    std::cout << sol.findTargetSumWays(nums, target);

    return 0;
}