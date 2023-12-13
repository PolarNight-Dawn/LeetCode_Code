#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-17.
//

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<int> temp(len + 1, 0);

        for (int i = 0; i < len; i++) {
            if (nums[i] >= 1 && nums[i] <= len + 1) {
                temp[nums[i] - 1] = nums[i];
            }
        }

        for (int i = 0; i < len + 1; i++) {
            if (temp[i] != i + 1) return i + 1;
        }

        return 1;
    }
};

int main41() {
    std::vector<int> nums = {1};

    Solution sol;
    std::cout << sol.firstMissingPositive(nums);

    return 0;
}