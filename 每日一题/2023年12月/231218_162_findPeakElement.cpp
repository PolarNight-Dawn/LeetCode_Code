#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-18, 下午3:44.
//

class Solution {
public:
    // int findPeakElement(vector<int>& nums) {
    //     if (nums.size() == 1) return 0;
    //
    //     function<int(int, int)> Dichotomy = [&](int start, int end) -> int {
    //         int mid = start + (end - start) / 2;
    //
    //         if ((mid == 0 ||nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
    //             return mid;
    //
    //         if (mid > 0 && nums[mid - 1] > nums[mid])
    //             return Dichotomy(start, mid - 1);
    //         else
    //             return Dichotomy(mid + 1, end);
    //     };
    //     return Dichotomy(0, nums.size() - 1);
    // }

    //! \优化代码
    int findPeakElement(vector<int>& nums) {
        int left = -1, right = nums.size() - 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid;
        }
        return right;
    }
};

int main231218162() {
    vector<int> nums = {1, 2};

    Solution sol;
    cout << sol.findPeakElement(nums);

    return 0;
}