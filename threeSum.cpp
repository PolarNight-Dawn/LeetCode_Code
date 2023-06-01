#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;
//
// Created by polarnight on 23-4-24.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++, right--;
                } else if (nums[left] + nums[right] < target) {
                    left++;
                } else {
                    right--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};


int main15() {
    vector<int> nums = {0, 0, 0};

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