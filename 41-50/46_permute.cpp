#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-22.
//

class Solution {
public:
    void backTracing(std::vector<int> &nums, std::vector<int> &temp,
                     std::vector<std::vector<int>> &res, int len) {
        if (temp.size() == len) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < len; i++) {
            if(std::find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
                temp.push_back(nums[i]);
                backTracing(nums, temp, res, len);
                temp.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<int> temp;
        std::vector<std::vector<int>> res;

        backTracing(nums, temp, res, len);

        return res;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> res;

    Solution sol;
    res = sol.permute(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}