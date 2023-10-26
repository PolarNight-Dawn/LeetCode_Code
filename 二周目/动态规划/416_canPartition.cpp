#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

//
// Created by polarnight on 23-10-26, 下午2:46.
//

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int max_num = * std::max_element(nums.begin(), nums.end());

        int target = sum / 2;
        if (max_num > target) return false;

        std::vector<std::vector<int>> dp(len, std::vector<int>(target + 1, 0));
        for (int i = 0; i < len; i++) dp[i][0] = true;

        dp[0][nums[0]] = true;
        for (int i = 1; i < len; i++) {
            int num = nums[i];
            for (int j = 1; j < target + 1; j++) {
                if (j > num) dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[len - 1][target];
    }
};

int main() {
    std::vector<int> nums = {1,5,11,5};

    Solution sol;
    std::cout << sol.canPartition(nums);

    return 0;
}