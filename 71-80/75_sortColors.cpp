#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-12.
//

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] > nums[j]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
    }
};

int main() {
    std::vector<int> nums = {2,0,2,1,1,0};

    Solution sol;
    sol.sortColors(nums);

    for (auto &vec: nums) {
        std::cout << vec << " ";
    }

    return 0;
}