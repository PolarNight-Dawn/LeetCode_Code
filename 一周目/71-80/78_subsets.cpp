#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-14.
//

class Solution {
public:
    void backTracing(std::vector<int> &nums, std::vector<std::vector<int>> &res,
                     std::vector<int> &tmp, int start, int depth) {
        if (depth == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (std::find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
            tmp.push_back(nums[i]);
            backTracing(nums, res, tmp, i, depth - 1);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        int len = nums.size();
        std::vector<int> tmp;
        std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>());

        for (int i = 1; i <= len; i++) {
            backTracing(nums, res, tmp, 0, i);
        }

        return res;
    }
};


int main78() {
    std::vector<int> nums = {3, 2, 4, 1};
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