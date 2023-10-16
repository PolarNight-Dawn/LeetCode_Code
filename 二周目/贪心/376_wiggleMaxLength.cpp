#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-15, 下午8:13.
//

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        int down = 1, up = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) up = down + 1;
            else if (nums[i] < nums[i - 1]) down = up + 1;
        }
        return nums.size() == 0 ? 0 : std::max(down, up);
    }
};

int main() {
    std::vector<int> nums = {1,1,7,4,9,2,5};

    Solution sol;
    std::cout << sol.wiggleMaxLength(nums);

    return 0;
}