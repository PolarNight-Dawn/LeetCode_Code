#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-1, 下午4:31.
//

class Solution {
public:
    // int rob(std::vector<int> &nums) {
    //     if (nums.size() == 1) return nums[0];
    //     std::vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0], dp[1] = std::max(dp[0], nums[1]);
    //
    //     for (int i = 2; i < nums.size(); i++) {
    //         dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    //     }
    //     return dp.back();
    // }

    // 空间优化 滚动数组 dp[0]为前一个房间的值，dp[1]为此房间的最大值
    int rob(std::vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        std::vector<int> dp(2, 0);
        dp[0] = nums[0], dp[1] = std::max(dp[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int tmp = dp[1];
            dp[1] = std::max(dp[0] + nums[i], dp[1]);
            dp[0] = tmp;
        }
        return dp[1];
    }
};

int main198() {
    std::vector<int> nums = {1, 2, 3, 1};

    Solution sol;
    std::cout << sol.rob(nums);

    return 0;
}