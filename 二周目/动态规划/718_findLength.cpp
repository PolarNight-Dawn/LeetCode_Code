#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-8, 下午6:32.
//

class Solution {
public:
    int findLength(std::vector<int> &nums1, std::vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        int ans = 0;
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                dp[i][j] = nums1[i] == nums2[j] ? dp[i + 1][j + 1] + 1 : 0;
                ans = std::max(dp[i][j], ans);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 2, 1};
    std::vector<int> nums2 = {3, 2, 1, 4, 7};

    Solution sol;
    std::cout << sol.findLength(nums1, nums2);

    return 0;
}