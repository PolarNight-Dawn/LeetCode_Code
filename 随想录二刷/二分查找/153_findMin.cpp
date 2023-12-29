#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-18, 下午5:10.
//

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) left = mid + 1;
            else right = mid - 1;
        }
        return nums[left];
    }
};

int main152() {
    vector<int> nums = {3,1,2};

    Solution sol;
    cout << sol.findMin(nums);

    return 0;
}