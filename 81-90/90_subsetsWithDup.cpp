#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-21.
//

class Solution {
public:
    void backTracing(std::vector<int>& nums, std::vector<std::vector<int>>& res,
                     std::vector<int>& tmp, std::vector<int>& used, int start, int depth) {
        if (depth == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == 0) continue;
            used[i] = 1;
            tmp.push_back(nums[i]);
            backTracing(nums, res, tmp ,used, i + 1, depth - 1);
            tmp.pop_back();
            used[i] = 0;
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<int> tmp;
        std::vector<int> used(len, 0);
        std::vector<std::vector<int>> res;

        res.push_back(std::vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= len; i++) {
            backTracing(nums, res, tmp, used, 0, i);
        }

        return res;
    }
};

int main90() {
    std::vector<int> nums = {1, 2, 2};
    std::vector<std::vector<int>> res;

    Solution sol;
    res = sol.subsetsWithDup(nums);

    for (auto &tmp : res) {
        for (auto &vec :tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}