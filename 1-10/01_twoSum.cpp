#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-4-16.
//

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main01() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    sol.twoSum(nums, target);

    return 0;
}