#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

//
// Created by polarnight on 23-10-11, 下午2:36.
//

class Solution {
public:
    void BackTracing491(std::vector<std::vector<int>> &res, std::vector<int> &tmp,
                     std::vector<int> &nums, int start) {
        if (nums.size() <= 1) return;
        if (tmp.size() >= 2) res.push_back(tmp);

        std::unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            if (!tmp.empty() && nums[i] < tmp.back()) continue;
            if (used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            tmp.push_back(nums[i]);
            BackTracing491(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;

        BackTracing491(res, tmp, nums, 0);

        return res;
    }
};

int main491() {
    std::vector<int> nums = {4, 6, 7, 7};

    Solution sol;
    std::vector<std::vector<int>> res = sol.findSubsequences(nums);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}