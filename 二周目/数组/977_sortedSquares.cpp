#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

//
// Created by polarnight on 23-9-5.
//

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int> &nums) {
        std::vector<int> res;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int left_pow_num = pow(nums[left], 2);
            int right_pow_num = pow(nums[right], 2);
            if (left_pow_num <= right_pow_num) {
                res.push_back(right_pow_num);
                right--;
            } else {
                res.push_back(left_pow_num);
                left++;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main977() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};

    Solution sol;
    std::vector<int> res = sol.sortedSquares(nums);

    for (auto &vec: res) {
        std::cout << vec << " ";
    }

    return 0;
}