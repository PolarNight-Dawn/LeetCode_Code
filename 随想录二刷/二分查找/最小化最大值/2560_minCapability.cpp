#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-6, 下午4:07.
//

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        function<bool(int)> Check = [&](int mid) -> bool {
            int f0 = 0, f1 = 0;
            for (auto &num: nums) {
                if (num > mid) {
                    f0 = f1;
                } else {
                    int tmp = f1;
                    f1 = max(f1, f0 + 1);
                    f0 = tmp;
                }
            }
            return f1 >= k;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1,4,5};
    int k = 1;

    Solution sol;
    cout << sol.minCapability(nums, k);

    return 0;
}