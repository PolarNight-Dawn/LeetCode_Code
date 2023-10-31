#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-30, 下午3:58.
//

class Solution {
public:
    int combinationSum4(std::vector<int> &nums, int target) {
        std::vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (auto &num: nums) {
                if (j - num >= 0 && dp[j] < INT32_MAX - dp[j - num]) dp[j] += dp[j - num];
            }
        }

        return dp[target];
    }
};

int main377() {
    std::vector<int> nums = {1, 2, 3};
    int target = 4;

    Solution sol;
    std::cout << sol.combinationSum4(nums, target);

    return 0;
}