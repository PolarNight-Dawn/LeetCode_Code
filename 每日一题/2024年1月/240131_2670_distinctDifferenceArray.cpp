#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
//
// Created by polarnight on 24-1-31, 下午4:18.
//

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        vector<int> prefix(n, 0), res(n, 0);

        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
            prefix[i] = set.size();
        }

        set.clear();
        for (int i = n - 1; i >= 0; i--) {
            res[i] = prefix[i] - set.size();
            set.insert(nums[i]);
        }
        return res;
    }
};

int main2401312670() {
    vector<int> nums = {13,13,13};

    Solution sol;
    auto vec = sol.distinctDifferenceArray(nums);

    for (auto &tmp : vec) {
        cout << tmp << " ";
    }
    cout << endl;

    return 0;
}