#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-9.
//

class Solution {
public:
    int search(std::vector<int> &nums, int left, int right, int target) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) return mid;
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;

        if (nums[mid] < nums[right]) {
            if (nums[mid] < target && target < nums[right]) {
                return search(nums, mid + 1, right, target);
            } else {
                return search(nums, left, mid, target);
            }
        }

        if (nums[mid] > nums[left]) {
            if (nums[left] < target && target < nums[mid]) {
                return search(nums, left, mid - 1, target);
            } else {
                return search(nums, mid, right, target);
            }
        }

        return -1;
    }

    int search(std::vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int cnt = search(nums, left, right, target);

        return cnt;
    }
};

int main() {
    std::vector<int> nums = {1, 3};

    Solution sol;
    std::cout << sol.search(nums, 2);

    return 0;
}