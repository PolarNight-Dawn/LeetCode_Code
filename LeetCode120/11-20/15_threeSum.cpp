#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-4-24.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int triplet = nums[i] + nums[left] + nums[right];
                if (triplet > 0) right--;
                if (triplet < 0) left++;
                if (triplet == 0) {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};


int main15() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);

    for (auto vec: res) {
        for (int num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}