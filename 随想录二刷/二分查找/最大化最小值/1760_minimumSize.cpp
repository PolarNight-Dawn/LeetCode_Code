#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-2, 下午5:01.
//

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        function<bool(int)> Check = [&](int mid) -> bool {
            int ans = 0;
            vector<int> num = nums;
            for (auto &tmp : num) {
                if (tmp % mid == 0) ans += tmp / mid - 1;
                else ans += tmp / mid;
            }
            return ans > maxOperations;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {9};
    int maxOperations = 2;

    Solution sol;
    cout << sol.minimumSize(nums, maxOperations);

    return 0;
}