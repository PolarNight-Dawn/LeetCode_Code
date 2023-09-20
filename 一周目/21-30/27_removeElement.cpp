#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-6-24.
//

class Solution {
public:
    // int removeElement(std::vector<int>& nums, int val) {
    //     nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
    //     int k = nums.size();
    //     return k;
    // }

    // 二周目重刷 双指针法
    int removeElement(std::vector<int>& nums, int val) {
        int right = nums.size() - 1;
        for (int left = 0; left <= right; left++) {
            if (nums[left] == val) {
                // 这一段代码实现了两个功能 1.交换有效和无效的元素 2.移动了无效元素的右边界right
                int tmp = nums[right];
                nums[right--] = nums[left];
                nums[left--] = tmp;
            }
        }

        // 这里为什么不返回 left + 1，或者说 left + 1 为什么是错的
        // 因为 left 的本意就不是确定有效元素的左边界，它仅是作为一个遍历的位次
        return right + 1;
    }
};

int main() {
    std::vector<int> nums = {};
    int val = 2;

    Solution sol;
    int k = sol.removeElement(nums,val);

    int len = k - 1;
    while (len >= 0) {
        std::cout << nums[len--];
    }
    std::cout << std::endl << k;

     return 0;
}