//
// Created by polarnight on 24-3-19, 下午3:30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        int left = k, right = k;
        int min_val = nums[k], max_sum = nums[k];

        //! \优化代码
        for (int i = 0; i < n - 1; i++) {
            if (left == 0 || right < n && nums[left - 1] <= nums[right + 1])
                min_val = min(min_val, nums[++right]);
            else
                min_val = min(min_val, nums[--left]);
            max_sum = max(max_sum, min_val * (right - left + 1));
        }

        //! \被优化代码
        /*int i = k - 1, j = k + 1;
        while (i >= 0 && j < n) {
            if (nums[j] >= min_val) {
                right++, j++;
                max_sum = max(max_sum, min_val * (right - left + 1));
                continue;
            }
            if (nums[i] >= min_val) {
                left--, i--;
                max_sum = max(max_sum, min_val * (right - left + 1));
                continue;
            }
            if (nums[i] >= nums[j]) {
                left--;
                min_val = nums[i--];
                max_sum = max(max_sum, min_val * (right - left + 1));
            } else if (nums[i] < nums[j]) {
                right++;
                min_val = nums[j++];
                max_sum = max(max_sum, min_val * (right - left + 1));
            }
        }

        while (i >= 0) {
            if (nums[i] < min_val)
                min_val = nums[i];
            left--, i--;
            max_sum = max(max_sum, min_val * (right - left + 1));
        }

        while (j < n) {
            if (nums[j] < min_val)
                min_val = nums[j];
            right++, j++;
            max_sum = max(max_sum, min_val * (right - left + 1));
        }*/

        return max_sum;
    }
};

int main240319_1793() {
    vector<int> nums = {6569, 9667, 3148, 7698, 1622, 2194, 793, 9041, 1670, 1872};
    int k = 5;

    Solution sol;
    cout << sol.maximumScore(nums, k);

    return 0;
}