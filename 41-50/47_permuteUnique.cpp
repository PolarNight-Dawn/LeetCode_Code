#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-23.
//

class Solution {
public:
    void backTracing(std::vector<int> &nums, std::vector<int> &temp, std::vector<int> &used,
                     std::vector<std::vector<int>> &res, int len) {
        if (temp.size() == len) {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) continue;
            if (!used[i]) {
                used[i] = 1;
                temp.push_back(nums[i]);
                backTracing(nums, temp, used, res, len);
                temp.pop_back();
                used[i] = 0;
            }
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        int len = nums.size();
        std::vector<int> temp;
        std::vector<int> used(nums.size(), 0);
        std::vector<std::vector<int>> res;

        std::sort(nums.begin(), nums.end());
        backTracing(nums, temp, used, res, len);

        return res;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 2};
    std::vector<std::vector<int>> res;

    Solution sol;
    res = sol.permuteUnique(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}