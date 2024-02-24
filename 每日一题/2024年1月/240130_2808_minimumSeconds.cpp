#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 24-1-30, 下午6:19.
//

class Solution {
public:
    int minimumSeconds(vector<int> &nums) {
        unordered_map<int, vector<int>> map;
        int n = nums.size(), res = n;
        for (int i = 0; i < n; ++i)
            map[nums[i]].push_back(i);

        for (auto &pos: map) {
            int mx = pos.second[0] + n - pos.second.back();
            for (int i = 1; i < pos.second.size(); ++i)
                mx = max(mx, pos.second[i] - pos.second[i - 1]);
            res = min(res, mx / 2);
        }
        return res;
    }
};

int main240130() {
    vector<int> nums = {1, 2, 1, 2};

    Solution sol;
    cout << sol.minimumSeconds(nums);

    return 0;
}