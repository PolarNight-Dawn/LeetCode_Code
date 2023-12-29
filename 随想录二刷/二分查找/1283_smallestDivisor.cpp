#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-19, 下午7:45.
//

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 0, right = *max_element(nums.begin(), nums.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = 0;
            for (auto &num : nums) {
                sum += (num - 1) / mid + 1;
            }
            if (sum <= threshold) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main1283() {
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;

    Solution sol;
    cout << sol.smallestDivisor(nums, threshold);

    return 0;
}