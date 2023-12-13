#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-2, 下午4:43.
//

class Solution {
public:
    int rob213(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        std::vector<int> dp_1(n, 0), dp_2(n, 0);

        dp_1[0] = nums[0], dp_1[1] = std::max(dp_1[0], nums[1]), dp_2[2] = nums[1];
        for (int i = 2; i < n; i++) dp_1[i] = std::max(dp_1[i - 2] + nums[i], dp_1[i - 1]);
        for (int i = 3; i <= n; i++) dp_2[i] = std::max(dp_2[i - 2] + nums[i], dp_2[i - 1]);
        return std::max(dp_1[n - 1], dp_2[n - 1]);
    }
};

int main213() {
    std::vector<int> nums = {2,1};

    Solution sol;
    std::cout << sol.rob213(nums);

    return 0;
}