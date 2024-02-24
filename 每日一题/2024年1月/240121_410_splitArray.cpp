#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//
// Created by polarnight on 24-1-21, 下午3:26.
//

class Solution {
public:
    int splitArray(vector<int> &nums, int k) {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(begin(nums), end(nums), 0);

        function<bool(int)> Check = [&](int mid) -> bool {
            int count = 1, tmp = 0;
            for (auto &num : nums) {
                if (tmp + num <= mid) {
                    tmp += num;
                } else {
                    if (count++ == k) return false;
                    tmp = num;
                }
            }
            return true;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main240121410() {
    vector<int> nums = {2,3,1,2,4,3};
    int k = 5;

    Solution sol;
    cout << sol.splitArray(nums, k);

    return 0;
}
