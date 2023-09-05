#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-5.
//

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int slow_index = 0;

        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            if (0 != nums[fast_index]) {
                nums[slow_index++] = nums[fast_index];
            }
        }

        for (int i = slow_index; i < nums.size(); i++) nums[i] = 0;
    }
};

int main283() {
    std::vector<int> nums = {0,1,0,3,12};

    Solution sol;
    sol.moveZeroes(nums);

    for (auto &vec : nums) {
        std::cout << vec << " ";
    }

    return 0;
}