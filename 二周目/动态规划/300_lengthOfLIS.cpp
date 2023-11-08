#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-8, 下午2:09.
//

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main300() {
    std::vector<int> nums = {10,9,2,5,3,7,101,18};

    Solution sol;
    std::cout << sol.lengthOfLIS(nums);

    return 0;
}