#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-8, 下午3:04.
//

class Solution {
public:
    int findLengthOfLCIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main674() {
    std::vector<int> nums = {1, 3, 5, 4, 7};

    Solution sol;
    std::cout << sol.findLengthOfLCIS(nums);

    return 0;
}