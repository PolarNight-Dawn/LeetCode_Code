#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-14.
//

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        int len = nums.size();
        std::vector<std::vector<int>> res;

        for (int mask = 0; mask < (1 << len); mask++) {
            std::vector<int> subset;
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(subset);
        }

        return res;
    }
};


int main78() {
    std::vector<int> nums = {3,2,4,1};
    std::vector<std::vector<int>> res;

    Solution sol;
    res = sol.subsets(nums);

    for (auto &tmp: res) {
        for (auto &vec: tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}