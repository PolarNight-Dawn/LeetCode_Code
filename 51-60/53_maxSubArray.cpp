#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-29.
//

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] >= 0) {
                dp[i] = nums[i] + dp[i - 1];
            } else {
                dp[i] = nums[i];
            }
        }

        int res = INT32_MIN;
        for (auto &vec : dp) {
            res = std::max(vec, res);
        }
        return res;
    }
};

int  main53() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution sol;
    std::cout << sol.maxSubArray(nums);

    return 0;
}