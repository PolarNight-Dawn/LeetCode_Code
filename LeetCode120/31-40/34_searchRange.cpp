#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-10.
//

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }

        if (nums[right] != target) return {-1, -1};
        int Right = right;
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        if (nums[right] != target) return {-1, -1};
        return {right, Right};
    }
};

int main34() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    std::vector<int> res;

    Solution sol;
    res = sol.searchRange(nums, 8);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}