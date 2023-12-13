#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-4.
//

class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] == target) return mid;
        }

        return -1;
    }
};

int main704() {
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    Solution sol;
    std::cout << sol.search(nums, target);

    return 0;
}