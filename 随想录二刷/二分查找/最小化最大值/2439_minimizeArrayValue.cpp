#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-3, 下午5:53.
//

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());

        function<bool(int)> Check = [&](int mid) -> bool {
            long long have = 0;
            for (auto &n : nums) {
                if (n <= mid) {
                    have += mid - n;
                } else {
                    if (have < n - mid) return 0;
                    else have -= (n - mid);
                }
            }
            return 1;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};

int main2439() {
    vector<int> nums = {13,13,20,0,8,9,9};

    Solution sol;
    cout << sol.minimizeArrayValue(nums);

    return 0;
}