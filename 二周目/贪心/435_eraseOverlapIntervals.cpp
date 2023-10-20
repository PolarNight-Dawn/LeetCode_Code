#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-20, 下午10:15.
//

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
            return a[1] < b[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};

int main() {
    std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    Solution sol;
    std::cout << sol.eraseOverlapIntervals(intervals);

    return 0;
}